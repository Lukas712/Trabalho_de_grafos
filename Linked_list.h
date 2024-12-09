#include "Node.h"

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
class Linked_list
{
private:
    Node* primeiro, *ultimo;
    int n;
    void limpaNodes(Node* prox);
    bool ponderado; 
public:
    Linked_list();
    ~Linked_list();
    void insereFinal(int val);
    bool getPonderado();
    void setPonderado(bool val);
};

#endif