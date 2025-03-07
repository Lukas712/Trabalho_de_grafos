#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP


/**
* @brief Classe template para criação do grafo por lista encadeada
* 
* @tparam NodeType Tipo de nó que será utilizado
*/
template <typename NodeType>
class Linked_list
{
protected:
    NodeType* primeiro, *ultimo;

    /**
    * @brief Função auxiliar que deleta todos os nós 
    */
    void limpaNodes();
private:
    int n;
public:
    /**
     * @brief Construtor da Lista Encadeada
     * */
    Linked_list();
    /**
     * @brief Destrutor da Lista encadeada
     * */
    ~Linked_list();
    
    /**
     * @brief Retorna o tamanho da lista 
     * @return Tamanho da lista
     * */
    int getTam();
    
    /**
     * @brief Retorna o nó correspondente ao id passado
     * @param val Representa o id do nó a ser passado
     * */
    NodeType* getNodeById(int val);
    
    /**
    * @brief Retorna o ultimo nó
    * @return Último nó
    */
    NodeType* getUltimo();

    /**
     * @brief Retorna o primeiro nó
     * @return Primeiro nó
     * */
    NodeType* getPrimeiro();

    /**
     * @brief Insere nó no final da lista
     * @param val Valor a ser inserido no nó
     * */
    void insereFinal(float val);

    /**
     * @brief Imprime a Lista encadeada
     * */
    void imprimeLista();

    /**
     * @brief Remove o nó passado como parâmetro da lista
     * @param no Nó a ser removido
     */
    void removeNode(NodeType* no);
};

#include "Linked_list.tpp"

#endif
