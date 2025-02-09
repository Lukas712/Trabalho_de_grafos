#include "../include/Grafo.h"
#include <fstream>
#include <iostream>
using namespace std;

bool Grafo::eh_direcionado() {
    return this->direcionado;
}
bool Grafo::verticePonderado() {
    return this->verticePeso;
}
bool Grafo::arestaPonderada() {
    return this->arestaPeso;
}
int Grafo::getOrdem()
{
    return this->ordem;
}

void Grafo::setOrdem(int val) {
    this->ordem = val;
}

void Grafo::setDirecionado(bool val) {
    this->direcionado = val;
}

void Grafo::setVerticePonderado(bool val) {
    this->verticePeso = val;
}

void Grafo::setArestaPonderada(bool val) {
    this->arestaPeso = val;
}
        
int Grafo::getNConexo() {
        int* componentes = new int[getOrdem()]();

        for (int i = 0; i < getOrdem(); i+=1) {
            componentes[i] = i + 1;
        }


        for (int i = 0; i < getOrdem(); i+=1) {
            for (int j = 0; j < getOrdem(); j+=1) {
                if (i != j && getAresta(i, j) != nullptr) {
                    int menor = min(componentes[i], componentes[j]);
                    int maior = max(componentes[i], componentes[j]);

                    componentes[i] = menor;
                    componentes[j] = menor;

                    for (int k = 0; k < getOrdem(); k+=1) {
                        if (componentes[k] == maior) {
                            componentes[k] = menor;
                        }
                    }
                }
            }
        }


        int contaDiferente = 1;
        for (int i = 1; i < getOrdem(); i+=1) {
            if (componentes[i] != componentes[i - 1]) {
                contaDiferente+=1;
            }
        }

        delete[] componentes;

        if(contaDiferente == 1)
        {
        return 1;
        }
        else
        {
        return contaDiferente;
        }
    }
int Grafo::getGrau(){
    int maior = 0;
    int contador = 0;
    for(int i = 0; i<getOrdem(); i+=1)
    {
        for(int j = 0; j<getOrdem(); j+=1)
        {
            
            if(i != j)
            {
                if(getAresta(i,j) != nullptr)
                {
                    contador+=1;
                }
            }
        }
        if(contador>maior)
        {
            maior = contador;
        }
        contador = 0;
    }
    return maior;
};
        
bool Grafo::eh_completo() {
    int contador = 0;
    for(int i = 0; i<getOrdem(); i+=1)
    {
        for(int j = 0; j<getOrdem(); j+=1)
        {
            if(i != j)
            {
                if(getAresta(i,j) != nullptr)
                {
                    contador+=1;
                }
            }
        }
        if(contador!=getOrdem()-1)
        {
            return false;
        }
        contador = 0;
    }
    return true;
};
    
void Grafo::carregaGrafo(string grafo) {
    string caminhoGrafo = "entradas/" + grafo;
    cout<<caminhoGrafo<<endl;
    ifstream inFile(caminhoGrafo);

    int numVertices, direcionado, verticePonderado, arestaPonderada;
    inFile >> numVertices >> direcionado >> verticePonderado >> arestaPonderada;

    this->setDirecionado(direcionado);
    this->setVerticePonderado(verticePonderado);
    this->setArestaPonderada(arestaPonderada);

    if (verticePonderado) {
        for (int i = 0; i < numVertices; i+=1) {
            int peso;
            inFile >> peso;
            insereVertice(peso);

        }
    } 
    else
    {
        for (int i = 0; i < numVertices; i+=1) {
            insereVertice(1);
        }
    }

    int origem, destino;
    while (inFile >> origem >> destino) {
        if (arestaPonderada) {
            int peso;
            inFile >> peso;
            insereAresta(origem, destino, peso);
        }
        else {
            insereAresta(origem, destino, 1);
        }
    }
    inFile.close();
}
    
void Grafo::imprimeGrafo()
{
    cout<<"grafo.txt"<<endl;
    cout<<endl;
    cout<<"Grau: "<<getGrau()<<endl;
    cout<<"Ordem: "<<getOrdem()<<endl;
    cout<<"Direcionado: "<<imprmeSimNao(eh_direcionado())<<endl;
    cout<<"Componentes conexas: "<<getNConexo()<<endl;
    cout<<"Vertices ponderados: "<<imprmeSimNao(verticePonderado())<<endl;
    cout<<"Arestas ponderadas: "<<imprmeSimNao(arestaPonderada())<<endl;
    cout<<"Completo: "<<imprmeSimNao(eh_completo())<<endl;
}

string Grafo::imprmeSimNao(bool valor)
{
    if(valor)
    {
        return "Sim";
    }
    return "Não";
}