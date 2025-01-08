#include <iostream>
#include <fstream>
#include "Grafo_lista.h"
#include <ctime>
#include <cstdlib>
using namespace std;

Grafo_lista::Grafo_lista(){
    this->Vertice = new Linked_Vertex();
}
Grafo_lista::~Grafo_lista(){
    delete Vertice;
}

void Grafo_lista::insereVertice(int val)
{
    this->Vertice->insereFinal(val);
}

void Grafo_lista::insereAresta(int origem, int destino, int val)
{
    this->Vertice->insereAresta(origem, destino, val);
}

int Grafo_lista::getGrau()
{
    int maior = this->Vertice->getPrimeiro()->getArestas()->getTam();
    for(int i= 0; i<getOrdem(); i+=1)
    {
        NodeVertex* no = this->Vertice->getNodeById(i);
        if(maior < no->getArestas()->getTam())
        {
            maior = no->getArestas()->getTam();
        } 
    }
    return maior;
}

int Grafo_lista::getNConexo() {
    int ordem = getOrdem();
    int* componentes = new int[ordem];

    for (int i = 0; i < ordem; i++) {
        componentes[i] = i + 1;
    }
    for (int i = 0; i < ordem; i++) {
        NodeVertex* node = this->Vertice->getNodeById(i);
        if (!node) continue;

        NodeEdge* edge = node->getArestas()->getPrimeiro();
        while (edge) {
            if (edge->getAtivo()) {
                int j = edge->getValue();
                if (i != j) {
                    int menor = min(componentes[i], componentes[j]);
                    int maior = max(componentes[i], componentes[j]);

                    for (int k = 0; k < ordem; k++) {
                        if (componentes[k] == maior) {
                            componentes[k] = menor;
                        }
                    }
                }
            }
            edge = (NodeEdge*)edge->getProx();
        }
    }

    int contaDiferente = 0;
    bool* visitado = new bool[ordem]();

    for (int i = 0; i < ordem; i++) {
        if (!visitado[componentes[i]]) {
            contaDiferente++;
            visitado[componentes[i]] = true;
        }
    }

    delete[] componentes;
    delete[] visitado;
    return contaDiferente;
}



bool Grafo_lista::eh_completo()
{
    for(int i = 0; i < getOrdem(); i+=1)
    {
        NodeVertex* no = this->Vertice->getNodeById(i);
        if(no->getArestas()->getTam() != getOrdem()-1)
        {
            return false;
        }
    }
    return true;
}

bool Grafo_lista::temCiclo(int v, int visitado[], int pai) {
    visitado[v] = 1;

    NodeVertex* node = this->Vertice->getNodeById(v);
    NodeEdge* edge = node->getArestas()->getPrimeiro();

    while (edge != nullptr) {
        int u = edge->getValue();
        if (!visitado[u]) {
            if (temCiclo(u, visitado, v)) {
                return true;
            }
        } else if (u != pai) {
            return true;
        }
        edge = (NodeEdge*)edge->getProx();
    }
    return false;
}

bool Grafo_lista::eh_arvore() {
    if (getNConexo() != 1) {
        return false;
    }

    int numArestas = 0;
    for (int i = 0; i < getOrdem(); i++) {
        NodeVertex* node = this->Vertice->getNodeById(i);
        NodeEdge* edge = node->getArestas()->getPrimeiro();

        while (edge != nullptr) {
            int j = edge->getValue();
            if (i < j) {
                numArestas++;
            }
            edge = (NodeEdge*)edge->getProx();
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

bool Grafo_lista::eh_bipartido() {
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

                NodeVertex* node = this->Vertice->getNodeById(u);
                NodeEdge* edge = node->getArestas()->getPrimeiro();

                while (edge != nullptr) {
                    int v = edge->getValue();

                    if (cor[v] == -1) {
                        cor[v] = 1 - cor[u];
                        pilha[++topo] = v;
                    } else if (cor[v] == cor[u]) {
                        return false;
                    }
                    edge = (NodeEdge*)edge->getProx();
                }
            }
        }
    }

    return true;
}

bool Grafo_lista::possuiPonte() {
    int nInicial = getNConexo();

    for (int i = 0; i < getOrdem(); i++) {
        NodeVertex* no = this->Vertice->getNodeById(i);
        if (!no || !no->getAtivo()) continue;

        NodeEdge* aresta = no->getArestas()->getPrimeiro();
        while (aresta) {
            int j = aresta->getValue();
            NodeVertex* vizinho = this->Vertice->getNodeById(j);

            if (vizinho && vizinho->getAtivo()) {
                bool ativoOrig = aresta->getAtivo();
                aresta->setAtivo(false);

                int nFinal = getNConexo();

                aresta->setAtivo(ativoOrig);

                if (nFinal > nInicial) {
                    return true;
                }
            }

            aresta = (NodeEdge*)aresta->getProx();
        }
    }

    return false;
}

bool Grafo_lista::possuiArticulacao() {
    int nInicial = getNConexo();

    for (int i = 0; i < getOrdem(); i++) {
        NodeVertex* no = this->Vertice->getNodeById(i);
        if (!no || !no->getAtivo()) continue;

        bool ativoOrig = no->getAtivo();
        no->setAtivo(false);

        NodeEdge* aresta = no->getArestas()->getPrimeiro();
        while (aresta) {
            aresta->setAtivo(false);
            aresta = (NodeEdge*)aresta->getProx();
        }

        int nFinal = getNConexo();

        no->setAtivo(ativoOrig);

        aresta = no->getArestas()->getPrimeiro();
        while (aresta) {
            aresta->setAtivo(true);
            aresta = (NodeEdge*)aresta->getProx();
        }

        if (nFinal > nInicial) {
            return true;
        }
    }

    return false;
}