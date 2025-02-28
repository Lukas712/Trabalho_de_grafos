#include "../include/Linked_Vertex.h"
#include "../include/NodeEdge.h"
#include "../include/NodeVertex.h"
#include <iostream>
using namespace std;

Linked_Vertex::Linked_Vertex() : Linked_list(){};

Linked_Vertex::~Linked_Vertex()
{
    this->limpaNodes();
}

void Linked_Vertex::insereAresta(int origem, int destino, float val)
{
    NodeVertex* noOrigem = getNodeById(origem-1);
    Linked_list<NodeEdge>* arestas = noOrigem->getArestas();
    arestas->insereFinal(destino-1);
    arestas->getUltimo()->setPeso(val);
};

void Linked_Vertex::removeAresta(int i, int j)
{
    NodeVertex* no = getNodeById(i-1);
    Linked_list<NodeEdge>* arestas = no->getArestas();
    NodeEdge* noAresta = (NodeEdge*)arestas->getPrimeiro();
    while(noAresta != nullptr && noAresta->getValue() != j-1)
    {
        noAresta = (NodeEdge*)noAresta->getProx();
    }
    arestas->removeNode(noAresta);
    cout<<"Removendo a aresta ("<< i<<","<<j<<")"<<endl;
    
}

void Linked_Vertex::removeVertice(int id) {
    NodeVertex* no = getNodeById(id);
    if (no == nullptr){
        return;
    }

    NodeVertex* current = getPrimeiro();
    while (current != nullptr) {
        Linked_list<NodeEdge>* arestas = current->getArestas();
        NodeEdge* edge = arestas->getPrimeiro();
        while (edge != nullptr) {
            if (edge->getValue() == id) {
                NodeEdge* auxEdge = edge;
                edge = (NodeEdge*)edge->getProx();
                arestas->removeNode(auxEdge);
                current->setGrau(current->getGrau()-1);
            }
            else if(edge->getValue() > id)
            {
                edge->setValue(edge->getValue()-1);
                edge->setId(edge->getId()-1);
                edge = (NodeEdge*)edge->getProx();
            }
            else
            {
                edge = (NodeEdge*)edge->getProx();
            }
        }
        current = (NodeVertex*)current->getProx();
    }

    removeNode(no);
    cout<<"Removendo o vértice: "<<id+1<<endl;
    
    NodeVertex* p = getPrimeiro();
    int newId = 0;
    while (p != nullptr) {
        p->setId(newId++);
        p = (NodeVertex*)p->getProx();
    }
}