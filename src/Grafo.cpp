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

int Grafo::coloracaoArestaGuloso(){
    int nCores = 0;
    int ordem = this->getOrdem();
    NodeEdge*** mArestas = new NodeEdge**[ordem];
    for(int i = 0; i<ordem; i+=1)
    {
        mArestas[i] = new NodeEdge*[ordem]();
    }
    for(int i = 0; i<ordem; i+=1)
    {
        for(int j = 0; j<ordem; j+=1)
        {
            if(j>i) continue;
            NodeEdge* arestaTemp = this->getAresta(i,j);
            mArestas[i][j] = arestaTemp;
            mArestas[j][i] = arestaTemp;
        }
    }
    for(int  i = 0; i< ordem; i+=1)
    {
        for(int j = 0; j<ordem; j+=1)
        {
            NodeEdge* aresta = mArestas[i][j];
            if(aresta == nullptr || aresta->getCor() != -1)
            {
                continue;
            }
            bool coresUsadas[ordem-1] = {false};
            for(int k = 0; k<ordem; k+=1)
            {
                NodeEdge* adjacenteDeI = mArestas[i][k];

                NodeEdge* adjacenteDeJ = mArestas[j][k];

                if(adjacenteDeI != nullptr && adjacenteDeI != aresta && adjacenteDeI->getCor() != -1)
                {
                    coresUsadas[adjacenteDeI->getCor()-1] = true;
                }
                if(adjacenteDeJ != nullptr && adjacenteDeJ != aresta && adjacenteDeJ->getCor() != -1)
                {
                    coresUsadas[adjacenteDeJ->getCor()-1] = true;
                }
            }
            int corDisponivel = 1;
            while(corDisponivel<= ordem && coresUsadas[corDisponivel-1])
            {
                corDisponivel+=1;
            }

            aresta->setCor(corDisponivel);
            if(!this->eh_direcionado())
            {
                NodeEdge* arestaEspelho = mArestas[j][i];
                if(arestaEspelho != nullptr)
                {
                    arestaEspelho->setCor(corDisponivel);
                }
            }
            if(corDisponivel > nCores)
            {
                nCores = corDisponivel;
            }
        }
    }
    for(int i = 0; i<ordem; i+=1)
    {
        for(int j = 0; j<ordem; j+=1)
        {
            mArestas[i][j] = nullptr;
            delete mArestas[i][j];
        }
        delete[] mArestas[i];
    }
    delete[] mArestas;
    descoloreGrafo();
    return nCores;
}

int Grafo::coloracaoArestaRandomizado() {
    int nCores = 0;
    int ordem = this->getOrdem();
    int nArestas = 0;
    srand(time(nullptr));
    NodeEdge*** mArestas = new NodeEdge**[ordem];
    for(int i = 0; i<ordem; i+=1)
    {
        mArestas[i] = new NodeEdge*[ordem]();
    }
    for(int i = 0; i<ordem; i+=1)
    {
        for(int j = 0; j<ordem; j+=1)
        {
            if(j>i) continue;
            NodeEdge* arestaTemp = this->getAresta(i,j);
            if(arestaTemp != nullptr)
            {
                nArestas+=1;
            }
            mArestas[i][j] = arestaTemp;
            mArestas[j][i] = arestaTemp;
        }
    }

    while(nArestas > 0) {
        int i, j;
        NodeEdge* aresta = nullptr;
        do {
            i = rand() % ordem;
            j = rand() % ordem;
            aresta = mArestas[i][j];
        } while(i == j || aresta == nullptr || aresta->getCor() != -1);

        bool* coresUsadas = new bool[nCores + 1]();

        for (int k = 0; k < ordem; k+=1) {
            NodeEdge* adjI = mArestas[i][k];
            NodeEdge* adjJ = mArestas[j][k];

            if (adjI != nullptr && adjI->getCor() != -1) {
                int cor = adjI->getCor();
                if (cor <= nCores) coresUsadas[cor] = true;
            }
            if (adjJ != nullptr && adjJ != aresta && adjJ->getCor() != -1) {
                int cor = adjJ->getCor();
                if (cor <= nCores) coresUsadas[cor] = true;
            }
        }

        int* coresDisponiveis = new int[nCores + 1];
        int totalDisponiveis = 0;

        for (int k = 0; k <= nCores; k+=1) {
            if (!coresUsadas[k]) {
                coresDisponiveis[totalDisponiveis] = k;
                totalDisponiveis+=1;
            }
        }

        int corEscolhida;
        if (totalDisponiveis == 0) {
            nCores+=1;
            corEscolhida = nCores;
        } else {
            int escolha = rand() % totalDisponiveis;
            corEscolhida = coresDisponiveis[escolha];
        }

        delete[] coresUsadas;
        delete[] coresDisponiveis;

        aresta->setCor(corEscolhida);
        if(!this->eh_direcionado()) {
            NodeEdge* espelho = mArestas[j][i];
            if(espelho != nullptr)
            {
                espelho->setCor(corEscolhida);
            }
        }

        nArestas-=1;
    }
    for(int i = 0; i<ordem; i+=1)
    {
        for(int j = 0; j<ordem; j+=1)
        {
            mArestas[i][j] = nullptr;
            delete mArestas[i][j];
        }
        delete[] mArestas[i];
    }
    delete[] mArestas;
    descoloreGrafo();
    return nCores + 1;
}


int Grafo::coloracaoArestaReativo() {
    int nCores = 0;
    int ordem = this->getOrdem();
    int nArestas = 0;

    NodeEdge*** mArestas = new NodeEdge**[ordem];
    for(int i = 0; i<ordem; i+=1)
    {
        mArestas[i] = new NodeEdge*[ordem]();
    }
    for(int i = 0; i<ordem; i+=1)
    {
        for(int j = 0; j<ordem; j+=1)
        {
            if(j>i) continue;
            NodeEdge* arestaTemp = this->getAresta(i,j);
            if(arestaTemp != nullptr)
            {
                nArestas+=1;
            }
            mArestas[i][j] = arestaTemp;
            mArestas[j][i] = arestaTemp;
        }
    }

    float pontosGulosos = 1.0;
    float pontosRandomizados = 1.0;
    float recompensaUm = 1.1;
    float recompensaDois = 0.9;
    float minScore = 0.1;

    srand(time(nullptr));

    while(nArestas > 0) {
        int oldNCores = nCores;

        int i, j;
        NodeEdge* aresta = nullptr;
        do {
            i = rand() % ordem;
            j = rand() % ordem;
            if(i > j) swap(i, j);
            aresta = mArestas[i][j];
        } while(i == j || aresta == nullptr || aresta->getCor() != -1);

        bool coresUsadas[nCores] = {false};
        for(int k = 0; k < ordem; k+=1) {
            NodeEdge* adjI = mArestas[i][k];
            NodeEdge* adjJ = mArestas[j][k];

            if(adjI != nullptr && adjI != aresta && adjI->getCor() != -1) {
                coresUsadas[adjI->getCor() - 1] = true;
            }
            if(adjJ != nullptr && adjJ != aresta && adjJ->getCor() != -1) {
                coresUsadas[adjJ->getCor() - 1] = true;
            }
        }

        float pontuacaoGeral = pontosGulosos + pontosRandomizados;
        float probGuloso = pontosGulosos / pontuacaoGeral;
        bool usaGuloso = (float)rand() / RAND_MAX < probGuloso;

        int corEscolhida;

        if(usaGuloso) {
            corEscolhida = 1;
            while(corEscolhida <= nCores && coresUsadas[corEscolhida - 1]) {
                corEscolhida+=1;
            }
            if(corEscolhida > nCores) {
                nCores+=1;
                corEscolhida = nCores;
            }
        } else {
            int disponiveis = 0;
            for(int c = 0; c < nCores; c+=1) {
                if(!coresUsadas[c]) disponiveis+=1;
            }

            if(disponiveis == 0) {
                nCores+=1;
                corEscolhida = nCores;
            } else {
                int escolha = rand() % disponiveis;
                int contador = 0;
                for(int c = 0; c < nCores; c+=1) {
                    if(!coresUsadas[c]) {
                        if(contador == escolha) {
                            corEscolhida = c + 1;
                            break;
                        }
                        contador+=1;
                    }
                }
            }
        }

        bool novaCor = (corEscolhida > oldNCores);
        if(usaGuloso) {
            if(novaCor) {
                pontosGulosos = max(pontosGulosos * recompensaDois, minScore);
            } else {
                pontosGulosos *= recompensaUm;
            }
        } else {
            if(novaCor) {
                pontosRandomizados = max(pontosRandomizados * recompensaDois, minScore);
            } else {
                pontosRandomizados *= recompensaUm;
            }
        }


        aresta->setCor(corEscolhida);
        if(!this->eh_direcionado()) {
            NodeEdge* espelho = mArestas[j][i];
            if(espelho != nullptr) espelho->setCor(corEscolhida);
        }

        nArestas-=1;
    }
    for(int i = 0; i<ordem; i+=1)
    {
        for(int j = 0; j<ordem; j+=1)
        {
            mArestas[i][j] = nullptr;
            delete mArestas[i][j];
        }
        delete[] mArestas[i];
    }
    delete[] mArestas;
    descoloreGrafo();
    return nCores;
}
