#include "Linked_list.h"
#include <iostream>
#ifndef LINKED_VERTEX_H
#define LINKED_VERTEX_H
class Linked_Vertex : public Linked_list
{
private:
    Linked_list* Arestas;
public:
    Linked_Vertex() : Linked_list(){this->Arestas = NULL;};
    ~Linked_Vertex();
    Linked_list* getArestas() {return this->Arestas;};
};
#endif