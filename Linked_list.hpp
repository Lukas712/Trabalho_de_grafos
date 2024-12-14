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
    bool ponderado;


public:
    int getTam(){return this->n;};
    NodeType* getPrimeiro(){return this->primeiro;};
    NodeType* getProx(NodeType* node){
        return node->getProx();
    }
    
    Linked_list(){
        this->primeiro = NULL;
        this->ultimo = NULL;
        this->n = 0;
        this->ponderado = false;
    };

    ~Linked_list(){
        limpaNodes();
        ultimo = NULL;
    };
    
    
    void insereFinal(int val){
        NodeType* p = new NodeType();
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
    };
    
    void imprimeLista(){
        NodeType* p = primeiro;
        while(p!=nullptr)
        {
            cout<<p->getValue()<<" ";
            p = (NodeType*)p->getProx();
        }
        delete p;
        cout<<endl;
    }
};

#endif