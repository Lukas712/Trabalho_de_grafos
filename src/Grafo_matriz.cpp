#include<iostream>
#include "../include/Grafo_matriz.h"
using namespace std;

Grafo_matriz::Grafo_matriz(){
    matriz_adjacencia = nullptr;
    vertices = nullptr;
    capacidade = 10;
}
Grafo_matriz::~Grafo_matriz() {
    if (matriz_adjacencia != nullptr) {
        if (eh_direcionado()) {
            for (int i = 0; i < capacidade; i+=1) {
                for (int j = 0; j < capacidade; j+=1) {
                    delete matriz_adjacencia[i][j];
                }
                delete[] matriz_adjacencia[i];
            }
        } else {
            if (matriz_adjacencia[0] != nullptr) {
                int tamanho = capacidade * (capacidade - 1) / 2;
                for (int i = 0; i < tamanho; i+=1) {
                    delete matriz_adjacencia[0][i];
                }
                delete[] matriz_adjacencia[0];
            }
        }
        delete[] matriz_adjacencia;
    }
    delete[] vertices;
}

void Grafo_matriz::inicializaPesoVertices() {
    delete[] vertices;
    vertices = new NodeVertex[capacidade]();
}
void Grafo_matriz::inicializaMatriz() {
    if (eh_direcionado()) {
        matriz_adjacencia = new NodeEdge**[capacidade];
        for (int i = 0; i < capacidade; i+=1) {
            matriz_adjacencia[i] = new NodeEdge*[capacidade]();
        }
    } else {
        int tamanho = capacidade * (capacidade - 1) / 2;
        matriz_adjacencia = new NodeEdge**[1];
        matriz_adjacencia[0] = new NodeEdge*[tamanho]();
    }
}

void Grafo_matriz::resize(int novaCapacidade) {
NodeVertex* newVertices = new NodeVertex[novaCapacidade](); 
for (int i = 0; i < getOrdem(); i+=1) {
    newVertices[i].setValue(vertices[i].getValue());
    newVertices[i].setGrau(vertices[i].getGrau());
}
delete[] vertices;
vertices = newVertices;

NodeEdge*** novaMatriz = nullptr;
if (eh_direcionado()) {

    novaMatriz = new NodeEdge**[novaCapacidade];
    for (int i = 0; i < novaCapacidade; i+=1) {
        novaMatriz[i] = new NodeEdge*[novaCapacidade]();
    }

    for (int i = 0; i < capacidade; i+=1) {
        for (int j = 0; j < capacidade; j+=1) {
            novaMatriz[i][j] = matriz_adjacencia[i][j]; 
        }
    }

    for (int i = 0; i < capacidade; i+=1) {
        delete[] matriz_adjacencia[i];
    }
} else {
    int novoTamanho = novaCapacidade * (novaCapacidade - 1) / 2;
    int tamanhoAntigo = capacidade * (capacidade - 1) / 2;
    novaMatriz = new NodeEdge**[1];
    novaMatriz[0] = new NodeEdge*[novoTamanho]();

    for (int i = 0; i < tamanhoAntigo; i+=1) {
        novaMatriz[0][i] = matriz_adjacencia[0][i];
    }

    delete[] matriz_adjacencia[0];
}

delete[] matriz_adjacencia;
matriz_adjacencia = novaMatriz;
capacidade = novaCapacidade;
}


void Grafo_matriz::insereVertice(float val) {
    if (getOrdem() >= capacidade) {
        resize(capacidade * 2);
    }
    if (vertices == nullptr) {
        inicializaPesoVertices();
    }
    vertices[getOrdem()].setValue(val);
    setOrdem(getOrdem()+1);
}


void Grafo_matriz::insereAresta(int origem, int destino, float val) {
    if(origem < 1 || origem > getOrdem() || destino < 1 || destino > getOrdem()) {
        cout<<"Aresta inválida!"<<endl;
        return;
    }
    if(origem != destino)
    {
        origem -=1;
        destino-=1;
        if(matriz_adjacencia == nullptr)
        {
            inicializaMatriz();
        }
        if(origem >=0 && origem < getOrdem() && destino >=0 && destino < getOrdem())
        {
            if(getAresta(origem, destino) != nullptr)
            {
                cout<<"Aresta inválida!"<<endl;
                return;
            }
            else
            {
                NodeEdge** aresta = retornaCelulaMatriz(origem, destino);
                *aresta = new NodeEdge();
                (*aresta)->setPeso(val);
                (*aresta)->setValue(destino+1);
                vertices[origem].setGrau(vertices[origem].getGrau()+1);
                if(!eh_direcionado())
                {
                    vertices[destino].setGrau(vertices[destino].getGrau()+1);
                }
            }
        }
    }
}

NodeEdge** Grafo_matriz::retornaCelulaMatriz(int i, int j)
{
    if(eh_direcionado())
    {
        return &matriz_adjacencia[i][j];
    }
    else
    {
        if(i<j)
        {
            return &matriz_adjacencia[0][j*(j-1)/2 + i];
        }
        else
        {
            return &matriz_adjacencia[0][i*(i-1)/2 + j];
        }
    }
}

NodeVertex* Grafo_matriz::getVertice(int id)
{
    if(id >= getOrdem() || id < 0)
    {
        return nullptr;
    }
    return &vertices[id];
}

NodeEdge* Grafo_matriz::getAresta(int origem, int destino)
{
    if(origem >=0 && origem < getOrdem() && destino >=0 && destino < getOrdem() && origem != destino)
    {
        return *retornaCelulaMatriz(origem, destino);
    }
    return nullptr;
}

void Grafo_matriz::removeAresta(int i, int j)
{
    if(i>= 1 && i <=getOrdem() && j>=1 && j<=getOrdem())
    {
        NodeEdge** arestaPtr = retornaCelulaMatriz(i-1, j-1);
        
        vertices[i-1].setGrau(vertices[i-1].getGrau()-1);
        if (*arestaPtr != nullptr) {
            cout<<"Removendo a aresta ("<< i<<","<<j<<")"<<endl;
            delete *arestaPtr;
            *arestaPtr = nullptr;
        }
        else
        {
            cout<<"Aresta inválida!"<<endl;
        }
    }
    else
    {
        cout<<"Aresta inválida!"<<endl;
    }
}

void Grafo_matriz::removeVertice(int id) {
    if (id < 1 || id > getOrdem()) {
        cout << "ID inválido!" << endl;
        return;
    }
    int k = id - 1;

    for (int i = 0; i < getOrdem(); i+=1) {
        if (eh_direcionado()) {
            NodeEdge** arestaEntrada = retornaCelulaMatriz(i, k);
            if (*arestaEntrada != nullptr) {
                vertices[i].setGrau(vertices[i].getGrau() - 1);
            }
        } 
        else {
            NodeEdge** aresta = retornaCelulaMatriz(k, i);
                if (*aresta != nullptr) {
                    vertices[i].setGrau(vertices[i].getGrau() - 1);
                }
        }
}


    for(int i = 0; i< getOrdem(); i+=1)
        {
            NodeEdge** arestaPtr = retornaCelulaMatriz(k, i);
            if (*arestaPtr != nullptr) {
                delete *arestaPtr;
                *arestaPtr = nullptr;
            }
            arestaPtr = retornaCelulaMatriz(i, k);
            if (*arestaPtr != nullptr) {
                delete *arestaPtr;
                *arestaPtr = nullptr;
            }
        }
    
    NodeVertex* newVertices = new NodeVertex[capacidade]();
    for (int i = 0, j = 0; i < getOrdem(); i+=1) {
        if (i != k) {
            newVertices[j].setValue(vertices[i].getValue());
            newVertices[j].setGrau(vertices[i].getGrau());
            j+=1;
        }
    }
    delete[] vertices;
    vertices = newVertices;
    
    for (int i = k; i < getOrdem()-1; i+=1) {
        for (int j = 0; j < getOrdem()-1; j+=1) {
            if((*retornaCelulaMatriz(i+1,j+1)) != nullptr && i != j) {
                (*retornaCelulaMatriz(i,j)) = (*retornaCelulaMatriz(i+1,j+1));
            } else {
                (*retornaCelulaMatriz(i,j)) = nullptr;
            }
        }
    }

    for (int i = 0; i < getOrdem() - 1; i+=1) {
        *retornaCelulaMatriz(i, getOrdem() - 1) = nullptr;
        *retornaCelulaMatriz(getOrdem() - 1, i) = nullptr;
    }

        
        
    cout<<"Removendo o vértice: "<< id<<endl;
    setOrdem(getOrdem()-1);

}

