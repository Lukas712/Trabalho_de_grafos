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

bool Grafo_lista::verticePonderado(){
    return this->Vertice->getVerticePonderado();
}
bool Grafo_lista::arestaPonderada(){
    return this->Vertice->getArestaPonderada();
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
    for(int i= 0; i<this->Vertice->getTam(); i+=1)
    {
        NodeVertex* no = this->Vertice->getNodeById(i);
        if(maior < no->getArestas()->getTam())
        {
            maior = no->getArestas()->getTam();
        } 
    }
    return maior;
}

int Grafo_lista::getOrdem()
{
    return this->Vertice->getTam();
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

    for (int i = 0; i < this->Vertice->getTam(); i++) {
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
    int numVertices = this->Vertice->getTam();
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
    for(int i = 0; i < this->Vertice->getTam(); i+=1)
    {
        NodeVertex* no = this->Vertice->getNodeById(i);
        if(no->getArestas()->getTam() != this->Vertice->getTam()-1)
        {
            return false;
        }
    }
    return true;
}


void Grafo_lista::imprimeGrafo()
{
    cout<<"grafo.txt"<<endl;
    cout<<endl;
    cout<<"Grau: "<<getGrau()<<endl;
    cout<<"Ordem: "<<getOrdem()<<endl;
    cout<<"Direcionado: "<<eh_direcionado()<<endl;
    cout<<"Componentes conexas: "<<getNConexo()<<endl;
    cout<<"Vertices ponderados: "<<verticePonderado()<<endl;
    cout<<"Arestas ponderadas: "<<arestaPonderada()<<endl;
    cout<<"Completo: "<<eh_completo()<<endl;
    cout<<"Bipartido: "<<eh_bipartido()<<endl;
    cout<<"Arvore: "<<eh_arvore()<<endl;
    cout<<"Aresta Ponte: "<<possuiPonte()<<endl;
    cout<<"Vertice Articulação: "<<possuiArticulacao()<<endl;
}