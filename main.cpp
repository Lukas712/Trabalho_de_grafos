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
                grafoL.removeVertice(1);
                grafoL.removeAresta(2,1);
                grafoL.imprimeGrafo();
            }
            else
            {
                    Grafo_matriz grafoM;
                    grafoM.carregaGrafo(argv[3]);
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