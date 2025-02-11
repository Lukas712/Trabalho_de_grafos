#ifndef NODEEDGE_H
#define NODEEDGE_H
#include "Node.h"

class NodeEdge : public Node
{
    
    private:
    float peso;

    public:
    /**
     * @inheritDoc
     */
    NodeEdge();

    /**
     * @inheritDoc
     */
    ~NodeEdge();

    /**
     * @brief Retorna o peso da aresta
     * @return Peso
     */
    float getPeso();

    /**
     * @brief Define o peso da aresta
     * @param val Peso da aresta
     */
    void setPeso(float val);

};

#include "../src/NodeEdge.cpp"

#endif