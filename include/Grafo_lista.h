#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "Grafo.h"
#include "Linked_Vertex.h"
#include "NodeEdge.h"
#include "NodeVertex.h"

class Grafo_lista : public Grafo
{
    private:
        Linked_Vertex* Vertice;
    public:
        /**
         * @brief Construtor da classe Grafo lista
         * */
        Grafo_lista();
        /**
         * @brief Destrutor da classe Grafo lista 
         * */
        ~Grafo_lista();
        
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
        void removeAresta(int i, int j) override;
        
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

#include "../src/Grafo_lista.cpp"

#endif