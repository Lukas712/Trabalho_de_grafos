#ifndef NODEVERTEX_H
#define NODEVERTEX_H
#include "Node.h"
#include "Linked_list.hpp"
#include "NodeEdge.h"

class NodeVertex : public Node
{
    
    private:
    /**Armazena dentro de cada nó uma lista de arestas com um nó próprio para arestas */
    Linked_list<NodeEdge>* Arestas;

    public:
    NodeVertex() : Node(){
        Arestas = new Linked_list<NodeEdge>();
        };
    ~NodeVertex(){delete Arestas;};
    /**Retorna o vetor de arestas do vértice */
    Linked_list<NodeEdge>* getArestas(){return this->Arestas;};

};

#endif