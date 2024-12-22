#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "GrafoAbstract.h"
#include "Linked_Vertex.h"
class Grafo_lista : public GrafoAbstract
{
    private:
        Linked_Vertex* Vertice;
    public:
        Grafo_lista();
        ~Grafo_lista();

        void carregaGrafo();
        void novoGrafo();

        bool verticePonderado();
        bool arestaPonderada();
        void setVerticePonderado(bool val);
        void setArestaPonderada(bool val);

        void imprimeGrafo();

        
};
#endif