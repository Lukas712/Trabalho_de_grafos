#include<iostream>
#include<fstream>
#include<string.h>
#include"include/Grafo_lista.h"
#include"include/Grafo_matriz.h"
using namespace std;
    
    
    
int main(int argc, char* argv[])
{
        if(strcmp(argv[1],"-d") == 0)
        {
            if(strcmp(argv[2], "-l") == 0)
            {
                Grafo_lista grafoL;
                grafoL.carregaGrafo(argv[3]);
                // cout<<grafoL.getAresta(1,0)->getPeso()<<endl;
                // grafoL.insereAresta(3,1,5);
                // grafoL.insereAresta(3,2,1);
                // grafoL.removeAresta(2,3);
                // grafoL.removeAresta(1,2);
                // grafoL.removeVertice(3);
                // grafoL.insereVertice(5);
                for(int i = 0; i<500; i+=1)
                {
                    grafoL.insereVertice(i);
                }
                // grafoL.removeAresta(2,1);
                // grafoL.insereAresta(1,3,0);
                // grafoL.insereAresta(2,1, 2);
                // cout<<(grafoL.getAresta(1,0)->getPeso())<<endl;
                grafoL.imprimeGrafo();
                // grafoL.maiorMenorDistancia(1,3);
            }
            else
            {
                    Grafo_matriz grafoM;
                    grafoM.carregaGrafo(argv[3]);
                    // grafoM.insereAresta(2,1,0);
                    for(int i = 0; i<500; i+=1)
                    {
                        grafoM.insereVertice(i);
                    }
                    // grafoM.removeVertice(1);
                    // grafoM.removeAresta(2,1);
                    // grafoM.removeAresta(2,1);
                    // grafoM.insereAresta(1,3,0);
                    // grafoM.insereAresta(2,1, 2);
                    grafoM.imprimeGrafo();
                    // grafoM.maiorMenorDistancia(1,3);
            }
        }
        else
        {
            cout<<"Argumentos inválidos!"<<endl;
        }
    return 0;
}