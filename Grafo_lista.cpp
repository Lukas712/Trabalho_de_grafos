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
    if(origem >=0 && origem <getOrdem() && destino>=0 && destino < getOrdem())
    {
        NodeEdge* no = this->Vertice->getNodeById(origem)->getArestas()->getPrimeiro();
        
        while(no!= nullptr && no->getValue() != destino)
        {
            no = (NodeEdge*)no->getProx();
        }
        return no;
    }
    return nullptr;
}

NodeVertex* Grafo_lista::getVertice(int id)
{
    return this->Vertice->getNodeById(id);
}

void Grafo_lista::removeAresta(int i, int j)
{
    this->Vertice->removeAresta(i, j);
}

void Grafo_lista::removeVertice(int id)
{
    id-=1;
    if(id >= 0 && id < getOrdem())
    {
        this->Vertice->removeVertice(id);
        setOrdem(getOrdem()-1);
        // for(int i =0; i< getOrdem(); i+=1)
        // {
        //     NodeVertex* no = this->Vertice->getNodeById(i);
        //     if(no!= nullptr)
        //     {
        //         cout<<no->getValue()<<endl;
        //     }
        // }
    }
    // for(int i = 0; i< getOrdem(); i+=1)
    //     {
    //         for(int j = 0; j<getOrdem(); j+=1)
    //         {
    //             if(i!= j)
    //             {
    //                 if(getAresta(i,j) != nullptr)
    //                 {
    //                     cout<<getAresta(i,j)->getValue()<<endl;
    //                     // removeAresta(i,id+1);
    //                 }
    //             }
    //         }
    //     }
     
}