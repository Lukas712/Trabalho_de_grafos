#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

template <typename NodeType>
/**Classe template para criação do grafo por lista encadeada */
class Linked_list
{
protected:
    NodeType* primeiro, *ultimo;

    /**Função auxiliar que deleta todos os nós */
    void limpaNodes();
private:
    int n;
public:
    /**Retorna o tamanho da lista */
    int getTam();
    /**Retorna o nó correspondente ao id passado*/
    NodeType* getNodeById(int val);
    /**Retorna o ultimo nó */
    NodeType* getUltimo();
    /**Retorna o primeiro nó */
    NodeType* getPrimeiro();
    /**Construtor da Lista Encadeada */
    Linked_list();
    /**Destrutor da Lista encadeada */
    ~Linked_list();
    /**Insere nó no final da lista com peso passado como parâmetro*/
    void insereFinal(int val);
    /**Imprime a Lista encadeada */
    void imprimeLista();
    void removeNode(NodeType* no);
};

#include "Linked_list.tpp"

#endif
