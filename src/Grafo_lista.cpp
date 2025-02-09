#include <iostream>
#include "../include/Grafo_lista.h"

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
    setOrdem(getOrdem()+1);
}


void Grafo_lista::insereAresta(int origem, int destino, int val)
{
    if(getAresta(origem-1,destino-1) == nullptr)
    {
        this->Vertice->insereAresta(origem, destino, val);
    }
    else
    {
        cout<<"Aresta entre: "<<origem<<" e "<<destino<<" já existe"<<endl;
    }
}

NodeEdge* Grafo_lista::getAresta(int origem, int destino)
{
    NodeEdge* no = this->Vertice->getNodeById(origem)->getArestas()->getPrimeiro();
    if(origem >=0 && origem <getOrdem() && destino>=0 && destino < getOrdem())
    {        
        while(no!= nullptr && no->getValue() != destino)
        {
            no = (NodeEdge*)no->getProx();
        }
    }
    return no;
}

NodeVertex* Grafo_lista::getVertice(int id)
{
    return this->Vertice->getNodeById(id);
}

void Grafo_lista::removeAresta(int i, int j)
{
    if(i >= 1 && i <=this->getOrdem() && j>=1 && j <=this->getOrdem())
    {
        this->Vertice->removeAresta(i, j);
    }
    else
    {
        cout<<"Não é possível remover o nó"<<endl;
    }
}

void Grafo_lista::removeVertice(int id)
{
    if(id >= 1 && id <= getOrdem())
    {
        id-=1;
        if(id >= 0 && id < getOrdem())
        {
            this->Vertice->removeVertice(id);
            setOrdem(getOrdem()-1);
        }
    }
    else
    {
        cout<<"Não é possível remover o vértice"<<endl;
    }
}

