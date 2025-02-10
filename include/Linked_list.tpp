#include <iostream>
#include "Linked_list.hpp"

using namespace std;

template<typename NodeType>
int Linked_list<NodeType>::getTam(){
        return this->n;
}
    
template<typename NodeType>
NodeType* Linked_list<NodeType>::getNodeById(int val){
    NodeType* value = primeiro;
    if(val < 0 || val > n)
    {
        return value;
    }
    while((value!= nullptr) && (value->getId() != val))
    {
        value = (NodeType*)value->getProx();
    }
    return value;
}

template<typename NodeType>
NodeType* Linked_list<NodeType>::getUltimo()
{
    return this->ultimo;
}

template<typename NodeType>
NodeType* Linked_list<NodeType>::getPrimeiro()
{
    return this->primeiro;
}

template<typename NodeType>
Linked_list<NodeType>::Linked_list(){
    this->primeiro = nullptr;
    this->ultimo = nullptr;
    this->n = 0;
}

template<typename NodeType>
Linked_list<NodeType>::~Linked_list(){
    limpaNodes();
    ultimo = NULL;
}
    
template<typename NodeType>
void Linked_list<NodeType>::insereFinal(float val){
    NodeType* p = new NodeType();
    p->setValue(val);
    p->setProx(nullptr);
    p->setId(n);

    if(ultimo!=nullptr)
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

template<typename NodeType>
void Linked_list<NodeType>::imprimeLista(){
    NodeType* p = primeiro;
    while(p!=nullptr)
    {
        cout<<p->getValue()<<" ";
        p = (NodeType*)p->getProx();
    }
    cout<<endl;
}

template<typename NodeType>
void Linked_list<NodeType>::removeNode(NodeType* no)
{
    NodeType* aux;
    if(primeiro != nullptr && primeiro == no)
    {
        aux = primeiro;
        primeiro = (NodeType*)primeiro->getProx();
        
        if(primeiro == nullptr)
        {
            ultimo = nullptr;
        }
        delete aux;
        n-=1;
        return;
    }
    NodeType* p = primeiro;
    while(p != nullptr && (NodeType*)p->getProx() != no)
    {
        p = (NodeType*)p->getProx();
    }

    if(p == nullptr)
    {
        cout<<"Remoção inválida!"<<endl;
        return;
    }

    aux = nullptr;
    if((NodeType*)p->getProx() == ultimo)
    {
        aux = ultimo;
        delete aux;
        p->setProx(nullptr);
        ultimo = p;
    }
    else
    {
        aux = (NodeType*)p->getProx();
        p->setProx((NodeType*)aux->getProx());
        delete aux;
    }
    this->n-=1;
}

template<typename NodeType>
void Linked_list<NodeType>::limpaNodes(){
    while(primeiro != NULL)
    {
        NodeType* p = primeiro;
        primeiro = (NodeType*)(primeiro->getProx());
        delete p;
    }
}