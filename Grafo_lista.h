#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "GrafoAbstract.h"
#include "Linked_Vertex.h"
class Grafo_lista : public GrafoAbstract
{
    private:
        Linked_Vertex* Vertice;
        int* ordem;
        int* grau;
        int* nCompConexo;
        bool temArticulacao;
        bool temPonte;
        bool grafoBipartido;
        bool grafoCompleto;
        bool grafoDirecionado;
        bool grafoArvore;
    public:
        Grafo_lista();
        ~Grafo_lista();
        int nConexo();
        int getGrau();
        int getOrdem();

        void carregaGrafo();
        void novoGrafo();

        bool verticePonderado();
        bool arestaPonderada();
        bool eh_bipartido();
        bool eh_direcionado();
        bool eh_completo();
        bool eh_arvore();
        bool possuiArticulacao();
        bool possuiPonte();
};
#endif