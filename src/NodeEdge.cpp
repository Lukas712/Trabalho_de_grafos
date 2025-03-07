#include "../include/NodeEdge.h"

NodeEdge::NodeEdge() : Node(){
    this->peso = 1;
    this->cor = -1;
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

void NodeEdge::setCor(int val)
{
    this->cor = val;
}

int NodeEdge::getCor()
{
    return this->cor;
}