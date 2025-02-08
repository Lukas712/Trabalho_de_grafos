#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
using namespace std;
#include "Node.h"

template <typename NodeType>
/**Classe template para criação do grafo por lista encadeada */
class Linked_list
{
protected:
    NodeType* primeiro, *ultimo;

    /**Função auxiliar que deleta todos os nós */
    void limpaNodes(){
        while(primeiro != NULL)
        {
            NodeType* p = primeiro;
            primeiro = (NodeType*)(primeiro->getProx());
            delete p;
        }
    };
private:
    int n;

public:
    /**Retorna o tamanho da lista */
    int getTam(){return this->n;};
    
    /**Retorna o nó correspondente ao id passado*/
    NodeType* getNodeById(int val){
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
    };
    /**Retorna o ultimo nó */
    NodeType* getUltimo()
    {
        return this->ultimo;
    }
    /**Retorna o primeiro nó */
    NodeType* getPrimeiro()
    {
        return this->primeiro;
    }
    /**Construtor da Lista Encadeada */
    Linked_list(){
        this->primeiro = nullptr;
        this->ultimo = nullptr;
        this->n = 0;
    };
    /**Destrutor da Lista encadeada */
    ~Linked_list(){
        limpaNodes();
        ultimo = NULL;
    };
    
    /**Insere nó no final da lista com peso passado como parâmetro*/
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
    /**Imprime a Lista encadeada */
    void imprimeLista(){
        NodeType* p = primeiro;
        while(p!=nullptr)
        {
            cout<<p->getValue()<<" ";
            p = (NodeType*)p->getProx();
        }
        cout<<endl;
    }

    void removeNode(NodeType* no)
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
};



#endif