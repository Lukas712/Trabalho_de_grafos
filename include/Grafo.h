#ifndef GRAFO_H
#define GRAFO_H
#include "NodeVertex.h"
#include "NodeEdge.h"


class Grafo
{   
    private:
        int ordem = 0;
        bool direcionado, verticePeso, arestaPeso;
        string imprmeSimNao(bool valor);
    
    public:    
    virtual NodeVertex* getVertice(int id) = 0;
    virtual NodeEdge* getAresta(int origem, int destino) = 0;
    virtual void insereVertice(float val) = 0;
    virtual void insereAresta(int origem, int destino, float val) = 0;
    virtual void removeVertice(int id) = 0;
        
    bool eh_direcionado();
    bool verticePonderado();
    bool arestaPonderada();
    int getOrdem();
    void setOrdem(int val);
    void setDirecionado(bool val);
    void setVerticePonderado(bool val);
    void setArestaPonderada(bool val); 
    int getNConexo();
    int getGrau();
    bool eh_completo();
    void carregaGrafo(string grafo);
    void imprimeGrafo();
    void maiorMenorDistancia(int ponto1, int ponto2);
};

#include "../src/Grafo.cpp"

#endif