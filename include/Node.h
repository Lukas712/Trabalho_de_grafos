#ifndef NODE_H
#define NODE_H

class Node
{
private:
    float value;
    Node* prox;
    int id;
    
public:
    /**
     * @brief Construtor da classe
     */
    Node();

    /** 
     * @brief Destrutor da classe
     * */
    ~Node();

    /**
     * @brief Retorna o próximo nó
     * @return Próximo nó
     */
    Node* getProx();

    /**
     * @brief Define o próximo nó
     * @param prox Nó que será inserido como próximo nó
     */
    void setProx(Node* prox);
    
    /**
     * @brief Define o valor do nó
     * @param value valor do nó
     */
    void setValue(float value);

    /**
     * @brief Retorna o valor do nó
     * @return Valor do nó
     */
    float getValue();
    
    /**
     * @brief Define o id do nó
     * @param val Id do nó
     */
    void setId(int val);

    /**
     * @brief Retorna o id do nó
     * @return ID do nó
     */
    int getId();
};

#include "../src/Node.cpp"

#endif