#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "GrafoAbstract.h"

class Grafo_matriz : public GrafoAbstract
{
    private:
        int** matriz_adjacencia;
        int* peso_Vertice;
        int numVertices;

    public:
        Grafo_matriz();
        ~Grafo_matriz();
        
        void insereVertice(int val);
        void insereAresta(int origem, int destino, int val);
        
        int getNConexo();
        int getGrau();

        bool eh_bipartido(){return 0;};
        bool eh_completo();
        bool eh_arvore(){return 0;};
        bool possuiArticulacao(){return false;};
        bool possuiPonte(){return false;};
};
        

#endif