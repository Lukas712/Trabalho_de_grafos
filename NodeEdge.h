#ifndef NODEEDGE_H
#define NODEEDGE_H
#include "Node.h"

class NodeEdge : public Node
{
    
    private:
    int peso;

    public:
    NodeEdge() : Node(){
        
    };
    ~NodeEdge(){};
    /**Retorna o peso da aresta */ 
    int getPeso(){return this->peso;};
    /**Define o peso da aresta */
    void setPeso(int val){this->peso = val;};

};

#endif