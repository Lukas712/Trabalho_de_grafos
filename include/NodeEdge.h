#ifndef NODEEDGE_H
#define NODEEDGE_H
#include "Node.h"

class NodeEdge : public Node
{
    
    private:
    int peso;

    public:
    NodeEdge();
    ~NodeEdge();
    /**Retorna o peso da aresta */ 
    int getPeso();
    /**Define o peso da aresta */
    void setPeso(int val);

};

#include "../src/NodeEdge.cpp"

#endif