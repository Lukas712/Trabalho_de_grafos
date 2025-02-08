#include<iostream>
#include<fstream>
#include<string.h>
#include"Grafo_lista.h"
#include"Grafo_matriz.h"
#include "Grafo_lista.cpp"
#include "Grafo_matriz.cpp"
#include "Linked_Vertex.h"
using namespace std;
    
    
    
int main(int argc, char* argv[])
{
        if(strcmp(argv[1],"-d") == 0)
        {
            if(strcmp(argv[2], "-l") == 0)
            {
                Grafo_lista grafoL;
                grafoL.carregaGrafo(argv[3]);
                // grafoL.removeAresta(2,1);
                // grafoL.insereAresta(2,1, 0);
                // grafoL.removeAresta(2,3);
                // grafoL.removeAresta(1,2);
                // grafoL.removeVertice(3);
                // grafoL.insereVertice(5);
                grafoL.imprimeGrafo();
            }
            else
            {
                    Grafo_matriz grafoM;
                    grafoM.carregaGrafo(argv[3]);
                    // grafoM.insereAresta(2,1,0);
                    // grafoM.insereVertice(5);
                    // grafoM.removeAresta(3,3);
                    // grafoM.removeVertice(4);
                    grafoM.imprimeGrafo();
            }
        }
        else
        {
            cout<<"Argumentos inválidos!"<<endl;
        }
    return 0;
}