#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int value;
    Node* prox;
    int id;
    
public:
    Node() : id(-1){Node* prox = NULL;};
    ~Node(){};
    Node* getProx(){return prox;};
    void setProx(Node* prox){this->prox = prox;};
    
    void setValue(int value){this->value = value;}
    int getValue(){return this->value;};

    void setId(int val){this->id = val;};
    int getId(){return this->id;};
};


#endif