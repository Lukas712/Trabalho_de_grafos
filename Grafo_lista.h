#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "GrafoAbstract.hpp"
#include "Linked_Vertex.h"
class Grafo_lista : public GrafoAbstract
{
    private:
        Linked_Vertex* Vertice;
        bool temCiclo(int v, int visitado[], int pai);
        bool bfsBipartido(int inicio, int* cor);
    public:
        Grafo_lista();
        ~Grafo_lista();

        void insereVertice(int val);
        void insereAresta(int origem, int destino, int val);

        int getNConexo();
        int getGrau();

        bool eh_bipartido();
        bool eh_completo();
        bool eh_arvore();
        bool possuiArticulacao();
        bool possuiPonte();

};
#endif