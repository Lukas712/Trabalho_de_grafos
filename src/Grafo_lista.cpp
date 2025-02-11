#include <iostream>
#include "../include/Grafo_lista.h"

using namespace std;

Grafo_lista::Grafo_lista(){
    this->Vertice = new Linked_Vertex();
}

Grafo_lista::~Grafo_lista(){
    delete Vertice;
}


void Grafo_lista::insereVertice(float val)
{
    this->Vertice->insereFinal(val);
    setOrdem(getOrdem()+1);
}


void Grafo_lista::insereAresta(int origem, int destino, float val)
{
    if(origem >=1 && origem <= getOrdem() && destino >=1 && destino <= getOrdem())
    {
        if(getAresta(origem-1,destino-1) == nullptr)
        {
            this->Vertice->insereAresta(origem, destino, val);
            NodeVertex* no = this->Vertice->getNodeById(origem-1);
            no->setGrau(no->getGrau()+1);
            if(!eh_direcionado())
            {
                this->Vertice->insereAresta(destino, origem, val);
                NodeVertex* noVolta = this->Vertice->getNodeById(destino-1);
                noVolta->setGrau(noVolta->getGrau()+1);
            }
        }
        else
        {
            cout<<"Aresta entre: "<<origem<<" e "<<destino<<" já existe"<<endl;
        }
    }
    else
    {
        cout<<"Aresta inválida!"<<endl;
    }
}

NodeEdge* Grafo_lista::getAresta(int origem, int destino)
{
    if(origem >=0 && origem <getOrdem() && destino>=0 && destino < getOrdem())
    {        
        NodeEdge* no = this->Vertice->getNodeById(origem)->getArestas()->getPrimeiro();
        if(no != nullptr)
        {
            while(no!= nullptr && no->getValue() != destino)
            {
                no = (NodeEdge*)no->getProx();
            }
            return no;
        }
    }
    return nullptr;
}

NodeVertex* Grafo_lista::getVertice(int id)
{
    return this->Vertice->getNodeById(id);
}

void Grafo_lista::removeAresta(int i, int j)
{
    if(i >= 1 && i <=getOrdem() && j>=1 && j <=getOrdem())
    {
        if(getAresta(i-1,j-1) != nullptr)
        {
            this->Vertice->removeAresta(i, j);
            NodeVertex* no = this->Vertice->getNodeById(i-1);
            no->setGrau(no->getGrau()-1);
            if(!eh_direcionado())
            {
                this->Vertice->removeAresta(j, i);
                NodeVertex* noVolta = this->Vertice->getNodeById(j);
                noVolta->setGrau(noVolta->getGrau()-1);
            }
        }
        else
        {
            cout<<"Nó inexistente!"<<endl;
        }
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