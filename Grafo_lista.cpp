#include <iostream>
#include <fstream>
#include "Grafo_lista.h"
using namespace std;

Grafo_lista::Grafo_lista(){
    // this->Vertice = NULL;
    // this->ordem = NULL;
    // this->grau = NULL;
    // this->nCompConexo = NULL;
    // this->temArticulacao = false;
}
Grafo_lista::~Grafo_lista(){
    // delete ordem;
    // delete grau;
    // delete nCompConexo;
}

int Grafo_lista::nConexo(){
    return *nCompConexo;
}
int Grafo_lista::getGrau(){
    return *grau;
}
int Grafo_lista::getOrdem(){
    return *ordem;
}

void Grafo_lista::carregaGrafo(){
    ifstream inFile;
    string linha;
    inFile.open("Descricao.txt", ios::in | ios::out);
    while(!inFile.eof())
    {
        getline(inFile, linha);
        cout<<linha<<endl;
    }
    inFile.close();
}
void Grafo_lista::novoGrafo(){
    return;
}

bool Grafo_lista::verticePonderado(){
    // return this->Vertice->getPonderado();
}
bool Grafo_lista::arestaPonderada(){
    // return this->Vertice->getArestas()->getPonderado();
}
bool Grafo_lista::possuiArticulacao(){
    return this->temArticulacao;
}
bool Grafo_lista::possuiPonte(){
    return this->temPonte;
}
bool Grafo_lista::eh_bipartido(){
    return this->grafoBipartido;
}
bool Grafo_lista::eh_direcionado(){
    return this->grafoDirecionado;
}
bool Grafo_lista::eh_completo(){
    return this->grafoCompleto;
}
bool Grafo_lista::eh_arvore(){
    return this->grafoArvore;
}