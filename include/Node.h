#ifndef NODE_H
#define NODE_H

class Node
{
private:
    float value;
    Node* prox;
    int id;
    
public:
    /**Construtor da classe Node */
    Node();
    /**Destrutor da classe Node */
    ~Node();
    Node* getProx();
    void setProx(Node* prox);
    
    void setValue(float value);
    float getValue();
    
    void setId(int val);
    int getId();
};

#include "../src/Node.cpp"

#endif