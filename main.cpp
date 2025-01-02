#include<iostream>
#include<fstream>
#include"Grafo_lista.h"
#include"Grafo_matriz.h"
#include "Grafo_lista.cpp"
#include "Grafo_matriz.cpp"
#include "Linked_Vertex.h"
using namespace std;
    
    
    
int main()
{
    // Grafo_lista grafoL;
    // grafoL.novoGrafo();
    // grafoL.carregaGrafo();
    Grafo_matriz grafoM;
    grafoM.novoGrafo();
    grafoM.carregaGrafo();
    return 0;
}