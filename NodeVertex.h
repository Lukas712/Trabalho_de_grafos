#ifndef NODEVERTEX_H
#define NODEVERTEX_H
#include "Node.h"
#include "Linked_list.hpp"

class NodeVertex : public Node
{
    
    private:
    Linked_list<Node>* Arestas;
    static int nextID;
    int id;

    public:
    NodeVertex() : Node(), id(nextID++){Arestas = new Linked_list<Node>();};
    ~NodeVertex(){};
    Linked_list<Node>* getArestas(){return this->Arestas;};
    int getId(){return this->id;};
};
int NodeVertex::nextID = 0;

#endif