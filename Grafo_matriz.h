#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "GrafoAbstract.hpp"

class Grafo_matriz : public GrafoAbstract
{
    private:
        int** matriz_adjacencia;
        int* peso_Vertice;
        int numVertices;
        /**Inicializa a matriz como matriz de adjacência ou representação linear */
        void inicializaMatriz();
        /**Incializa o peso dos vértices */
        void inicializaPesoVertices();
        /**Retorna o elemento [i][j] da matriz convertendo os índices em caso de matriz por representação linear*/
        int* retornaCelulaMatriz(int i, int j);
        /**Verifica e retorna a existência de ciclos no grafo */
        bool temCiclo(int v, int visitado[], int pai);

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