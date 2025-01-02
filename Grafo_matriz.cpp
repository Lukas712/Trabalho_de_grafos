#include<iostream>
#include "Grafo_matriz.h"
using namespace std;

Grafo_matriz::Grafo_matriz(){
    matriz_adjacencia = nullptr;
    peso_Vertice = nullptr;
    numVertices = 0;
}
Grafo_matriz::~Grafo_matriz(){
    if(matriz_adjacencia != nullptr){
        for(int i = 0; i < numVertices; i++){
            delete[] matriz_adjacencia[i];
        }
        delete[] matriz_adjacencia;
    }
}

void Grafo_matriz::insereVertice(int val){
    
    int* novosValoresVertices = new int[numVertices + 1];
    for (int i = 0; i < numVertices; i+=1) {
        novosValoresVertices[i] = peso_Vertice[i];
    }

    novosValoresVertices[numVertices] = val;
    if (peso_Vertice != nullptr) {
        delete[] peso_Vertice;
    }

    peso_Vertice = novosValoresVertices;
    numVertices+=1;
    int** novaMatriz = new int*[numVertices];
    for (int i = 0; i < numVertices; i+=1) {
        novaMatriz[i] = new int[numVertices];
    }
    
    for (int i = 0; i < numVertices - 1; i+=1) {
        for (int j = 0; j < numVertices - 1; j+=1) {
            novaMatriz[i][j] = matriz_adjacencia[i][j];
        }
    }

    for (int i = 0; i < numVertices; i+=1) {
        novaMatriz[i][numVertices - 1] = 0;
        novaMatriz[numVertices - 1][i] = 0;
    }
    if (matriz_adjacencia != nullptr) {
        for (int i = 0; i < numVertices - 1; i+=1) {
            delete[] matriz_adjacencia[i];
        }
        delete[] matriz_adjacencia;
    }

    matriz_adjacencia = novaMatriz;
}

void Grafo_matriz::insereAresta(int origem, int destino, int val) {
    if (origem-1 < getOrdem() && destino-1 < getOrdem()) {
        if(val != 0)
        {
            matriz_adjacencia[origem-1][destino-1] = val;
            if (!eh_direcionado()) {
                matriz_adjacencia[destino-1][origem-1] = val;
            }
        }
        else
        {
            matriz_adjacencia[origem-1][destino-1] = 1;
            if (!eh_direcionado()) {
                matriz_adjacencia[destino-1][origem-1] = 1;
            }
        }
        
    }
}

int Grafo_matriz::getGrau()
{
    int grauMaior = 0;
    int contadorGrau = 0;
    for (int i = 0; i < getOrdem(); i+=1) {
        for (int j = 0; j < getOrdem(); j+=1) {
            if (matriz_adjacencia[i][j] != 0) {
                contadorGrau+=1;
            }
        }
        if(contadorGrau>grauMaior)
        {
            grauMaior = contadorGrau;
        }
        contadorGrau = 0;
    }
    return grauMaior;
}

bool Grafo_matriz::eh_completo()
{
    for (int i = 0; i < numVertices; i+=1) {
        for (int j = 0; j < numVertices; j+=1) {
            if(i!=j)
            {
                if (matriz_adjacencia[i][j] == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

int Grafo_matriz::getNConexo()
{
    cout << "Matriz de Adjacência:" << endl;
    for (int i = 0; i < numVertices; i+=1) {
        for (int j = 0; j < numVertices; j+=1) {
            cout << matriz_adjacencia[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Valores dos Vértices:" << endl;
    for (int i = 0; i < numVertices; i+=1) {
        cout << "Vértice " << i << ": " << peso_Vertice[i] << endl;
    }

    return 0;
}
