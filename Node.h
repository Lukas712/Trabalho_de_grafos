#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int value;
    Node* prox;

public:
    Node();
    ~Node();
    Node* getProx(){return prox;};
    void setProx(Node* prox){this->prox = prox;};
    
    void setValue(int value){this->value = value;}
    int getValue(){return this->value;};

};

#endif