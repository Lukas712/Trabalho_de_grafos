#ifndef NODEVERTEX_H
#define NODEVERTEX_H
#include "Node.h"
#include "Linked_list.hpp"
#include "NodeEdge.h"

class NodeVertex : public Node
{
    
    private:
    Linked_list<NodeEdge>* Arestas;

    public:
    NodeVertex() : Node(){
        Arestas = new Linked_list<NodeEdge>();
        };
    ~NodeVertex(){delete Arestas;};
    Linked_list<NodeEdge>* getArestas(){return this->Arestas;};

};

#endif