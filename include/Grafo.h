#ifndef GRAFO_H
#define GRAFO_H
#include "NodeVertex.h"
#include "NodeEdge.h"


class Grafo
{   
    private:
        int ordem = 0;
        bool direcionado, verticePeso, arestaPeso;
        
        /**
         * @brief Retorna sim ou não dependendo da expressão booleana
         * @param valor Resultado booleano
         * @return String "Sim" ou "Não"
         */
        string imprmeSimNao(bool valor);
        
        /**
         * @brief Retorna uma string contendo o maior peso dentre todas as menores distâncias entre dois pontos
         * @return String com maior menor distância
         */
        string retornaMaiorMenorDistancia();
    
    public:

    virtual ~Grafo() = default;
    /**
     * @brief Retorna o nó caso exista do id desejado
     * @param id ID do nó deslocado uma unidade
     * @return Retorna o nó caso exista
     */
    virtual NodeVertex* getVertice(int id) = 0;
    
    /**
     * @brief Retorna a aresta caso exista
     * @param origem Indica o nó de origem na aresta (origem começa em zero)
     * @param destino Indica o nó de destino na aresta (destino começa em zero)
     * @return Retorna a aresta caso exista
     */
    virtual NodeEdge* getAresta(int origem, int destino) = 0;
    
    /**
     * @brief Insere um vértice com peso e o coloca em último
     * @param val Valor a ser inserido no vértice
     */
    virtual void insereVertice(float val) = 0;
    
    /**
     * @brief Insere uma aresta entre dois nós com peso e o coloca em último caso não exista no mesmo ponto
     * @param origem Indica o nó onde a aresta vai ser colocada
     * @param destino Indica o nó ao qual estará ligado
     * @param val Valor a ser inserido na aresta
     */
    virtual void insereAresta(int origem, int destino, float val) = 0;
    
    /**
     * @brief Remove o vértice com o id-1 passado como parâmetro
     * @param id Indica o nó que será removido (O id sempre é uma unidade a mais)
     */
    virtual void removeVertice(int id) = 0;
    
    /**
     * @brief Remove a aresta caso exista
     * @param origem Indica o nó de origem (origem começa em 1)
     * @param destino Indica o nó de destino (destino começa em 1)
     */
    virtual void removeAresta(int origem, int destino) = 0;
    
    /**
     * @brief Retorna se o grafo é direcionado ou não
     * @return Verdadeiro ou falso
     */
    bool eh_direcionado();
    
    /**
     * @brief Retorna se os vértices do grafo são ponderados ou não
     * @return Verdadeiro ou falso
     */
    bool verticePonderado();
    
    /**
     * @brief Retorna se as arestas do grafo são ponderadas ou não
     * @return Verdadeiro ou falso
     */
    bool arestaPonderada();
    
    /**
     * @brief Retorna a ordem do grafo
     * @return Inteiro representado pela ordem
     */
    int getOrdem();
    
    /**
     * @brief Define a ordem do grafo
     * @param val Valor que será definido para a ordem do grafo
     */
    void setOrdem(int val);
    
    /**
     * @brief Define se o grafo é direcionado ou não
     * @param val Valor que será definido para o direcionamento do grafo
     */
    void setDirecionado(bool val);
    
    /**
     * @brief Define se o grafo possui vértices ponderados
     * @param val Valor que será definido para os vértices ponderados
     */
    void setVerticePonderado(bool val);
    
    /**
     * @brief Define se o grafo possui arestas ponderadas
     * @param val Valor que será definido para as arestas ponderadas
     */
    void setArestaPonderada(bool val);
    
    /**
     * @brief Retorna o grau do grafo
     * @return Inteiro representado pelo grau
     */
    int getGrau();
    
    /**
     * @brief Retorna se o grafo é completo
     * @return booleano representando se é ou não completo
     */
    bool eh_completo();
    
    /**
     * @brief Carrega o grafo na estrutura
     * @param grafo String que representa o nome do arquivo à ser carregado
     */
    void carregaGrafo(string grafo);
    
    /**
     * @brief Imprime o grafo de acordo com a descrição do trabalho
     */
    void imprimeGrafo();
    
    /**
     * @brief Calcula a menor distância entre dois pontos utilizando o algoritmo de Dijkstra
     * @param ponto1 Nó de origem
     * @param ponto2 Nó de destino
     * @return Menor distância entre dois pontos
     */
    float maiorMenorDistancia(int ponto1, int ponto2);
    
};

#include "../src/Grafo.cpp"

#endif