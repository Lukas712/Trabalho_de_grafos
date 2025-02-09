#include "../include/NodeEdge.h"

NodeEdge::NodeEdge() : Node(){};

NodeEdge::~NodeEdge(){};

int NodeEdge::getPeso()
{
    return this->peso;
}

void NodeEdge::setPeso(int val)
{
    this->peso = val;
}