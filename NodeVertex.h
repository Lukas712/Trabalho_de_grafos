#ifndef NODEVERTEX_H
#define NODEVERTEX_H
#include "Node.h"
#include "Linked_list.hpp"

class NodeVertex : public Node
{
    
    private:
    Linked_list<Node>* Arestas;

    public:
    NodeVertex() : Node(){Arestas = new Linked_list<Node>();};
    ~NodeVertex(){delete Arestas;};
    Linked_list<Node>* getArestas(){return this->Arestas;};

};


#endif