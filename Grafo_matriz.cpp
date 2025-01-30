#include<iostream>
#include "Grafo_matriz.h"
#include "Linked_list.hpp"
using namespace std;

Grafo_matriz::Grafo_matriz(){
    matriz_adjacencia = nullptr;
    vertices = nullptr;
    numVertices = 0;
}
Grafo_matriz::~Grafo_matriz() {
    if (matriz_adjacencia != nullptr) {
        if (eh_direcionado()) {
            for (int i = 0; i < numVertices; i++) {
                if (matriz_adjacencia[i] != nullptr) { 
                    for (int j = 0; j < numVertices; j++) {
                        delete matriz_adjacencia[i][j];
                    }
                    delete[] matriz_adjacencia[i];
                }
            }
        } else {
            int tamanho = numVertices * (numVertices - 1) / 2;
            if (matriz_adjacencia[0] != nullptr) {
                for (int i = 0; i < tamanho; i++) {
                    delete matriz_adjacencia[0][i];
                }
                delete[] matriz_adjacencia[0];
            }
        }
        delete[] matriz_adjacencia;
    }

    if (vertices != nullptr) {
        delete[] vertices;
    }
}



void Grafo_matriz::inicializaMatriz()
{
    if (matriz_adjacencia == nullptr) {
        if (eh_direcionado()) {
            matriz_adjacencia = new NodeEdge**[getOrdem()]();
            for (int i = 0; i < getOrdem(); i++) {
                matriz_adjacencia[i] = new NodeEdge*[getOrdem()];
            }
            for(int i = 0; i < getOrdem(); i++)
            {
                for(int j = 0; j < getOrdem(); j++)
                {
                    matriz_adjacencia[i][j] = nullptr;
                }
            }
        } else {
            int tamanho = getOrdem() * (getOrdem() - 1) / 2;
            matriz_adjacencia = new NodeEdge**[1]();
            matriz_adjacencia[0] = new NodeEdge*[tamanho]();
            for(int i = 0; i < tamanho; i++)
            {
                matriz_adjacencia[0][i] = nullptr;
            }
        }
}

}
void Grafo_matriz::inicializaPesoVertices() {
    if (vertices != nullptr) { 
        delete[] vertices; 
    }
    vertices = new NodeVertex[getOrdem()]();
}


void Grafo_matriz::insereVertice(int val) {
    if (vertices == nullptr) {
        inicializaPesoVertices();
    }
    vertices[numVertices].setValue(val); 
    numVertices++;
}


void Grafo_matriz::insereAresta(int origem, int destino, int val) {
    if(matriz_adjacencia == nullptr)
    {
        inicializaMatriz();
    }
    origem -=1;
    destino-=1;
    if (origem< getOrdem() && destino < getOrdem()) {
        NodeEdge** aresta = retornaCelulaMatriz(origem, destino);
        *aresta = new NodeEdge();
        (*aresta)->setValue(val);
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
