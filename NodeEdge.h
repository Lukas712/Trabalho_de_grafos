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
    int getPeso(){return this->peso;};
    void setPeso(int val){this->peso = val;};

};

#endif