#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int value;
    Node* prox;
    int id;
    bool noAtivo;
    
public:
    /**Construtor da classe Node */
    Node();
    /**Destrutor da classe Node */
    ~Node();
    Node* getProx();
    void setProx(Node* prox);
    
    void setValue(int value);
    int getValue();
    

    void setId(int val);
    int getId();
    
    void setAtivo(bool value);
    bool getAtivo();
};

#include "../src/Node.cpp"

#endif