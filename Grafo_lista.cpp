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

NodeEdge* Grafo_lista::getAresta(int origem, int destino)
{
    NodeEdge* no = this->Vertice->getNodeById(origem)->getArestas()->getPrimeiro();
    while(no->getValue() != destino && no->getProx() != nullptr)
    {
        no = (NodeEdge*)no->getProx();
    }
    if(no->getValue() != destino)
    {
        return nullptr;
    }
    return no;
}

NodeVertex* Grafo_lista::getVertice(int id)
{
    return this->Vertice->getNodeById(id);
}