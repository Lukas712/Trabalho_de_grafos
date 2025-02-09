#include "../include/Node.h"

Node::Node() : id(-1)
{
    Node* prox = nullptr;
    noAtivo = true;
}

Node::~Node(){}

Node* Node::getProx()
{
    return prox;
}

void Node::setProx(Node* prox)
{
    this->prox = prox;
}

void Node::setValue(int value)
{
    this->value = value;
}

int Node::getValue()
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

void Node::setAtivo(bool value)
{
    this->noAtivo = value;
}

bool Node::getAtivo()
{
    return this->noAtivo;
}