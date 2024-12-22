#include <iostream>
using namespace std;

#ifndef GRAFOABSTRACT_H
#define GRAFOABSTRACT_H
class GrafoAbstract
{   
    private:
        int ordem;
        int grau;
        int nCompConexo;
        bool temArticulacao;
        bool temPonte;
        bool grafoBipartido;
        bool grafoCompleto;
        bool grafoDirecionado;
        bool grafoArvore;
    public:    
        int getNConexo(){return nCompConexo;};
        int getGrau(){return grau;};
        int getOrdem(){return ordem;};


        virtual bool verticePonderado() = 0;
        virtual bool arestaPonderada() = 0;
        bool eh_bipartido(){return grafoBipartido;};
        bool eh_direcionado(){return grafoDirecionado;};
        bool eh_completo(){return grafoCompleto;};
        bool eh_arvore(){return grafoArvore;};
        bool possuiArticulacao(){return temArticulacao;};
        bool possuiPonte(){return temPonte;};
        virtual void imprimeGrafo() = 0;

        void setNConexo(int val){
            this->nCompConexo = val;
        };
        void setGrau(int val){grau = val;};
        void setOrdem(int val){ordem = val;};
        virtual void setVerticePonderado(bool val) = 0;
        virtual void setArestaPonderada(bool val) = 0;
        void setBipartido(bool val){grafoBipartido = val;};
        void setDirecionado(bool val){grafoDirecionado = val;};
        void setCompleto(bool val){grafoCompleto = val;};
        void setArvore(bool val){grafoArvore = val;};
        void setArticulacao(bool val){temArticulacao = val;};
        void setPonte(bool val){temPonte = val;};

        void criaCompleto(ofstream& outFile, int ordem, bool arestaPonderada, bool direcionado) {
    
            int vet[ordem*(ordem-1)/2] = {0};
            if(!direcionado)
            {
                for(int i = 0; i<ordem*(ordem-1)/2; i+=1)
                {
                    vet[i] = (rand() % 100 + 1);
                }
            }
            for (int i = 0; i < ordem; i+=1) {
                for (int j = 0; j < ordem; j+=1) {
                    if (i != j) {
                        
                        outFile << i+1 << " " << j+1 << " ";
                        if(arestaPonderada)
                        {
                            if(direcionado)
                            {   
                                outFile<<(rand() % 100 + 1);
                            }
                            else
                            {
                                if(i<j)
                                {
                                    outFile<<vet[((j-1)*j)/2+i];
                                }
                                else if (i>j)
                                {
                                    outFile<<vet[((i-1)*i)/2+j];
                                }
                            }
                        }
                        outFile << endl;
                    }
                }
            }
        }

        void criaArvore(ofstream& outFile, int ordem, bool arestaPonderada, bool direcionado) {
            int vet[ordem-1] = {0};
            if (!direcionado) {
                for (int i = 0; i < ordem-1; i+=1) {
                    vet[i] = rand() % 100 + 1;
                }
            }

            for (int i = 1; i < ordem;) {
                int origem = rand() % (i);
                int destino = i;
                if(origem != destino)
                {
                    outFile << origem + 1 << " " << destino + 1<< " ";
                    if (arestaPonderada) {
                        if (direcionado) {
                            outFile <<(rand() % 100 + 1);
                        } else {
                            outFile << vet[i-1];
                            outFile << endl;
                            outFile << destino + 1 << " " << origem + 1<< " " << vet[i-1];
                        }
                    }
                    else
                    {
                        outFile << destino + 1 << " " << origem + 1<< " ";
                    }
                    outFile << endl;
                    i+=1;
                }
            }
        }

        void criaBipartido(ofstream& outFile, int ordem, bool arestaPonderada, bool direcionado) {
            
            int tamanhoU = ordem / 2;
            int tamanhoV = ordem - tamanhoU;

            int vet[tamanhoU * tamanhoV] = {0};
            if (!direcionado) {
                for (int i = 0; i < tamanhoU * tamanhoV; i++) {
                    vet[i] = (rand() % 100 + 1);
                }
            }

            for (int i = 0; i < tamanhoU; i+=1) {
                for (int j = 0; j < tamanhoV; j+=1) {
                    int u = i;                
                    int v = tamanhoU + j;    

                    outFile << u+1 << " " << v+1 << " ";
                    if (arestaPonderada) {
                        if (direcionado) {
                            outFile << (rand() % 100 + 1);
                        } else {
                            outFile << vet[i * tamanhoV + j];
                        }
                    }
                    outFile << endl;

                    if (!direcionado) {
                        outFile << v+1 << " " << u+1 << " ";
                        if (arestaPonderada) {
                            outFile << vet[i * tamanhoV + j];
                        }
                        outFile << endl;
                    }
                }
            }
        }

};
#endif