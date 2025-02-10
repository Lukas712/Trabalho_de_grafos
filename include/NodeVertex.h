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
    int grau;

    public:
    NodeVertex();
    ~NodeVertex();
    /**Retorna o vetor de arestas do vértice */
    Linked_list<NodeEdge>* getArestas();
    int getGrau();
    void setGrau(int val);
};

#include "../src/NodeVertex.cpp"

#endif