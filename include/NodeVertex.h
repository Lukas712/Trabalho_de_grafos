#ifndef NODEVERTEX_H
#define NODEVERTEX_H

#include "Node.h"
#include "Linked_list.hpp"
#include "NodeEdge.h"

class NodeVertex : public Node
{
    
    private:
    Linked_list<NodeEdge>* Arestas;
    int grau;

    public:
    /**
     * @inheritDoc
     */
    NodeVertex();
    
    /**
     * @inheritDoc
     */
    ~NodeVertex();
    
    /**
     * @brief Retorna a lista de arestas do vértice
     * @return Lista encadeada de arestas
     */
    Linked_list<NodeEdge>* getArestas();

    /**
     * @brief Retorna o tamanho da lista de arestas do vértice (seu grau)
     * @return Grau do vértice
     */
    int getGrau();

    /**
     * @brief Define o grau do vértice
     * @param val Novo grau do vértice
     */
    void setGrau(int val);
};

#include "../src/NodeVertex.cpp"

#endif