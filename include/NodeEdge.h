#ifndef NODEEDGE_H
#define NODEEDGE_H
#include "Node.h"

class NodeEdge : public Node
{
    
    private:
    float peso;
    int cor;

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

    /**
     * @brief Retorna a cor do nó
     * @return Cor
     */
    int  getCor();
    /**
     * @brief Define a cor do nó
     * @param val Cor
     * @return void
     */
    void setCor(int val);

};


#endif