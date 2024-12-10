#include <iostream>
#include <fstream>
#include "Grafo_lista.h"
using namespace std;

Grafo_lista::Grafo_lista(){
    this->Vertice = NULL;
    this->ordem = NULL;
    this->grau = NULL;
    this->nCompConexo = NULL;
}
Grafo_lista::~Grafo_lista(){
    delete ordem;
    delete grau;
    delete nCompConexo;
}

int Grafo_lista::n_conexo(){
    return *nCompConexo;
}
int Grafo_lista::getGrau(){
    return *grau;
}
int Grafo_lista::getOrdem(){
    return *ordem;
}

void Grafo_lista::carregaGrafo(){

}
void Grafo_lista::novoGrafo(){

}

bool Grafo_lista::verticePonderado(){
    return this->Vertice->getPonderado();
}
bool Grafo_lista::arestaPonderada(){
    return this->Vertice->getArestas()->getPonderado();
}
bool Grafo_lista::possuiArticulacao(){}
bool Grafo_lista::possuiPonte(){}
bool Grafo_lista::eh_bipartido(){}
bool Grafo_lista::eh_direcionado(){}
bool Grafo_lista::eh_completo(){}
bool Grafo_lista::eh_arvore(){}