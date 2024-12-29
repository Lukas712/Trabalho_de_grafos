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

        void criaArvore(ofstream& outFile, int ordem, bool arestaPonderada, bool direcionado, int grau) {
            int vet[ordem-1] = {0};
            if (!direcionado) {
                for (int i = 0; i < ordem-1; i+=1) {
                    vet[i] = rand() % 100 + 1;
                }
            }
            int j;
            int contador = 0;
            for (int i = 1; i < ordem;i+=1) {;
                if (contador == 0) {
                    if(i<= grau)
                    {
                        j = 1;
                        contador = grau;
                    }
                    else
                    {
                        j +=1;
                        contador = grau-1;
                    }
                }

                contador-=1 ;
                outFile <<  j << " " << i + 1<< " ";
                if (arestaPonderada) {
                    if (direcionado) {
                        outFile <<(rand() % 100 + 1);
                    } else {
                        outFile << vet[i-1];
                        outFile << endl;
                        outFile << i + 1 << " " <<  j<< " " << vet[i-1];
                    }
                }
                else
                {
                    outFile << j << " " << i+1;
                    if(!direcionado)
                    {
                        outFile << endl;
                        outFile << i + 1 << " " <<  j;
                    }
                }
                outFile << endl; 
            }
        }

        // void criaBipartido(ofstream& outFile, int ordem, bool arestaPonderada, bool direcionado, int grau, int componentesConexas, int ponte, int articulacao)
        // {
        // int tamanho[componentesConexas] = {0};
        // int base = ordem / componentesConexas;
        // int sobra = ordem % componentesConexas;

        // for (int i = 0; i < componentesConexas; i+=1)
        // {
        //     tamanho[i] = base;
        // }
        // for (int i = 0; i < sobra; i+=1)
        // {
        //     tamanho[i]++;
        // }

        //     for (int i = 0; i < componentesConexas; i+=1)
        //     {
        //         while (tamanho[i] < grau + 1 && tamanho[i] > 1)
        //         {
        //             bool ajustado = false;
        //             for (int j = 0; j < componentesConexas; j+=1)
        //             {
        //                 if (i != j && tamanho[j] > 1)
        //                 {
        //                     tamanho[j]--;
        //                     tamanho[i]++;
        //                     ajustado = true;
        //                     break;
        //                 }
        //             }
        //             if (!ajustado)
        //             {
        //                 break;
        //             }
        //         }
        //     }

        //     int verticeUsado = 0;
        //     for (int i = 0; i < componentesConexas; i+=1) {
        //         int numVertices = tamanho[i];


        //         if (numVertices <= 1) {
        //             verticeUsado += numVertices;
        //             continue;
        //         }
                
        //         int vertices[numVertices];
        //         for (int j = 0; j < numVertices; j+=1) {
        //             vertices[j] = verticeUsado + j;
        //         }
        //         verticeUsado += numVertices;
        //         int contador = 0;

        //         for (int u = 0; u < numVertices; u+=1) {
        //             if(contador >grau-1)
        //             {
        //                 break;
        //             }
        //             for (int v = u + 1; v < numVertices && contador < grau; v+=1)
        //             {
        //                     outFile << vertices[u] + 1 << " " << vertices[v] + 1 << " ";
        //                     if (arestaPonderada) {
        //                         if (direcionado) {
        //                             outFile << (rand() % 100 + 1);
        //                         } else {
        //                             outFile << (rand() % 100 + 1);
        //                         }
        //                     }
        //                     outFile << endl;

        //                     if (!direcionado) {
        //                         outFile << vertices[v] + 1 << " " << vertices[u] + 1 << " ";
        //                         if (arestaPonderada) {
        //                             outFile << (rand() % 100 + 1);
        //                         }
        //                         outFile << endl;
        //                     }
        //                     contador+=1;
                        
        //             }
        //         }
        //     }
        // }

void criaBipartido(ofstream& outFile, int ordem, bool arestaPonderada, bool direcionado, int grau, int componentesConexas, int ponte, int articulacao) {
    int tamanho[componentesConexas] = {0};
    int base = ordem / componentesConexas;
    int sobra = ordem % componentesConexas;

    int vet[ordem-componentesConexas] = {0};
    if (!direcionado)
    {
        for(int i = 0; i < ordem-componentesConexas; i+=1)
        {
            vet[i] = rand() % 100 + 1;
        }
    }

    for (int i = 0; i < componentesConexas; i+=1)
    {
        tamanho[i] = base;
    }
    for (int i = 0; i < sobra; i+=1)
    {
        tamanho[i]++;
    }

    for (int i = 0; i < componentesConexas; i+=1)
    {
        while (tamanho[i] < grau + 1 && tamanho[i] > 1)
        {
            bool ajustado = false;
            for (int j = 0; j < componentesConexas; j+=1)
            {
                if (i != j && tamanho[j] > 1)
                {
                    tamanho[j]--;
                    tamanho[i]++;
                    ajustado = true;
                    break;
                }
            }
            if (!ajustado)
            {
                break;
            }
        }
    }
    
    for(int i = 0; i<componentesConexas; i+=1)
    {
        int ladoMaior = (tamanho[i]+1)/2;
        int ladoMenor = tamanho[i]-ladoMaior;
        while(ladoMaior < grau)
        {
            if(ladoMenor > 1)
            {
                ladoMaior += 1;
                ladoMenor -= 1;
            }
            else
            {
                break;
            }
        }
        int grauComponente;
        if(grau >ladoMaior)
        {
            grauComponente = ladoMaior;
        }
        else
        {
            grauComponente = grau;
        }
        
        int contador = 0;
        int somaTamanhoComponentes = 0;
        if(i>0)
        {
            somaTamanhoComponentes += tamanho[i-1];
        }
        
        for(int j = 0; j<ladoMenor; j+=1)
        {
            for(int k= 0; k<grauComponente; k+=1)
            {
                int calculoVertice = j+ladoMenor+k+1 - contador;
                int calculoIndice = j+somaTamanhoComponentes+calculoVertice-1-ladoMenor;
                if(somaTamanhoComponentes>0)
                {
                    calculoIndice-=1;
                }
                // cout<<calculoIndice<<endl;
                if(calculoVertice <= tamanho[i])
                {
                    outFile<<j+1+somaTamanhoComponentes<<" "<<calculoVertice+ somaTamanhoComponentes<<" ";
                    if(direcionado)
                    {
                        outFile<<(rand() % 100 + 1)<<endl;
                    }
                    else
                    {
                        outFile<<vet[calculoIndice]<<endl;
                        outFile<<calculoVertice+ somaTamanhoComponentes<<" "<<j+1+somaTamanhoComponentes<< " "<<vet[calculoIndice] <<endl;
                    }
                }
                else
                {
                    outFile<<j+1+somaTamanhoComponentes<<" "<<calculoVertice-ladoMenor+ somaTamanhoComponentes<<endl;
                    if(direcionado)
                    {
                        outFile<<(rand() % 100 + 1)<<endl;
                    }
                    else
                    {
                        outFile<<vet[calculoIndice]<<endl;
                        outFile<<calculoVertice+ somaTamanhoComponentes<<" "<<j+1+somaTamanhoComponentes<< " "<<vet[calculoIndice] <<endl;
                    }
                }
                
            }
            if(grau>=ladoMaior)
            {
                contador+=1; 
            }
            
        }
    }
}



    void carregaGrafo() {
        ifstream inFile("/home/lukas-freitas/VsCode/Trabalho_de_grafos/output/grafo.txt");
        if (!inFile.is_open()) {
            cerr << "Erro ao abrir o arquivo grafo.txt" << endl;
            return;
        }

        int numVertices, direcionado, verticePonderado, arestaPonderada;
        inFile >> numVertices >> direcionado >> verticePonderado >> arestaPonderada;

        this->setOrdem(numVertices);
        this->setDirecionado(direcionado);
        this->setVerticePonderado(verticePonderado);
        this->setArestaPonderada(arestaPonderada);

        if (verticePonderado) {
            for (int i = 0; i < numVertices; i+=1) {
                int peso;
                inFile >> peso;
            }
        } else {
            for (int i = 0; i < numVertices; i+=1) {
            }
        }

        int origem, destino, peso;
        while (inFile >> origem >> destino) {
            if (arestaPonderada) {
                inFile >> peso;
            } else {
                peso = 1;
            }
            // NodeVertex* noOrigem = this->Vertice->getNodeById(origem-1);
            // NodeVertex* noDestino = this->Vertice->getNodeById(destino-1);

            // if (noOrigem && noDestino) {
            //     noOrigem->getArestas()->insereFinal(noDestino->getValue());
            //     if (!direcionado) {
            //         noDestino->getArestas()->insereFinal(noOrigem->getValue());
            //     }
            // }
        }

        inFile.close();
        imprimeGrafo();
    }

    void novoGrafo() {
        srand(time(0));
        ifstream descFile("Descricao.txt");
        if (!descFile.is_open()) {
            cerr << "Erro ao abrir o arquivo Descricao.txt" << endl;
            return;
        }
        
        bool direcionado,verticePonderado, arestaPonderada, completo, bipartido, arvore, ponte,  articulacao;
        int grau = 0, ordem, componentesConexas;

        descFile >> grau >> ordem >> direcionado >> componentesConexas >> verticePonderado >> arestaPonderada;
        descFile >> completo >> bipartido >> arvore >> ponte >> articulacao;

        descFile.close();
        ofstream outFile("grafo.txt");
        if (!outFile.is_open()) {
            cerr << "Erro ao criar o arquivo grafo.txt" << endl;
            return;
        }

        outFile << ordem << " " << direcionado << " " << verticePonderado << " " << arestaPonderada << endl;
        
        if(verticePonderado)
        {
            for (int i = 0; i < ordem; ++i) {
                int peso = (rand() % 100 + 1);
                if (verticePonderado) {
                    outFile << peso << " ";
                }
            }
            outFile << endl;
        }
        
        if (completo) {
            if((grau != ordem-1) || componentesConexas != 1 || ponte || articulacao || ordem <=0)
            {
                cout<<"Grafo completo não pode ser feito com a descrição dada!"<<endl;
                return;
            }
            criaCompleto(outFile, ordem, arestaPonderada, direcionado);
        }
        else if (bipartido) {
            // if(grau < 0 || componentesConexas < 1 || componentesConexas > ordem|| ordem <=0 || grau > ((ordem+componentesConexas-1)/componentesConexas)|| (grau == 0 && componentesConexas != ordem) || grau < (2* (ordem-componentesConexas+1))/ordem || grau < max(ordem/(componentesConexas+1), ordem%(componentesConexas+1)))
            // {
            //     cout<<"Grafo bipartido não pode ser feito com a descrição dada!"<<endl;
            //     return;
            // }
            criaBipartido(outFile, ordem, arestaPonderada, direcionado, grau, componentesConexas, ponte, articulacao);
        } 
        else if (arvore)
        {
            if(componentesConexas != 1 || grau >= ordem || grau <0 || ordem <=0  || (ordem == 1 && ponte) || ((ordem == 1 || ordem == 2) && articulacao) || (ordem >2 && grau == 1))
            {
                    cout<<"Grafo arvore não pode ser feito com a descrição dada!"<<endl;
                    return;
            }
            criaArvore(outFile, ordem, arestaPonderada, direcionado, grau);
        }

        // if (ponte) {
        //     adicionaPonte(outFile);
        // }
        // if (articulacao) {
        //     adicionaArticulacao(outFile);
        // }

        outFile.close();
    }
};
#endif