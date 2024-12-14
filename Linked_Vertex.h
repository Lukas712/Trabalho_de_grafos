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
        NodeVertex* getNodeById(int val){
            NodeVertex* value = primeiro;
            while((value->getId() != val) && (value!= nullptr))
            {
                value = (NodeVertex*)value->getProx();
            }
            return value;
        };
};
#endif