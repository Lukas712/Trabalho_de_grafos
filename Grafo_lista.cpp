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


void Grafo_lista::carregaGrafo() {
    ifstream inFile("/home/lukas-freitas/VsCode/Trabalho_de_grafos/output/grafo.txt");
    if (!inFile.is_open()) {
        cerr << "Erro ao abrir o arquivo grafo.txt" << endl;
        return;
    }

    int numVertices, direcionado, verticePonderado, arestaPonderada;
    inFile >> numVertices >> direcionado >> verticePonderado >> arestaPonderada;

    this->setOrdem(numVertices);
    this->setDirecionado(direcionado);
    this->setVerticePonderado(verticePonderado);
    this->setArestaPonderada(arestaPonderada);

    if (verticePonderado) {
        for (int i = 0; i < numVertices; i+=1) {
            int peso;
            inFile >> peso;
        }
    } else {
        for (int i = 0; i < numVertices; i+=1) {
        }
    }

    int origem, destino, peso;
    while (inFile >> origem >> destino) {
        if (arestaPonderada) {
            inFile >> peso;
        } else {
            peso = 1;
        }
        // NodeVertex* noOrigem = this->Vertice->getNodeById(origem-1);
        // NodeVertex* noDestino = this->Vertice->getNodeById(destino-1);

        // if (noOrigem && noDestino) {
        //     noOrigem->getArestas()->insereFinal(noDestino->getValue());
        //     if (!direcionado) {
        //         noDestino->getArestas()->insereFinal(noOrigem->getValue());
        //     }
        // }
    }

    inFile.close();
    imprimeGrafo();
}

void Grafo_lista::novoGrafo() {
    srand(time(0));
    ifstream descFile("/home/lukas-freitas/VsCode/Trabalho_de_grafos/output/Descricao.txt");
    if (!descFile.is_open()) {
        cerr << "Erro ao abrir o arquivo Descricao.txt" << endl;
        return;
    }
    
    bool direcionado,verticePonderado, arestaPonderada, completo, bipartido, arvore, ponte,  articulacao;
    int grau = 0, ordem, componentesConexas;

    descFile >> grau >> ordem >> direcionado >> componentesConexas >> verticePonderado >> arestaPonderada;
    descFile >> completo >> bipartido >> arvore >> ponte >> articulacao;

    descFile.close();

    ofstream outFile("grafo.txt");
    if (!outFile.is_open()) {
        cerr << "Erro ao criar o arquivo grafo.txt" << endl;
        return;
    }

    outFile << ordem << " " << direcionado << " " << verticePonderado << " " << arestaPonderada << endl;
    
    if(verticePonderado)
    {
        for (int i = 0; i < ordem; ++i) {
            int peso = (rand() % 100 + 1);
            if (verticePonderado) {
                outFile << peso << " ";
            }
        }
        outFile << endl;
    }

    if (completo) {
        criaCompleto(outFile, ordem, arestaPonderada, direcionado);
    } else if (bipartido) {
        criaBipartido(outFile, ordem, arestaPonderada, direcionado);
    } else if (arvore) {
        criaArvore(outFile, ordem, arestaPonderada, direcionado);
    }

    // if (ponte) {
    //     adicionaPonte(outFile);
    // }
    // if (articulacao) {
    //     adicionaArticulacao(outFile);
    // }

    outFile.close();
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