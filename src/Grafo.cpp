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
        NodeVertex* no = this->getVertice(0);
        int maior = no->getGrau();
        for(int i = 1; i<getOrdem(); i+=1)
        {
            no = this->getVertice(i);
            if(no != nullptr && no->getGrau() > maior)
            {
                maior = no->getGrau();
            }
        }
        return maior;
    };
            
    bool Grafo::eh_completo(){
        for(int i = 0; i<this->getOrdem(); i+=1)
        {
            NodeVertex* no = this->getVertice(i);
            if(no->getGrau() != this->getOrdem()-1)
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
                this->insereVertice(peso);

            }
        } 
        else
        {
            for (int i = 0; i <numVertices; i+=1) {
                this->insereVertice(1);
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
                    this->insereAresta(origem, destino, peso);
                }
                else
                {
                    this->insereAresta(destino, origem, peso);
                }
            }
            else {
                if(eh_direcionado())
                {
                    this->insereAresta(origem, destino, 1);
                }
                else
                {
                    this->insereAresta(destino, origem, 1);
                }
            }
        }
        inFile.close();
    }
        
    void Grafo::imprimeGrafo(string grafo)
    {
        cout<<grafo<<endl;
        cout<<endl;
        cout<<"Grau: "<<this->getGrau()<<endl;
        cout<<"Ordem: "<<this->getOrdem()<<endl;
        cout<<"Direcionado: "<<this->imprmeSimNao(this->eh_direcionado())<<endl;
        cout<<"Vertices ponderados: "<<this->imprmeSimNao(this->verticePonderado())<<endl;
        cout<<"Arestas ponderadas: "<<this->imprmeSimNao(this->arestaPonderada())<<endl;
        cout<<"Completo: "<<this->imprmeSimNao(this->eh_completo())<<endl;
        // cout<<"Maior menor distância: "<<this->retornaMaiorMenorDistancia()<<endl;
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
    NodeVertex* noPontoUm = this->getVertice(ponto1);
    NodeVertex* noPontoDois = this->getVertice(ponto2);

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
    float distancias[this->getOrdem()];
    bool visitados[this->getOrdem()] = {false};


    for (int i = 0; i < this->getOrdem(); i+=1) {
        distancias[i] = INF;
        visitados[i] = false;
    }

    distancias[ponto1] = 0;

    for (int count = 0; count < this->getOrdem(); count+=1) {
        int u = -1;
        float min_dist = INF;
        
        for (int i = 0; i < this->getOrdem(); i+=1) {
            if (!visitados[i] && distancias[i] < min_dist) {
                min_dist = distancias[i];
                u = i;
            }
        }

        if (u == -1) break;
        visitados[u] = true;

        for (int v = 0; v < this->getOrdem(); v+=1) {
            if (u == v) continue;
            NodeEdge* aresta = this->getAresta(u, v);
            if (aresta != nullptr) {
                float peso = aresta->getPeso();
                if (distancias[u] + peso < distancias[v]) {
                    distancias[v] = distancias[u] + peso;
                }
            }
        }
    }

    float valor = distancias[ponto2];

    if (valor == INF) {
        return -1;
    } else {
        return valor;
    }

}

string Grafo::retornaMaiorMenorDistancia()
{
    if (this->arestaPonderada()) {
        for (int i = 0; i < this->getOrdem(); i+=1) {
            for (int j = 0; j < this->getOrdem(); j+=1) {
                NodeEdge* aresta = this->getAresta(i, j);
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
    for(int i = 0; i<this->getOrdem(); i+=1)
    {
        for(int j = 0; j<this->getOrdem(); j+=1)
        {
            if(i != j)
            {
                float valor = this->maiorMenorDistancia(i,j);
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

void Grafo::descoloreGrafo() {
    for (int i = 0; i < this->getOrdem(); i+=1) {
        for (int j = 0; j < this->getOrdem(); j+=1) {
            NodeEdge* aresta = this->getAresta(i, j);
            if (aresta != nullptr) {
                aresta->setCor(-1);
            }
        }
    }
}

int Grafo::coloracaoArestaGuloso() {
    int maxCor = 0;


    for (int i = this->getOrdem() - 1; i >= 0; i-=1) {
        for (int j = this->getOrdem() - 1; j > i; j-=1) {
            NodeEdge* aresta = this->getAresta(i, j);
            if (aresta == nullptr || aresta->getCor() != -1) {
                continue;
            }

            bool* coresUsadas = new bool[this->getOrdem() + 1]();

            for (int k = 0; k < this->getOrdem(); k+=1) {
                NodeEdge* adj1 = this->getAresta(i, k);
                NodeEdge* adj2 = this->getAresta(k, i);
                if (adj1 != nullptr && adj1 != aresta && adj1->getCor() != -1) {
                    coresUsadas[adj1->getCor()] = true;
                }
                if (adj2 != nullptr && adj2 != aresta && adj2->getCor() != -1) {
                    coresUsadas[adj2->getCor()] = true;
                }
            }

            for (int k = 0; k < this->getOrdem(); k+=1) {
                NodeEdge* adj1 = this->getAresta(j, k);
                NodeEdge* adj2 = this->getAresta(k, j);
                if (adj1 != nullptr && adj1 != aresta && adj1->getCor() != -1) {
                    coresUsadas[adj1->getCor()] = true;
                }
                if (adj2 != nullptr && adj2 != aresta && adj2->getCor() != -1) {
                    coresUsadas[adj2->getCor()] = true;
                }
            }

            // Encontra a menor cor disponível
            int corDisponivel = 1;
            while (corDisponivel <= this->getOrdem() && coresUsadas[corDisponivel]) {
                corDisponivel+=1;
            }

            aresta->setCor(corDisponivel);
            if (!this->eh_direcionado()) {
                NodeEdge* arestaInversa = this->getAresta(j, i);
                if (arestaInversa != nullptr) {
                    arestaInversa->setCor(corDisponivel);
                }
            }
            if (corDisponivel > maxCor) {
                maxCor = corDisponivel;
            }
            delete [] coresUsadas;
        }
    }
    descoloreGrafo();
    return maxCor;
}

int Grafo::coloracaoArestaRandomizado() {
    int maxCor = 0;
    int ordem = this->getOrdem();

    // Coletar arestas não coloridas (i, j) onde i < j
    int numArestas = 0;
    for (int i = 0; i < ordem; i++) {
        for (int j = i + 1; j < ordem; j++) {
            NodeEdge* aresta = this->getAresta(i, j);
            if (aresta != nullptr && aresta->getCor() == -1) {
                numArestas++;
            }
        }
    }
    
    srand(nullptr);
    NodeEdge** arestas = new NodeEdge*[numArestas];
    for(int i = numArestas-1; i> 0; i-=1)
    {
        int j = rand() % (i+1);
        arestas[i] = this->getAresta(i,j);
    }

    // Embaralhar as arestas usando Fisher-Yates
    for (int i = numArestas - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Par temp = arestas[i];
        arestas[i] = arestas[j];
        arestas[j] = temp;
    }

    // Colorir cada aresta na ordem embaralhada
    for (int k = 0; k < numArestas; k++) {
        int i = arestas[k].i;
        int j = arestas[k].j;
        NodeEdge* aresta = this->getAresta(i, j);

        bool* coresUsadas = new bool[ordem + 1]();

        // Verificar cores usadas pelos vizinhos de i
        for (int v = 0; v < ordem; v++) {
            NodeEdge* adj = this->getAresta(i, v);
            if (adj && adj != aresta && adj->getCor() != -1) {
                coresUsadas[adj->getCor()] = true;
            }
            adj = this->getAresta(v, i);
            if (adj && adj != aresta && adj->getCor() != -1) {
                coresUsadas[adj->getCor()] = true;
            }
        }

        // Verificar cores usadas pelos vizinhos de j
        for (int v = 0; v < ordem; v++) {
            NodeEdge* adj = this->getAresta(j, v);
            if (adj && adj != aresta && adj->getCor() != -1) {
                coresUsadas[adj->getCor()] = true;
            }
            adj = this->getAresta(v, j);
            if (adj && adj != aresta && adj->getCor() != -1) {
                coresUsadas[adj->getCor()] = true;
            }
        }

        int corDisponivel = 1;
            while (corDisponivel <= this->getOrdem() && coresUsadas[corDisponivel]) {
                corDisponivel+=1;
            }

            aresta->setCor(corDisponivel);
            if (!this->eh_direcionado()) {
                NodeEdge* arestaInversa = this->getAresta(j, i);
                if (arestaInversa != nullptr) {
                    arestaInversa->setCor(corDisponivel);
                }
            }
            if (corDisponivel > maxCor) {
                maxCor = corDisponivel;
            }
            delete [] coresUsadas;
    }

    delete[] arestas;
    descoloreGrafo();
    return maxCor;
}


int Grafo::coloracaoArestaReativo() {
    int maxCor = 0;for (int u = this->getOrdem() - 1; u >= 0; u -= 1) {
    for (int v = this->getOrdem() - 1; v > u; v -= 1) {
        NodeEdge* aresta = this->getAresta(u, v);
        if (aresta == nullptr || aresta->getCor() != -1) {
            continue;
        }

        bool* coresUsadas = new bool[this->getOrdem() + 1]();

        // Verifica cores usadas pelos vértices u e v
        for (int k = 0; k < this->getOrdem(); k += 1) {
            NodeEdge* adj1 = this->getAresta(u, k);
            NodeEdge* adj2 = this->getAresta(k, u);
            if (adj1 != nullptr && adj1 != aresta && adj1->getCor() != -1) {
                coresUsadas[adj1->getCor()] = true;
            }
            if (adj2 != nullptr && adj2 != aresta && adj2->getCor() != -1) {
                coresUsadas[adj2->getCor()] = true;
            }
        }

        for (int k = 0; k < this->getOrdem(); k += 1) {
            NodeEdge* adj1 = this->getAresta(v, k);
            NodeEdge* adj2 = this->getAresta(k, v);
            if (adj1 != nullptr && adj1 != aresta && adj1->getCor() != -1) {
                coresUsadas[adj1->getCor()] = true;
            }
            if (adj2 != nullptr && adj2 != aresta && adj2->getCor() != -1) {
                coresUsadas[adj2->getCor()] = true;
            }
        }
    int ordem = this->getOrdem();
    bool direcionado = this->eh_direcionado();

    // Contar o número total de arestas
    int count = 0;
    if (direcionado) {
        for (int i = 0; i < ordem; i++) {
            for (int j = 0; j < ordem; j++) {
                if (i != j && this->getAresta(i, j) != nullptr) {
                    count++;
                }
            }
        }
    } else {
        for (int i = 0; i < ordem; i++) {
            for (int j = i + 1; j < ordem; j++) {
                if (this->getAresta(i, j) != nullptr) {
                    count++;
                }
            }
        }
    }
    // Arrays para armazenar as arestas
    int* uArray = new int[count];
    int* vArray = new int[count];
    NodeEdge** arestaArray = new NodeEdge*[count];
    int index = 0;
    if (direcionado) {
        for (int i = 0; i < ordem; i++) {
            for (int j = 0; j < ordem; j++) {
                NodeEdge* aresta = this->getAresta(i, j);
                if (aresta != nullptr) {
                    uArray[index] = i;
                    vArray[index] = j;
                    arestaArray[index] = aresta;
                    index++;
                }
            }
        }
    } else {
        for (int i = 0; i < ordem; i++) {
            for (int j = i + 1; j < ordem; j++) {
                NodeEdge* aresta = this->getAresta(i, j);
                if (aresta != nullptr) {
                    uArray[index] = i;
                    vArray[index] = j;
                    arestaArray[index] = aresta;
                    index++;
                }
            }
        }
    }
    // Resetar as cores de todas as arestas
    for (int i = 0; i < count; i++) {
        arestaArray[i]->setCor(-1);
    }
    // Colorir cada aresta
    for (int i = 0; i < count; i++) {
        int u = uArray[i];
        int v = vArray[i];
        NodeEdge* aresta = arestaArray[i];
        bool* coresUsadas = new bool[ordem + 1](); // Inicializado com false
        // Verifica as cores das arestas adjacentes ao vértice u
        for (int k = 0; k < ordem; k++) {
            NodeEdge* adj = this->getAresta(u, k);
            if (adj != nullptr && (direcionado || k != v) && adj != aresta && adj->getCor() != -1) {
                coresUsadas[adj->getCor()] = true;
            }
            if (!direcionado) {
                adj = this->getAresta(k, u);
                if (adj != nullptr && k != v && adj->getCor() != -1) {
                    coresUsadas[adj->getCor()] = true;
                }
            }
        }
        // Verifica as cores das arestas adjacentes ao vértice v
        for (int k = 0; k < ordem; k++) {
            NodeEdge* adj = this->getAresta(v, k);
            if (adj != nullptr && (direcionado || k != u) && adj != aresta && adj->getCor() != -1) {
                coresUsadas[adj->getCor()] = true;
            }
            if (!direcionado) {
                adj = this->getAresta(k, v);
                if (adj != nullptr && k != u && adj->getCor() != -1) {
                    coresUsadas[adj->getCor()] = true;
                }
            }
        }
        // Encontra a menor cor disponível
        int corDisponivel = 1;
        while (corDisponivel <= ordem && coresUsadas[corDisponivel]) {
            corDisponivel++;
        }
        // Atribui a cor à aresta e à sua aresta espelhada, se não direcionado
        aresta->setCor(corDisponivel);
        if (!direcionado) {
            NodeEdge* arestaInversa = this->getAresta(v, u);
            if (arestaInversa != nullptr) {
                arestaInversa->setCor(corDisponivel);
            }
        }
        maxCor = std::max(maxCor, corDisponivel);
        delete[] coresUsadas;
    }
    delete[] uArray;
    delete[] vArray;
    delete[] arestaArray;
    for(int i = 0; i<this->getOrdem(); i+=1)
    {
        for(int j = 0; j<this->getOrdem(); j+=1)
        {
            NodeEdge* aresta = this->getAresta(i,j);
            if(aresta != nullptr)
            {
                aresta->setCor(-1);
            }
        }
    }
}
}
return maxCor;
}