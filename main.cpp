#include<iostream>
#include<fstream>
#include<string.h>
#include <cstdlib>
#include <ctime>
#include"include/Grafo_lista.h"
#include"include/Grafo_matriz.h"
using namespace std;
    
    
    
int main(int argc, char* argv[])
{
    if(argc == 4)
    {
        srand(time(0));
        if(strcmp(argv[1],"-d") == 0)
        {
            if(strcmp(argv[2], "-l") == 0)
            {
                Grafo_lista grafoL;
                grafoL.carregaGrafo(argv[3]);
                // grafoL.insereAresta(3,1,5);
                // grafoL.insereAresta(3,2,1);
                // grafoL.removeAresta(2,3);
                // grafoL.removeAresta(1,2);
                // grafoL.removeVertice(3);
                // grafoL.insereVertice(5);
                // for(int i = 0; i<50; i+=1)
                // {
                //     grafoL.insereVertice(i);
                // }
                // for (int origem = 1; origem <= 103; origem++) {
                //     for (int destino = 1; destino <= 103; destino++) {
                //         if (origem != destino) {
                //             int peso = rand() % 100+1;
                //             grafoL.insereAresta(origem, destino, peso);
                //         }
                //     }
                // }
                
                // grafoL.removeAresta(2,3);
                // grafoL.insereAresta(1,3,0);
                // grafoL.insereAresta(2,1, 2);
                grafoL.removeVertice(1);
                grafoL.removeAresta(2,1);
                grafoL.imprimeGrafo();
            }
            else
            {
                    Grafo_matriz grafoM;
                    grafoM.carregaGrafo(argv[3]);
                    // // grafoM.insereAresta(2,1,0);
                    // for(int i = 0; i<50; i+=1)
                    // {
                    //     grafoM.insereVertice(i);
                    // }
                    // for (int origem = 0; origem <= 104; origem++) {
                    //     for (int destino = 0; destino <= 104; destino++) {
                    //         if (origem != destino) {
                    //             int peso = rand() % 100+1;
                    //             grafoM.insereAresta(origem, destino, peso);
                    //         }
                    //     }
                    // }
                    // for (int origem = 1; origem <= 53; origem++) {
                    //     for (int destino = -10; destino <= 53; destino++) {
                    //         if (origem != destino) {
                    //             grafoM.removeAresta(origem, destino);
                    //         }
                    //     }
                    // }
                    
                    // grafoM.removeAresta(2,3);
                    // grafoM.removeAresta(2,1);
                    // grafoM.insereAresta(1,3,0);
                    // grafoM.insereAresta(2,1, 2);
                    // grafoM.removeVertice(1);
                    // grafoM.removeAresta(1,2);
                    grafoM.removeVertice(1);
                    grafoM.removeAresta(2,1);
                    grafoM.imprimeGrafo();
            }
        }
        else
        {
            cout<<"Argumentos inválidos!"<<endl;
        }
    }
    else
    {
        cout<<"Argumentos inválidos!"<<endl;
    }
    return 0;
}