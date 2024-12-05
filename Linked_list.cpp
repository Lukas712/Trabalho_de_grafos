#include "Linked_list.h"
#include<iostream>
using namespace std;

Linked_list::Linked_list()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

Linked_list::~Linked_list()
{
    limpaNodes(primeiro);
    ultimo = NULL;
}

void Linked_list::limpaNodes(Node* prox)
{
    if(primeiro != NULL)
    {
        Node* p = new Node();
        p = primeiro;
        primeiro->setProx(primeiro->getProx());
        delete p;
        limpaNodes(primeiro);
    }
}

void Linked_list::insereFinal(int val)
{
    Node* p = new Node();
    p->setValue(val);
    p->setProx(NULL);

    if(ultimo!=NULL)
    {
        ultimo->setProx(p);
    }
    else
    {
        primeiro = p;
    }
    ultimo = p;
    n+=1;
}

