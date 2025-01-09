#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "GrafoAbstract.hpp"
#include "Linked_Vertex.h"
class Grafo_lista : public GrafoAbstract
{
    private:
        Linked_Vertex* Vertice;
        /**Verifica e retorna a existência de ciclos no grafo */
        bool temCiclo(int v, int visitado[], int pai);
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
        int getNConexo();
        /**Calcula e retorna o grau do grafo */
        int getGrau();
        /**Verifica e retorna se o grafo é bipartido utilizando de coloração de vértices para determinar */
        bool eh_bipartido();
        /**Verifica e retorna se o grafo é completo*/
        bool eh_completo();
        /**Verifica e retorna se o grafo é uma árvore */
        bool eh_arvore();
        /**Verifica e retorna se o grafo possui ao menos uma articulação ou não */
        bool possuiArticulacao();
        /**Verifica e retorna se o grafo possui ao menos uma ponte ou não */
        bool possuiPonte();


        
};
#endif