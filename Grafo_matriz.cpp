#include<iostream>
#include "Grafo_matriz.h"
#include "Linked_list.hpp"
using namespace std;

Grafo_matriz::Grafo_matriz(){
    matriz_adjacencia = nullptr;
    vertices = nullptr;
    numVertices = 0;
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
        } 
        else
        {
            delete[] matriz_adjacencia[0];
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
    for (int i = 0; i < numVertices; i+=1) {
        newVertices[i].setValue(vertices[i].getValue());
    }
    delete[] vertices;
    vertices = newVertices;

    NodeEdge*** novaMatriz = nullptr;
    if (eh_direcionado()) {
        novaMatriz = new NodeEdge**[novaCapacidade];
        for (int i = 0; i < novaCapacidade; i+=1) {
            novaMatriz[i] = new NodeEdge*[novaCapacidade]();
            for (int j = 0; j < capacidade; j+=1) {
                if (i < capacidade && j < capacidade) {
                    novaMatriz[i][j] = matriz_adjacencia[i][j];
                    matriz_adjacencia[i][j] = nullptr;
                }
            }
        }
        for (int i = 0; i < capacidade; i+=1) {
            delete[] matriz_adjacencia[i];
        }
    } else {
        int novoTamanho = novaCapacidade * (novaCapacidade - 1) / 2;
        novaMatriz = new NodeEdge**[1];
        novaMatriz[0] = new NodeEdge*[novoTamanho]();
    }

    delete[] matriz_adjacencia;
    matriz_adjacencia = novaMatriz;
    capacidade = novaCapacidade;
}

void Grafo_matriz::insereVertice(int val) {
    if (numVertices >= capacidade) {
        resize(capacidade * 2);
    }
    if (vertices == nullptr) {
        inicializaPesoVertices();
    }
    vertices[numVertices].setValue(val);
    numVertices+=1;
    setOrdem(numVertices);
}


void Grafo_matriz::insereAresta(int origem, int destino, int val) {
    origem -=1;
    destino-=1;
    if(matriz_adjacencia == nullptr)
    {
        inicializaMatriz();
    }
    if(getAresta(origem, destino) == nullptr)
    {
        if (origem>=0 && origem< getOrdem() && destino >= 0 && destino < getOrdem() && origem != destino) {
            NodeEdge** aresta = retornaCelulaMatriz(origem, destino);
            *aresta = new NodeEdge();
            (*aresta)->setValue(val);
        }
        else
        {
            cout<<"Não é possível inserir a aresta ("<<origem+1<<","<<destino+1<<")"<<endl;
        }
    }
    else
    {
        cout<<"Aresta entre: "<<origem+1<<" e "<<destino+1<<" já existe"<<endl;
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
    if(origem > getOrdem() || destino > getOrdem() || origem < 0 || destino < 0)
    {
        return nullptr;
    }
    return *retornaCelulaMatriz(origem, destino);
}

void Grafo_matriz::removeAresta(int i, int j)
{
    NodeEdge** arestaPtr = retornaCelulaMatriz(i-1, j-1);
    
    if (*arestaPtr != nullptr) {
        delete *arestaPtr;
        *arestaPtr = nullptr;
    }
    else
    {
        cout<<"A aresta: ("<< i <<","<<j <<") não existe!"<<endl;
    }
}

void Grafo_matriz::removeVertice(int id) {
    if (id < 1 || id > numVertices) {
        cout << "ID inválido!" << endl;
        return;
    }
    int k = id - 1;

    for (int i = 0; i < numVertices; i+=1) {
        NodeEdge** arestaPtr = retornaCelulaMatriz(k, i);
        if (*arestaPtr != nullptr) {
            delete *arestaPtr;
            *arestaPtr = nullptr;
        }
        if (eh_direcionado()) {
            NodeEdge** arestaReversa = retornaCelulaMatriz(i, k);
            if (*arestaReversa != nullptr) {
                delete *arestaReversa;
                *arestaReversa = nullptr;
            }
        }
    }

    NodeVertex* newVertices = new NodeVertex[capacidade](); 
    for (int i = 0; i < numVertices-1; i+=1) {
        newVertices[i].setValue(vertices[i].getValue());
    }
    delete[] vertices;
    vertices = newVertices;

    numVertices-=1;
    setOrdem(numVertices);

    if (eh_direcionado()) {
        NodeEdge*** novaMatriz = new NodeEdge**[capacidade];
        for (int i = 0; i < capacidade; i+=1) {
            novaMatriz[i] = new NodeEdge*[capacidade]();
        }

        for (int i = 0; i < numVertices; i+=1) {
            for (int j = 0; j < numVertices; j+=1) {
                int oldI;
                int oldJ;
                if(i<k) {
                    oldI = i;
                }
                else
                {
                    oldI = i+1;
                }
                if(j<k)
                {
                    oldJ = j;
                }
                else
                {
                    oldJ = j+1;
                }
                novaMatriz[i][j] = matriz_adjacencia[oldI][oldJ];
                matriz_adjacencia[oldI][oldJ] = nullptr;
            }
        }

        for (int i = 0; i < capacidade; i+=1) {
            delete[] matriz_adjacencia[i];
        }
        delete[] matriz_adjacencia;
        matriz_adjacencia = novaMatriz;
    } else {
        int novoTamanho = capacidade * (capacidade - 1) / 2;
        NodeEdge** novaMatriz = new NodeEdge*[novoTamanho]();

        for (int i = 0; i < numVertices; i+=1) {
            for (int j = i + 1; j < numVertices; j+=1) {
                int oldI;
                int oldJ;
                if(i<k) {
                    oldI = i;
                }
                else
                {
                    oldI = i+1;
                }
                if(j<k)
                {
                    oldJ = j;
                }
                else
                {
                    oldJ = j+1;
                }
                NodeEdge** oldEdge = retornaCelulaMatriz(oldI, oldJ);
                int newIndex = j * (j - 1) / 2 + i;
                novaMatriz[newIndex] = *oldEdge;
                *oldEdge = nullptr;
            }
        }

        delete[] matriz_adjacencia[0];
        matriz_adjacencia[0] = novaMatriz;
    }
}