#include "../include/NodeVertex.h"

NodeVertex::NodeVertex() : Node(){
    Arestas = new Linked_list<NodeEdge>();
    this->grau = 0;
}

NodeVertex::~NodeVertex()
{
    delete Arestas;
}

Linked_list<NodeEdge>* NodeVertex::getArestas()
{
    return this->Arestas;
}
int NodeVertex::getGrau()
{
    return this->grau;
}

void NodeVertex::setGrau(int val)
{
    this->grau = val;
}