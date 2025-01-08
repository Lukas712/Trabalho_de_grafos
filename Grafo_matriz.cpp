#include<iostream>
#include "Grafo_matriz.h"
#include "Linked_list.hpp"
using namespace std;

Grafo_matriz::Grafo_matriz(){
    matriz_adjacencia = nullptr;
    peso_Vertice = nullptr;
    numVertices = 0;
}
Grafo_matriz::~Grafo_matriz(){
    if(matriz_adjacencia != nullptr){
        if(eh_direcionado()) {
            for(int i = 0; i < numVertices; i+=1){
                delete[] matriz_adjacencia[i];
            }
            delete[] matriz_adjacencia;
        }
        else {
            delete[] matriz_adjacencia[0];
            delete[] matriz_adjacencia;
        }
    }
    delete[] peso_Vertice;
}


void Grafo_matriz::inicializaMatriz()
{
    if(matriz_adjacencia == nullptr)
    {
        if(eh_direcionado())
        {
            matriz_adjacencia = new int*[getOrdem()]();
            for(int i = 0; i< getOrdem(); i+=1)
            {
                matriz_adjacencia[i] = new int[getOrdem()]();
            }
        }
        else
        {
            int tamanho = getOrdem()*(getOrdem()-1)/2;
            matriz_adjacencia = new int*[1]();
            matriz_adjacencia[0] = new int[tamanho]();
        }
    }
}

void Grafo_matriz::inicializaPesoVertices()
{
    peso_Vertice = new int[getOrdem()]();
}

void Grafo_matriz::insereVertice(int val){
    if(peso_Vertice == nullptr)
    {
        inicializaPesoVertices();
    }
    peso_Vertice[numVertices++] = val;
}

void Grafo_matriz::insereAresta(int origem, int destino, int val) {
    if(matriz_adjacencia == nullptr)
    {
        inicializaMatriz();
    }
    origem -=1;
    destino-=1;
    if (origem< getOrdem() && destino < getOrdem()) {
        if(val != 0)
        {
            if(eh_direcionado())
            {
                matriz_adjacencia[origem][destino] = val;
            }
            else
            {
                if(origem < destino)
                {
                    matriz_adjacencia[0][(destino-1)*destino/2 + origem] = val;
                }
            }
        }
        else
        {
            if(eh_direcionado())
            {
                matriz_adjacencia[origem][destino] = 1;
            }
            else
            {
                if(origem < destino)
                {
                    matriz_adjacencia[0][(destino-1)*destino/2 + origem] = 1;
                }
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
            if(i != j)
            {
                if (*retornaCelulaMatriz(i,j) != 0) {
                    contadorGrau+=1;
                }
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
    
    for(int i = 0; i<getOrdem(); i+=1)
    {
        for(int j = 0; j<getOrdem(); j+=1)
        {
            if(eh_direcionado())
            {
                if(i != j)
                {
                    if(matriz_adjacencia[i][j] != matriz_adjacencia[j][i] && matriz_adjacencia[i][j] > 0)
                    {
                        return false;
                    }
                }
            }
            else
            {
                if(*retornaCelulaMatriz(i,j) == 0)
                {
                    return false;
                }
            }
        }
    }
    {
        return true;
    }
    return false;
}

bool Grafo_matriz::temCiclo(int v, int visitado[], int pai) {
    visitado[v] = 1;

    for (int u = 0; u < getOrdem(); u+=1) {
        bool arestaExiste = false;
        
        if (eh_direcionado()) {
            if (*retornaCelulaMatriz(v, u) != 0) {
                arestaExiste = true;
            }
        } else {
            if (v < u && *retornaCelulaMatriz(v, u) != 0) {
                arestaExiste = true;
            } else if (u < v && *retornaCelulaMatriz(u, v) != 0) {
                arestaExiste = true;
            }
        }

        if (arestaExiste) {
            if (!visitado[u]) {
                if (temCiclo(u, visitado, v)) {
                    return true;
                }
            } else if (u != pai) {
                return true;
            }
        }
    }
    return false;
}

bool Grafo_matriz::eh_arvore() {
    if (getNConexo() != 1) {
        return false;
    }

    int numArestas = 0;
    for (int i = 0; i < getOrdem(); i+=1) {
        for (int j = i + 1; j < getOrdem(); j++) {
            if (*retornaCelulaMatriz(i, j) != 0) {
                numArestas++;
            }
        }
    }

    if (numArestas != getOrdem() - 1) {
        return false;
    }

    int visitado[getOrdem()] = {0};
    if (temCiclo(0, visitado, -1)) {
        return false;
    }

    return true;
}

    int Grafo_matriz::getNConexo()
    {
            int* componentes = new int[getOrdem()]();

            for(int i = 0; i<getOrdem(); i+=1)
            {
                componentes[i] = i+1;
            }
            for(int i = 0; i < getOrdem(); i+=1)
            {
                for(int j = 0; j < getOrdem(); j+=1)
                {
                    if(*retornaCelulaMatriz(i,j) != 0 && i!=j)
                    {
                        int menor = min(componentes[i], componentes[j]);
                        int maior = max(componentes[i], componentes[j]);

                        componentes[i] = menor;
                        componentes[j] = menor;
                    
                        for (int k = 0; k < getOrdem(); k+=1) {
                            if (componentes[k] == maior) {
                                componentes[k] = menor;
                            }
                        }
                        
                    }
                }
            }
            int contaDiferente = 1;
            for(int i = 1; i<getOrdem(); i+=1)
            {
                if(componentes[i] != componentes[i-1])
                {
                    contaDiferente+=1;
                }
            }
            delete[] componentes;
            if(contaDiferente == 0)
            {
            return 1;
            }
            else
            return contaDiferente;
    }

int* Grafo_matriz::retornaCelulaMatriz(int i, int j)
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

bool Grafo_matriz::eh_bipartido() {
    int cor[getOrdem()];
    for (int i = 0; i < getOrdem(); i++) {
        cor[i] = -1;
    }

    int pilha[getOrdem()];
    int topo = -1;

    for (int i = 0; i < getOrdem(); i++) {
        if (cor[i] == -1) {
            pilha[++topo] = i;
            cor[i] = 0;

            while (topo >= 0) {
                int u = pilha[topo--];

                for (int v = 0; v < getOrdem(); v++) {
                    bool arestaExiste = false;

                    if (eh_direcionado()) {
                        arestaExiste = *retornaCelulaMatriz(u, v) != 0;
                    }
                    else if (u < v) {
                        arestaExiste = *retornaCelulaMatriz(u, v) != 0;
                    }

                    if (arestaExiste) {
                        if (cor[v] == -1) {
                            cor[v] = 1 - cor[u];
                            pilha[++topo] = v;
                        } else if (cor[v] == cor[u]) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}


bool Grafo_matriz::possuiPonte() {
    
    
    int nInicial = getNConexo();
    for (int u = 0; u < getOrdem(); u++) {
        for (int v = u+1; v < getOrdem(); v++) {

            if (*retornaCelulaMatriz(u, v) != 0) {

                int valorOriginal = *retornaCelulaMatriz(u, v);
                *retornaCelulaMatriz(u, v) = 0;


                int nFinal = getNConexo();
                

                
                if (nFinal > nInicial) {
                    *retornaCelulaMatriz(u, v) = valorOriginal;
                    
                    return true;
                }

                *retornaCelulaMatriz(u, v) = valorOriginal;
            }
        }
    }
    

    return false;
}

bool Grafo_matriz::possuiArticulacao() {
    int nInicial = getNConexo();
    int** backup_matriz = new int*[getOrdem()]();
    for (int i = 0; i < getOrdem(); i++) {
        backup_matriz[i] = new int[getOrdem()]();
        for (int j = 0; j < getOrdem(); j++) {
            backup_matriz[i][j] = *retornaCelulaMatriz(i, j);
        }
    }

    for (int v = 0; v < getOrdem(); v++) {
        int** temp_matriz = new int*[getOrdem()]();
        for (int i = 0; i < getOrdem(); i++) {
            temp_matriz[i] = new int[getOrdem()]();
            for (int j = 0; j < getOrdem(); j++) {
                temp_matriz[i][j] = backup_matriz[i][j];
            }
        }

        for (int i = 0; i < getOrdem(); i++) {
            temp_matriz[v][i] = 0;
            temp_matriz[i][v] = 0;
        }

        int** old_matriz = matriz_adjacencia;
        matriz_adjacencia = temp_matriz;

        int nFinal = getNConexo();
        
        for (int i = 0; i < getOrdem(); i++) {
            delete[] temp_matriz[i];
        }
        delete[] temp_matriz;
        matriz_adjacencia = old_matriz;

        if (nFinal > nInicial) {
            for (int i = 0; i < getOrdem(); i++) {
                delete[] backup_matriz[i];
            }
            delete[] backup_matriz;
            return true;
        }
    }

    for (int i = 0; i < getOrdem(); i++) {
        delete[] backup_matriz[i];
    }
    delete[] backup_matriz;
    return false;
}