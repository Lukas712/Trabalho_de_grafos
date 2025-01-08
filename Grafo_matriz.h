#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "GrafoAbstract.hpp"

class Grafo_matriz : public GrafoAbstract
{
    private:
        int** matriz_adjacencia;
        int* peso_Vertice;
        int numVertices;
        void inicializaMatriz();
        void inicializaPesoVertices();
        int* retornaCelulaMatriz(int i, int j);
        void encontrarComponentesConexas();
        bool temCiclo(int v, int visitado[], int pai);

    public:
        Grafo_matriz();
        ~Grafo_matriz();
        
        void insereVertice(int val);
        void insereAresta(int origem, int destino, int val);
        
        int getNConexo();
        int getGrau();

        bool eh_bipartido();
        bool eh_completo();
        bool eh_arvore();
        bool possuiArticulacao();
        bool possuiPonte();
        // void insereArestaAleatoria(int i, int j, int peso);
};
        

#endif