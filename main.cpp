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
        if(strcmp(argv[1],"-d") == 0)
        {
            if(strcmp(argv[2], "-l") == 0)
            {
                try{
                        Grafo_lista grafoL;
                        grafoL.carregaGrafo(argv[3]);
                        grafoL.removeVertice(1);
                        grafoL.removeAresta(2,1);
                        grafoL.imprimeGrafo(argv[3]);

                }
                catch(const exception& e)
                {
                    cout<<e.what()<<endl;
                    return 1;
                }
            }
            else
            {
                try{
                    Grafo_matriz grafoM;
                    grafoM.carregaGrafo(argv[3]);
                    grafoM.removeVertice(1);
                    grafoM.removeAresta(2,1);
                    grafoM.imprimeGrafo(argv[3]);
                }
                catch(const exception& e)
                {
                    cout<<e.what()<<endl;
                    return 1;
                }
            }
        }
        else if(strcmp(argv[1], "-p") == 0)
        {
            if(strcmp(argv[2], "-l") == 0)
            {
                try{
                        Grafo_lista grafoL;
                        grafoL.carregaGrafo(argv[3]);
                        cout<<grafoL.coloracaoArestaGuloso()<<endl;
                        cout<<grafoL.coloracaoArestaRandomizado()<<endl;
                        cout<<grafoL.coloracaoArestaReativo()<<endl;
                        grafoL.imprimeGrafo(argv[3]);

                }
                catch(const exception& e)
                {
                    cout<<e.what()<<endl;
                    return 1;
                }
            }
            else
            {
                try{
                    Grafo_matriz grafoM;
                    grafoM.carregaGrafo(argv[3]);
                    cout<<grafoM.coloracaoArestaGuloso()<<endl;
                    cout<<grafoM.coloracaoArestaRandomizado()<<endl;
                    cout<<grafoM.coloracaoArestaReativo()<<endl;
                    grafoM.imprimeGrafo(argv[3]);
                }
                catch(const exception& e)
                {
                    cout<<e.what()<<endl;
                    return 1;
                }
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