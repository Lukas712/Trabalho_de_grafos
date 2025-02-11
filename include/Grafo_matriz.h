#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "Grafo.h"
#include "NodeEdge.h"
#include "NodeVertex.h"

class Grafo_matriz : public Grafo
{
    private:
        NodeEdge*** matriz_adjacencia;
        NodeVertex* vertices;
        int numVertices;
        int capacidade;
        
        /**
         * @brief Inicializa a matriz com tamanho inicial 10 como matriz de adjacência ou representação por matriz triangular caso seja não direcionada
         */
        void inicializaMatriz();

        /**
         * @brief Inicializa os vértices com tamanho inicial 10 
        */
        void inicializaPesoVertices();
        
        /**
         * @brief Retorna o elemento correto na matriz, independente do tipo de representação
         * @param i Índice da linha da matriz (começa em zero)
         * @param j Índice da coluna da matriz (começa em zero)
         * @return Elemento da posição [i][j] da matriz
        */
        NodeEdge** retornaCelulaMatriz(int i, int j);
        
        /**
         * @brief Realoca a matriz e os vértices com tamanho dobrado
         * @param novaCapacidade Define a nova capacidade que a matriz vai ter
         */
        void resize(int novaCapacidade);

    public:
        
        /**
         * @brief Construtor da classe matriz
         */
        Grafo_matriz();
        
        /**
         * @brief Destrutor da classe matriz
         */
        ~Grafo_matriz();
        
        /**
         * @inheritDoc
         */
        void insereVertice(float val) override;
        
        /**
         * @inheritDoc
         */
        void insereAresta(int origem, int destino, float val) override;
        
        /**
         * @inheritDoc
         */
        void removeAresta(int origem, int destino) override;
        
        /**
         * @inheritDoc
         */
        void removeVertice(int id) override;
        
        /**
         * @inheritDoc
         */
        NodeVertex* getVertice(int id) override;
        
        /**
         * @inheritDoc
         */
        NodeEdge* getAresta(int origem, int destino) override;
};
        
#include "../src/Grafo_matriz.cpp"

#endif