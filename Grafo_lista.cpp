#include <iostream>
#include <fstream>
#include "Grafo_lista.h"
#include <ctime>
#include <cstdlib>
using namespace std;

Grafo_lista::Grafo_lista(){
    this->Vertice = new Linked_Vertex();
    this->setGrau(0);
    this->setArestaPonderada(false);
    this->setArticulacao(false);
    this->setArvore(false);
    this->setBipartido(false);
    this->setDirecionado(false);
    this->setCompleto(false);
    this->setArvore(false);
    this->setArticulacao(false);
    this->setPonte(false);
    this->setNConexo(0);
}
Grafo_lista::~Grafo_lista(){
    delete Vertice;
}

bool Grafo_lista::verticePonderado(){
    return this->Vertice->getVerticePonderado();
}
bool Grafo_lista::arestaPonderada(){
    return this->Vertice->getArestaPonderada();
}

void Grafo_lista::setArestaPonderada(bool val)
{
    this->Vertice->setArestaPonderada(val);
}

void Grafo_lista::setVerticePonderado(bool val)
{
    this->Vertice->setVerticePonderado(val);
}

void Grafo_lista::imprimeGrafo()
{
    cout<<"grafo.txt"<<endl;
    cout<<endl;
    cout<<"Grau: "<<getGrau()<<endl;
    cout<<"Ordem: "<<getOrdem()<<endl;
    cout<<"Direcionado: "<<eh_direcionado()<<endl;
    cout<<"Componentes conexas: "<<getNConexo()<<endl;
    cout<<"Vertices ponderados: "<<verticePonderado()<<endl;
    cout<<"Arestas ponderadas: "<<arestaPonderada()<<endl;
    cout<<"Completo: "<<eh_completo()<<endl;
    cout<<"Bipartido: "<<eh_bipartido()<<endl;
    cout<<"Arvore: "<<eh_arvore()<<endl;
    cout<<"Aresta Ponte: "<<possuiPonte()<<endl;
    cout<<"Vertice Articulação: "<<possuiArticulacao()<<endl;
}