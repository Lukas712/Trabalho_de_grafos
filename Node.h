#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int value;
    Node* prox;
    static int nextID;
    int id;

public:
    Node() : id(nextID++){Node* prox = NULL;};
    ~Node(){};
    Node* getProx(){return prox;};
    void setProx(Node* prox){this->prox = prox;};
    
    void setValue(int value){this->value = value;}
    int getValue(){return this->value;};

    int getId(){return this->id;};
};
int Node::nextID = 0;


#endif