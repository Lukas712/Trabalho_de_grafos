#include "../include/NodeEdge.h"

NodeEdge::NodeEdge() : Node(){
    this->peso = 1;
};

NodeEdge::~NodeEdge(){};

float NodeEdge::getPeso()
{
    return this->peso;
}

void NodeEdge::setPeso(float val)
{
    this->peso = val;
}