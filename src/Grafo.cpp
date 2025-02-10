    #include "../include/Grafo.h"
    #include <fstream>
    #include <iostream>
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
            
    bool Grafo::eh_completo() {
        for(int i = 0; i<getOrdem(); i+=1)
        {
            NodeVertex* no = getVertice(i);
            if(no->getGrau() != getOrdem()-1)
            {
                return false;
            }
        }
        return true;
    };
        
    void Grafo::carregaGrafo(string grafo) {
        string caminhoGrafo = "entradas/" + grafo;
        ifstream inFile(caminhoGrafo);

        int numVertices, direcionado, verticePonderado, arestaPonderada;
        inFile >> numVertices >> direcionado >> verticePonderado >> arestaPonderada;

        this->setDirecionado(direcionado);
        this->setVerticePonderado(verticePonderado);
        this->setArestaPonderada(arestaPonderada);

        if (verticePonderado) {
            for (int i = 0; i < numVertices; i+=1) {
                int peso;
                inFile >> peso;
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
                int peso;
                inFile >> peso;
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
    }

    string Grafo::imprmeSimNao(bool valor)
    {
        if(valor)
        {
            return "Sim";
        }
        return "Não";
    }

    void Grafo::maiorMenorDistancia(int ponto1, int ponto2) {
    ponto1 -= 1;
    ponto2 -= 1;

    if (getVertice(ponto1) == nullptr || getVertice(ponto2) == nullptr) {
        cout << "Erro: Vértices não encontrados." << endl;
        return;
    }

    const float INF = 1e9;
    int n = getOrdem();
    float* distancias = new float[n](); // Inicializa com zeros
    bool* visitados = new bool[n]();    // Inicializa com false
    int ajusteNegativo = 0;

    // Verificação de pesos negativos nas arestas
    if (arestaPonderada()) {
        ajusteNegativo = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                NodeEdge* aresta = getAresta(i, j);
                if (aresta != nullptr && aresta->getPeso() < ajusteNegativo) {
                    ajusteNegativo = aresta->getPeso();
                }
            }
        }
        
        if (ajusteNegativo < 0) {
            ajusteNegativo = abs(ajusteNegativo) + 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        NodeEdge* aresta = getAresta(i, j);
                        if (aresta != nullptr) {
                            aresta->setPeso(aresta->getPeso() + ajusteNegativo);
                        }
                    }
                }
            }
        }
    }

    // Inicialização das distâncias e visitados
    for (int i = 0; i < n; i++) {
        distancias[i] = INF;
        visitados[i] = false;
    }
    distancias[ponto1] = 0;

    // Algoritmo de Dijkstra adaptado
    for (int count = 0; count < n; count++) {
        int u = -1;
        float min_dist = INF;
        
        // Encontra o vértice não visitado com a menor distância
        for (int i = 0; i < n; i++) {
            if (!visitados[i] && distancias[i] < min_dist) {
                min_dist = distancias[i];
                u = i;
            }
        }

        if (u == -1) break;
        visitados[u] = true;

        // Percorre todas as arestas adjacentes a u
        for (int v = 0; v < n; v++) {
            if (u == v) continue;
            NodeEdge* aresta = getAresta(u, v);
            if (aresta != nullptr) {
                float peso = aresta->getPeso();
                if (distancias[u] + peso < distancias[v]) {
                    distancias[v] = distancias[u] + peso;
                }
            }
        }

        // Para grafos não direcionados
        if (!eh_direcionado()) {
            for (int v = 0; v < n; v++) {
                if (u == v) continue;
                NodeEdge* aresta = getAresta(v, u);
                if (aresta != nullptr) {
                    float peso = aresta->getPeso();
                    if (distancias[u] + peso < distancias[v]) {
                        distancias[v] = distancias[u] + peso;
                    }
                }
            }
        }
    }

    // Restaura os pesos originais se necessário
    if (ajusteNegativo != 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                NodeEdge* aresta = getAresta(i, j);
                if (aresta != nullptr) {
                    aresta->setPeso(aresta->getPeso() - ajusteNegativo);
                }
            }
        }
    }

    // Exibe o resultado
    if (distancias[ponto2] == INF) {
        cout << "Não existe caminho entre " << ponto1 + 1 << " e " << ponto2 + 1 << endl;
    } else {
        cout << "A menor distância é " << distancias[ponto2] << endl;
    }

    delete[] distancias;
    delete[] visitados;
}