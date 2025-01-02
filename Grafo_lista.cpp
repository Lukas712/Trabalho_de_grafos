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
    int maior = this->Vertice->getNodeById(0)->getArestas()->getTam();
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

void Grafo_lista::dfsAux(int vertice, bool* visitados) {
    visitados[vertice] = true;

    NodeVertex* noAtual = this->Vertice->getNodeById(vertice);

    Linked_list<NodeEdge>* arestas = noAtual->getArestas();
    NodeEdge* aresta = arestas->getPrimeiro();
    while (aresta != nullptr) {
        int destino = aresta->getValue();
        if (!visitados[destino]) {
            dfsAux(destino, visitados);
        }
        aresta = (NodeEdge*)aresta->getProx();
    }

    for (int i = 0; i < getOrdem(); i++) {
        NodeVertex* outroNo = this->Vertice->getNodeById(i);
        Linked_list<NodeEdge>* outrasArestas = outroNo->getArestas();
        NodeEdge* outraAresta = outrasArestas->getPrimeiro();
        while (outraAresta != nullptr) {
            if (outraAresta->getValue() == vertice && !visitados[i]) {
                dfsAux(i, visitados);
            }
            outraAresta = (NodeEdge*)outraAresta->getProx();
        }
    }
}


int Grafo_lista::getNConexo() {
    int numVertices = getOrdem();
    if (numVertices == 0) {
        return 0;
    }

    bool* visitados = new bool[numVertices];
    for (int i = 0; i < numVertices; i+=1) {
        visitados[i] = false;
    }

    int numComponentes = 0;

    for (int i = 0; i < numVertices; i+=1) {
        if (!visitados[i]) {
            numComponentes+=1;
            dfsAux(i, visitados);
        }
    }

    delete[] visitados;
    return numComponentes;
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

//tem que corrigir essa função depois
bool Grafo_lista::eh_arvore()
{
    if(getNConexo() != 1)
    {
        return false;
    }
    return !temCiclo(eh_direcionado());

}
//tem que corrigir essa função depois
bool Grafo_lista::temCiclo(bool direcionado) {
    int n = getOrdem(); 
    bool* visitado = new bool[n]; 
    bool* pilhaRecursao = new bool[n];

    visitado[0] = false;
    pilhaRecursao[0] = false;

    for (int i = 0; i < n; i+=1) {
        if (!visitado[i]) {
            if (dfsTemCiclo(i, -1, visitado, pilhaRecursao, direcionado)) {
                delete[] visitado;
                delete[] pilhaRecursao;
                return true; 
            }
        }
    }

    delete[] visitado;
    delete[] pilhaRecursao;
    return false; 
}

//Tem que corrigir essa função depois
bool Grafo_lista::dfsTemCiclo(int atual, int pai, bool* visitado, bool* pilhaRecursao, bool direcionado) {
    visitado[atual] = true;

    NodeVertex* noAtual = Vertice->getNodeById(atual);
    NodeEdge* arestaAtual = noAtual->getArestas()->getPrimeiro();

    while (arestaAtual != nullptr) {
        int vizinho = arestaAtual->getValue();

        
        if (!visitado[vizinho]) {
            if (dfsTemCiclo(vizinho, atual, visitado, pilhaRecursao, direcionado)) {
                return true;
            }
        } 
        
        else if (!direcionado && vizinho != pai) {
            return true; 
        }

       
        arestaAtual = (NodeEdge*) arestaAtual->getProx();
    }

    return false;
}

bool Grafo_lista::eh_bipartido() {
    int n = getOrdem();

    int totalCombinacoes = 1 << n;

    for (int mask = 0; mask < totalCombinacoes; ++mask) {
        int componenteUm[n] = {0}, componenteDois[n] = {0};
        int tamanho1 = 0, tamanho2 = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                componenteUm[tamanho1++] = i;
            } else {
                componenteDois[tamanho2++] = i;
            }
        }

        bool eValida = true;
        for (int i = 0; i < n && eValida; ++i) {
            NodeVertex* noAtual = this->Vertice->getNodeById(i);
            NodeEdge* arestaAtual = noAtual->getArestas()->getPrimeiro();

            while (arestaAtual != nullptr) {
                int vizinho = arestaAtual->getValue();

                bool noMesmoConjunto = 
                    ((mask & (1 << i)) && (mask & (1 << vizinho))) ||
                    (!(mask & (1 << i)) && !(mask & (1 << vizinho)));

                if (noMesmoConjunto) {
                    eValida = false;
                    break;
                }

                arestaAtual = (NodeEdge*)arestaAtual->getProx();
            }
        }

        if (eValida) {
            return true;
        }
    }

    return false;
}
