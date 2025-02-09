#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "GrafoAbstract.hpp"
#include "NodeEdge.h"
#include "NodeVertex.h"

class Grafo_matriz : public GrafoAbstract
{
    private:
        NodeEdge*** matriz_adjacencia;
        NodeVertex* vertices;
        int numVertices;
        int capacidade;
        /**Inicializa a matriz como matriz de adjacência ou representação linear */
        void inicializaMatriz();
        /**Incializa o peso dos vértices */
        void inicializaPesoVertices();
        /**Retorna o elemento [i][j] da matriz convertendo os índices em caso de matriz por representação linear*/
        NodeEdge** retornaCelulaMatriz(int i, int j);
        
        void resize(int novaCapacidade);

    public:
        /**Construtor da classe Grafo matriz */
        Grafo_matriz();
        /**Destrutor da classe Grafo lista */
        ~Grafo_matriz();
        /**Insere vértice com peso "val" */
        void insereVertice(int val);
        /**Insere aresta ao indicar o vértice de origem, o vértice de destino e o peso da aresta */
        void insereAresta(int origem, int destino, int val);
        /**Remove uma aresta ao passar o vértice de origem e qual o vértice que deve ser removido */
        void removeAresta(int i, int j);

        void removeVertice(int id);
        /**Calcula e retorna o número de componentes conexas do grafo */
        NodeVertex* getVertice(int id);
        NodeEdge* getAresta(int origem, int destino);
};
        

#endif