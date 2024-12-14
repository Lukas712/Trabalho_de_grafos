#include <iostream>
#include <fstream>
#include "Grafo_lista.h"
#include <ctime>
#include <cstdlib>
using namespace std;

Grafo_lista::Grafo_lista(){
    this->Vertice = new Linked_Vertex();
}
Grafo_lista::~Grafo_lista(){
    delete Vertice;
}



void Grafo_lista::carregaGrafo(){
    ifstream inFile;
    string linha;
    inFile.open("Descricao.txt", ios::in | ios::out);
    if(getline(inFile, linha))
    {
        this->setGrau(stoi(linha));
    }
    if(getline(inFile, linha))
    {
        this->setOrdem(stoi(linha));
    }
    if(getline(inFile, linha))
    {
        this->setDirecionado(stoi(linha));
    }
    if(getline(inFile, linha))
    {
        this->setNConexo(stoi(linha));
    }
    if(getline(inFile, linha))
    {
        this->setVerticePonderado(stoi(linha));
    }
    if(getline(inFile, linha))
    {
        this->setArestaPonderada(stoi(linha));
    }
    if(getline(inFile, linha))
    {
        this->setCompleto(stoi(linha));
    }
    if(getline(inFile, linha))
    {
        this->setBipartido(stoi(linha));
    }
    if(getline(inFile, linha))
    {
        this->setArvore(stoi(linha));
    }
    if(getline(inFile, linha))
    {
        this->setPonte(stoi(linha));
    }
    if(getline(inFile, linha))
    {
        this->setArticulacao(stoi(linha));
    }
    imprimeGrafo();
    inFile.close();
}
void Grafo_lista::novoGrafo(){
    srand(time(0));
    for(int i = 0; i<this->getOrdem();i+=1)
    {
        this->Vertice->insereFinal((rand()%100)+1);
    }
    if(eh_completo())
    {
        for(int i = 0; i<this->Vertice->getTam();i+=1)
        {
            for(int j = 0; j<this->getGrau()+1; j+=1)
            {
                if(j!=i)
                {
                    this->Vertice->getNodeById(i)->getArestas()->insereFinal(this->Vertice->getNodeById(j)->getValue());
                }
            }
        }
    }
    if (eh_arvore())
    {
    int numVertices = this->Vertice->getTam();
    if (numVertices < 2) return; 

    
        for (int i = 1; i < numVertices; i++) 
        {
            
            NodeVertex* atual = this->Vertice->getNodeById(i);
            NodeVertex* anterior = this->Vertice->getNodeById(i - 1);

            if (atual && anterior) 
            {
                atual->getArestas()->insereFinal(anterior->getValue());
                anterior->getArestas()->insereFinal(atual->getValue());
            }
        }
    }
    this->Vertice->imprimeLista();
    cout<<endl;
    for (int i = 0; i<this->Vertice->getTam();i+=1)
    {
        this->Vertice->getNodeById(i)->getArestas()->imprimeLista();
    }
    
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