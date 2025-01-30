#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "GrafoAbstract.hpp"
#include "Linked_Vertex.h"
class Grafo_lista : public GrafoAbstract
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
        /**Calcula e retorna o número de componentes conexas do grafo */
        void removeVertice(int id){};
        NodeVertex* getVertice(int id);
        NodeEdge* getAresta(int origem, int destino);


        
};
#endif