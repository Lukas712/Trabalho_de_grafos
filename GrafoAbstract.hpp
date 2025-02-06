#include <iostream>
#include <fstream>
#include "NodeEdge.h"
#include "NodeVertex.h"
using namespace std;

#ifndef GRAFOABSTRACT_HPP
#define GRAFOABSTRACT_HPP

class GrafoAbstract
{   
    private:
        int ordem;
        bool direcionado, verticePeso, arestaPeso;

        

    public:    
        virtual NodeVertex* getVertice(int id) = 0;
        virtual NodeEdge* getAresta(int origem, int destino) = 0;
        virtual void insereVertice(int val) = 0;
        virtual void insereAresta(int origem, int destino, int val) = 0;
        virtual void removeVertice(int id) = 0;
        
        bool eh_direcionado() {return this->direcionado;};
        bool verticePonderado() {return this->verticePeso;};
        bool arestaPonderada() {return this->arestaPeso;};
        int getOrdem(){return this->ordem;};

        void setOrdem(int val) {
            this->ordem = val;
        }

        void setDirecionado(bool val) {
            this->direcionado = val;
        }

       void setVerticePonderado(bool val) {
            this->verticePeso = val;
        }

        void setArestaPonderada(bool val) {
            this->arestaPeso = val;
        }
        
        int getNConexo() {
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

        int getGrau(){
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
        
        bool eh_completo() {
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
    
    void carregaGrafo(string grafo) {
        
        
        ifstream inFile(grafo);

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
                insereVertice(peso);

            }
        } 
        else
        {
            for (int i = 0; i < numVertices; i+=1) {
                insereVertice(0);
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
                insereAresta(origem, destino, 0);
            }
        }
        
        inFile.close();
        
    }
    
    void imprimeGrafo()
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

    string imprmeSimNao(bool valor)
    {
        if(valor)
        {
            return "Sim";
        }
        return "Não";
    }

};
#endif