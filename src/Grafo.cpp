    #include "../include/Grafo.h"
    #include <fstream>
    #include <iostream>
    #include <iomanip>
    using namespace std;

    bool Grafo::eh_direcionado() {
        return this->direcionado;
    }
    bool Grafo::verticePonderado() {
        return this->verticePeso;
    }
    bool Grafo::arestaPonderada() {
        return this->arestaPeso;
    }
    int Grafo::getOrdem()
    {
        return this->ordem;
    }

    void Grafo::setOrdem(int val) {
        this->ordem = val;
    }

    void Grafo::setDirecionado(bool val) {
        this->direcionado = val;
    }

    void Grafo::setVerticePonderado(bool val) {
        this->verticePeso = val;
    }

    void Grafo::setArestaPonderada(bool val) {
        this->arestaPeso = val;
    }
            
    int Grafo::getGrau(){
        NodeVertex* no = getVertice(0);
        int maior = no->getGrau();
        for(int i = 1; i<getOrdem(); i+=1)
        {
            no = getVertice(i);
            if(no != nullptr && no->getGrau() > maior)
            {
                maior = no->getGrau();
            }
        }
        return maior;
    };
            
    bool Grafo::eh_completo(){
        for(int i = 0; i<getOrdem(); i+=1)
        {
            NodeVertex* no = getVertice(i);
            if(no->getGrau() != getOrdem()-1)
            {
                return false;
            }
        }
        return true;
    }
        
    void Grafo::carregaGrafo(string grafo) {
        ifstream inFile("entradas/" + grafo);
        if(!inFile.is_open())
        {
            // cout<<"Erro ao abrir o arquivo"<<endl;
            throw runtime_error("Erro! Arquivo não existe!");
            // exit(1);

        }

        int numVertices, direcionado, arestaPonderada;
        float verticePonderado;
        if(!(inFile >> numVertices >> direcionado >> verticePonderado >> arestaPonderada)){
            throw runtime_error("Erro! Cabeçalho não inicializado");
        }

        this->setDirecionado(direcionado);
        this->setVerticePonderado(verticePonderado);
        this->setArestaPonderada(arestaPonderada);

        if (verticePonderado) {
            for (int i = 0; i < numVertices; i+=1) {
                float peso;
                if(!(inFile >> peso)){
                    throw runtime_error("Erro! Pesos de vértices não inicializados!");
                }
                insereVertice(peso);

            }
        } 
        else
        {
            for (int i = 0; i < numVertices; i+=1) {
                insereVertice(1);
            }
        }

        int origem, destino;
        while (inFile >> origem >> destino) {
            if (arestaPonderada) {
                float peso;
                if(!(inFile >> peso)){
                    throw runtime_error("Erro! Peso da aresta (" + to_string(origem) + "," + to_string(destino) +") não inicializado");
                }
                if(eh_direcionado())
                {
                    insereAresta(origem, destino, peso);
                }
                else
                {
                    insereAresta(destino, origem, peso);
                }
            }
            else {
                if(eh_direcionado())
                {
                    insereAresta(origem, destino, 1);
                }
                else
                {
                    insereAresta(destino, origem, 1);
                }
            }
        }
        inFile.close();
    }
        
    void Grafo::imprimeGrafo()
    {
        cout<<"grafo.txt"<<endl;
        cout<<endl;
        cout<<"Grau: "<<getGrau()<<endl;
        cout<<"Ordem: "<<getOrdem()<<endl;
        cout<<"Direcionado: "<<imprmeSimNao(eh_direcionado())<<endl;
        cout<<"Vertices ponderados: "<<imprmeSimNao(verticePonderado())<<endl;
        cout<<"Arestas ponderadas: "<<imprmeSimNao(arestaPonderada())<<endl;
        cout<<"Completo: "<<imprmeSimNao(eh_completo())<<endl;
        cout<<"Maior menor distância: "<<retornaMaiorMenorDistancia()<<endl;
    }

    string Grafo::imprmeSimNao(bool valor)
    {
        if(valor)
        {
            return "Sim";
        }
        return "Não";
    }

    float Grafo::maiorMenorDistancia(int ponto1, int ponto2) {
    NodeVertex* noPontoUm = getVertice(ponto1);
    NodeVertex* noPontoDois = getVertice(ponto2);

    if (noPontoUm == nullptr || noPontoDois == nullptr) {
        cout << "Erro: Vértices não encontrados." << endl;
        return -1;
    }
    if(noPontoUm->getGrau() == 0 && noPontoDois->getGrau() == 0)
    {
        return -1;
    }

    //Variável grande que eu usei para simular o infinito
    const float INF = 1e9;
    float* distancias = new float[getOrdem()]();
    bool* visitados = new bool[getOrdem()]();


    for (int i = 0; i < getOrdem(); i+=1) {
        distancias[i] = INF;
        visitados[i] = false;
    }

    distancias[ponto1] = 0;

    for (int count = 0; count < getOrdem(); count+=1) {
        int u = -1;
        float min_dist = INF;
        
        for (int i = 0; i < getOrdem(); i+=1) {
            if (!visitados[i] && distancias[i] < min_dist) {
                min_dist = distancias[i];
                u = i;
            }
        }

        if (u == -1) break;
        visitados[u] = true;

        for (int v = 0; v < getOrdem(); v+=1) {
            if (u == v) continue;
            NodeEdge* aresta = getAresta(u, v);
            if (aresta != nullptr) {
                float peso = aresta->getPeso();
                if (distancias[u] + peso < distancias[v]) {
                    distancias[v] = distancias[u] + peso;
                }
            }
        }
    }

    float valor = distancias[ponto2];
    delete[] distancias;
    delete[] visitados;

    if (valor == INF) {
        return -1;
    } else {
        return valor;
    }

}

string Grafo::retornaMaiorMenorDistancia()
{
    if (arestaPonderada()) {
        for (int i = 0; i < getOrdem(); i+=1) {
            for (int j = 0; j < getOrdem(); j+=1) {
                NodeEdge* aresta = getAresta(i, j);
                if (aresta != nullptr)
                {
                    if(aresta->getPeso() < 0){
                        return "\nNão é permitido o uso de pesos negativos nas arestas";
                    }
                }
            }
        }
    }
    float maior = -1;
    int indexX = -1;
    int indexY = -1;
    for(int i = 0; i<getOrdem(); i+=1)
    {
        for(int j = 0; j<getOrdem(); j+=1)
        {
            if(i != j)
            {
                float valor = maiorMenorDistancia(i,j);
                if(valor > maior)
                {
                    indexX = i;
                    indexY = j;
                    maior = valor; 
                }
            }
        }
    }
    if(maior == -1)
    {
        return "\nNão existe nenhum caminho de nenhum vértice para nenhum vértice";
    }
    else
    {
        return "(" + to_string(indexX+1) + "-" + to_string(indexY+1) + ") " + to_string(maior);
    }
}