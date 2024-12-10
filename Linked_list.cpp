#include "Linked_list.h"
#include<iostream>
using namespace std;

Linked_list::Linked_list()
{
    this->primeiro = NULL;
    this->ultimo = NULL;
    this->n = 0;
    this->ponderado = false;
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

bool Linked_list::getPonderado()
{
    return this->ponderado;
}

void Linked_list::setPonderado(bool val)
{
    this->ponderado = val;
}

