#include "../include/NodeVertex.h"

NodeVertex::NodeVertex() : Node(){
    Arestas = new Linked_list<NodeEdge>();
}

NodeVertex::~NodeVertex()
{
    delete Arestas;
}

Linked_list<NodeEdge>* NodeVertex::getArestas()
{
    return this->Arestas;
}