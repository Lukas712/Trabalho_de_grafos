#include<iostream>
#include<fstream>
#include"Grafo_lista.h"
#include"Grafo_matriz.h"
#include "Grafo_lista.cpp"
#include "Grafo_matriz.cpp"
#include "Linked_Vertex.h"
using namespace std;
    
    
    
int main(int argc, char* argv[])
{
    if(argv[1] == "-d")
    {
        if(argv[2] == "-l")
        {
            Grafo_lista grafoL;
            grafoL.novoGrafo(argv[3], argv[4]);
        }
        else
        {
            Grafo_matriz grafoM;
            grafoM.novoGrafo(argv[3], argv[4]);
        }
    }
    else
    {
        
        if(argv[2] == "-l")
        {
            Grafo_lista grafoL;
            grafoL.carregaGrafo(argv[3]);
        }
        else
        {
                Grafo_matriz grafoM;
                grafoM.carregaGrafo(argv[3]);
        }
    }
    return 0;
}