#ifndef NODEEDGE_H
#define NODEEDGE_H
#include "Node.h"

class NodeEdge : public Node
{
    
    private:
    float peso;

    public:
    NodeEdge();
    ~NodeEdge();
    /**Retorna o peso da aresta */ 
    float getPeso();
    /**Define o peso da aresta */
    void setPeso(float val);

};

#include "../src/NodeEdge.cpp"

#endif