#ifndef LINKED_LIST_H
#define LINKED_LIST_H
using namespace std;
#include "Node.h"

template <typename NodeType>
class Linked_list
{
protected:
    NodeType* primeiro, *ultimo;

    void limpaNodes(){
        while(primeiro != NULL)
        {
            NodeType* p = primeiro;
            primeiro = static_cast<NodeType*>(primeiro->getProx());
            delete p;
        }
    };
private:
    int n;

public:
    int getTam(){return this->n;};
    
    NodeType* getNodeById(int val){
        NodeType* value = primeiro;
        if(val < 0 || val > n)
        {
            cout<<"Erro de acesso!"<<endl;
            return value;
        }
        while((value!= nullptr) && (value->getId() != val))
        {
            value = (NodeType*)value->getProx();
        }
        return value;
    };

    NodeType* getUltimo()
    {
        return this->ultimo;
    }

    NodeType* getPrimeiro()
    {
        return this->primeiro;
    }
    
    Linked_list(){
        this->primeiro = nullptr;
        this->ultimo = nullptr;
        this->n = 0;
    };

    ~Linked_list(){
        limpaNodes();
        ultimo = NULL;
    };
    
    
    void insereFinal(int val){
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
    };
    
    void imprimeLista(){
        NodeType* p = primeiro;
        while(p!=nullptr)
        {
            cout<<p->getValue()<<" ";
            p = (NodeType*)p->getProx();
        }
        cout<<endl;
    }
};

#endif