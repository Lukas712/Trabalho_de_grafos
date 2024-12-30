#ifndef LINKED_VERTEX_H
#define LINKED_VERTEX_H

#include <iostream>
#include "Linked_list.hpp"
#include "NodeVertex.h"
class Linked_Vertex : public Linked_list<NodeVertex>
{
    private:
        bool arestaPonderada;
        bool verticePonderado;
    public:
        Linked_Vertex() : Linked_list(){};
        ~Linked_Vertex(){
            this->limpaNodes();
            ultimo = NULL;
            };
        bool getArestaPonderada() { return this->arestaPonderada;};
        void setArestaPonderada(bool val){this->arestaPonderada = val;};
        bool getVerticePonderado(){return this->verticePonderado;};
        void setVerticePonderado(bool val){this->verticePonderado = val;};
        void insereAresta(int origem, int destino, int val)
        {
            // cout<<origem<<" "<<destino<<" "<<val<<endl;
            NodeVertex* noOrigem = getNodeById(origem-1);
            noOrigem->getArestas()->insereFinal(destino-1);
            noOrigem->getArestas()->getUltimo()->setPeso(val);
            cout<<noOrigem->getArestas()<<endl;
        };
};
#endif