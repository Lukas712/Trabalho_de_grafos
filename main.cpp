#include<iostream>
#include<fstream>
#include"Grafo_lista.h"
#include"Grafo_matriz.h"
#include "Grafo_lista.cpp"
#include "Linked_Vertex.h"
using namespace std;
    
    
    
int main()
{
    Grafo_lista grafo;
    grafo.novoGrafo();
    grafo.carregaGrafo();
    return 0;
}