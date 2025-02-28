#include "../include/Node.h"

Node::Node() :  prox(nullptr),id(-1){}

Node::~Node(){}

Node* Node::getProx()
{
    return prox;
}

void Node::setProx(Node* prox)
{
    this->prox = prox;
}

void Node::setValue(float value)
{
    this->value = value;
}

float Node::getValue()
{
    return this->value;
}

void Node::setId(int val)
{
    this->id = val;
}

int Node::getId()
{
    return this->id;
}