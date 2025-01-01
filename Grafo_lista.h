#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "GrafoAbstract.h"
#include "Linked_Vertex.h"
class Grafo_lista : public GrafoAbstract
{
    private:
        Linked_Vertex* Vertice;
        void dfsAux(int vertice, bool* visitados);
    public:
        Grafo_lista();
        ~Grafo_lista();

        bool verticePonderado();
        bool arestaPonderada();
        void insereVertice(int val);
        void insereAresta(int origem, int destino, int val);

        int getNConexo();
        int getGrau();
        int getOrdem();

        bool eh_bipartido(){return false;};
        bool eh_direcionado(){return false;};
        bool eh_completo();
        bool eh_arvore(){return false;};
        bool possuiArticulacao(){return false;};
        bool possuiPonte(){return false;};

        void imprimeGrafo();

        
};
#endif