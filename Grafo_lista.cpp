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

void Grafo_lista::insereVertice(int val)
{
    this->Vertice->insereFinal(val);
}

void Grafo_lista::insereAresta(int origem, int destino, int val)
{
    this->Vertice->insereAresta(origem, destino, val);
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
    cout<<this->getOrdem()<<" "<<this->eh_direcionado()<<" "<< this->verticePonderado()<<" "<<this->arestaPonderada()<<endl;
    for(int i= 0; i<this->getOrdem(); i+=1)
    {
        cout<<this->Vertice->getNodeById(i)->getValue()<<" ";
    }
    cout<<endl;
    for(int i = 0; i<this->Vertice->getTam();i+=1)
    {
        NodeVertex* noBase = this->Vertice->getNodeById(i);
        NodeEdge* ultimo = noBase->getArestas()->getUltimo();
        // if(ultimo != nullptr)
        // {
        // cout<<noBase->getArestas()-><<endl;

        // }
        for(int j = 0; j<this->Vertice->getNodeById(i)->getArestas()->getTam();j+=1)
        {
            // cout<<noBase->getId() << " "<<noBase->getArestas()->getNodeById(j)->getValue()<<" "<<noBase->getArestas()->getNodeById(j)->getPeso()<<endl;
        }
    }
}