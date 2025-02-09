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
        /**Construtor da classe Grafo lista */
        Grafo_lista();
        /**Destrutor da classe Grafo lista */
        ~Grafo_lista();
        /**Insere vértice com peso "val" */
        void insereVertice(int val);
        /**Insere aresta ao indicar o vértice de origem, o vértice de destino e o peso da aresta */
        void insereAresta(int origem, int destino, int val);
        /**Remove uma aresta ao passar o vértice de origem e qual o vértice que deve ser removido */
        void removeAresta(int i, int j);
        /**Calcula e retorna o númerhis->Vertice->ro de componentes conexas do grafo */
        void removeVertice(int id);
        NodeVertex* getVertice(int id);
        NodeEdge* getAresta(int origem, int destino);
};

#include "../src/Grafo_lista.cpp"

#endif