#include <iostream>
#include <fstream>
using namespace std;

#ifndef GRAFOABSTRACT_HPP
#define GRAFOABSTRACT_HPP

class GrafoAbstract
{   
    private:
        int ordem;
        bool direcionado, verticePeso, arestaPeso;

        bool arquivoVazio(string nomeArquivo) {
            ifstream outFile(nomeArquivo, ios::in);
            if (!outFile.is_open()) {
                cout << "Erro ao abrir o arquivo." << endl;
                return true;
            }

            outFile.seekg(0, ios::end);
            bool vazio = (outFile.tellg() == 0);
            outFile.close();
            return vazio;
        }

        void setOrdem(int val) {
            this->ordem = val;
        }

        void setDirecionado(bool val) {
            this->direcionado = val;
        }

       void setVerticePonderado(bool val) {
            this->verticePeso = val;
        }

        void setArestaPonderada(bool val) {
            this->arestaPeso = val;
        }
    public:    
        
        virtual void insereVertice(int val) = 0;
        virtual void insereAresta(int origem, int destino, int val) = 0;
        // virtual void insereArestaAleatoria(int i, int j, int peso) = 0;
        // virtual GrafoAbstract getAresta();
        // virtual GrafoAbstract getVertice();
        
        virtual int getNConexo() = 0;
        virtual int getGrau() = 0;
        

        virtual bool eh_bipartido() = 0;
        
        virtual bool eh_completo() = 0;
        virtual bool eh_arvore() = 0;
        virtual bool possuiArticulacao() = 0;
        virtual bool possuiPonte() = 0;


        bool eh_direcionado() {return this->direcionado;};
        bool verticePonderado() {return this->verticePeso;};
        bool arestaPonderada() {return this->arestaPeso;};
        int getOrdem(){return this->ordem;};

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
                    if(!direcionado)
                    {
                        outFile << endl;
                        outFile << i + 1 << " " <<  j;
                    }
                }
                outFile << endl; 
            }
        }

        bool criaBipartido(ofstream& outFile, int ordem, bool arestaPonderada, bool direcionado, int grau, int componentesConexas, int ponte, int articulacao) {
            int tamanho[componentesConexas] = {0};
            int base = ordem / componentesConexas;
            int sobra = ordem % componentesConexas;
            int somaTamanhoComponentes = 0;

            int vet[ordem] = {0};
            if (!direcionado)
            {
                for(int i = 0; i < ordem; i+=1)
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
                tamanho[i]+=1;
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
                            tamanho[j]-=1;
                            tamanho[i]+=1;
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
            int contador=0;
            for(int i = 0; i<componentesConexas; i+=1)
            {
                if(tamanho[i]>0)
                {
                    contador+=1;
                }
            }
            
            if(contador != componentesConexas)
            {
                return false;
            }

            bool temPonte= false;
            bool temArticulacao = false;
            bool componenteSatisfazGrau = false;
            for(int i = 0; i<componentesConexas; i+=1)
            {
                int ladoMaior = (tamanho[i]+1)/2;
                int ladoMenor = tamanho[i]-ladoMaior;
                int calculoGrauUm = ((ladoMenor*grau)-ladoMaior*2);
                
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
                if(ladoMenor>1 && grau <= 1)
                {
                    return false;
                }
                if(ladoMenor >= 1)
                {
                    
                    if(ladoMenor == 1 && ladoMaior == 1)
                    {
                        
                        temPonte = true;
                        if(grau == 1)
                        {
                            componenteSatisfazGrau = true;
                        }
                        else
                        {
                            componenteSatisfazGrau = false;
                        }
                    }
                    else if(ladoMenor == 1 && ladoMaior > 1)
                    {
                        
                        temPonte = true;
                        temArticulacao = true;
                        if(grau<=ladoMaior)
                        {
                            componenteSatisfazGrau = true;
                        }
                        break;
                    }
                    else if(calculoGrauUm < 0)
                    {
                        componenteSatisfazGrau = true;
                        temPonte = true;
                        temArticulacao = true;
                        break;
                    }
                    else if(calculoGrauUm >= 0)
                    {
                        componenteSatisfazGrau = true;
                        temPonte = false;
                        temArticulacao = false;
                    }
                }
            }
            if(temArticulacao != articulacao || temPonte != ponte || grau > ordem ||!componenteSatisfazGrau)
            {
                return false;
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
                        
                       
                        if(calculoVertice <= tamanho[i])
                        {
                            outFile<<j+1+somaTamanhoComponentes<<" "<<calculoVertice+ somaTamanhoComponentes<<" ";
                            if(arestaPonderada)
                            {
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
                                if(!direcionado)
                                {
                                    outFile<<endl;
                                    outFile<<calculoVertice+ somaTamanhoComponentes<<" "<<j+1+somaTamanhoComponentes<<" ";
                                }
                                outFile<<endl;
                            }
                            
                        }
                        else
                        {
                            outFile<<j+1+somaTamanhoComponentes<<" "<<calculoVertice-ladoMenor+(ladoMenor-ladoMaior)+ somaTamanhoComponentes<<" ";
                            if(arestaPonderada)
                            {
                                if(direcionado)
                                {
                                    outFile<<(rand() % 100 + 1)<<endl;
                                }
                                else
                                {
                                    outFile<<vet[calculoIndice]<<endl;
                                    outFile<<calculoVertice-ladoMenor+(ladoMenor-ladoMaior) 
                                    +somaTamanhoComponentes<<" "<<j+1+somaTamanhoComponentes<< " "<<vet[calculoIndice] <<endl;
                                }
                            }
                            else
                            {
                                if(!direcionado)
                                {
                                    outFile<<endl;
                                    outFile<<calculoVertice-ladoMenor+(ladoMenor-ladoMaior)+somaTamanhoComponentes<<" "<<j+1+somaTamanhoComponentes<< " ";
                                }
                                outFile<<endl;
                            }
                            
                        }
                        
                    }
                    if(grau>=ladoMaior)
                    {
                        contador+=1; 
                    }
                    
                }
            }
            return true;
        }

    void carregaGrafo(string grafo) {
        ifstream inFile(grafo);
        if(arquivoVazio(grafo))
        {
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
                insereVertice(peso);

            }
        } 
        else
        {
            for (int i = 0; i < numVertices; i+=1) {
                insereVertice(0);
            }
        }

        int origem, destino;
        while (inFile >> origem >> destino) {
            if (arestaPonderada) {
                int peso;
                inFile >> peso;
                insereAresta(origem, destino, peso);
            }
            else {
                insereAresta(origem, destino, 0);
            }
        }
        
        inFile.close();
        imprimeGrafo();
    }

    void novoGrafo(string descricao, string grafo) {
        srand(time(0));
        ifstream descFile(descricao);
        if(arquivoVazio(descricao))
        {
            return;
        }
        
        bool direcionado,verticePonderado, arestaPonderada, completo, bipartido, arvore, ponte,  articulacao;
        int grau = 0, ordem, componentesConexas;

        descFile >> grau >> ordem >> direcionado >> componentesConexas >> verticePonderado >> arestaPonderada;
        descFile >> completo >> bipartido >> arvore >> ponte >> articulacao;

        descFile.close();
        ofstream outFile(grafo, ios::trunc);
        if(!outFile.is_open())
        {
            cout<<"Erro ao abrir o arquivo."<<endl;
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
                limpaArquivo(outFile, grafo);
                return;
            }
            criaCompleto(outFile, ordem, arestaPonderada, direcionado);
        }
        else if (bipartido) {
            if(!criaBipartido(outFile, ordem, arestaPonderada, direcionado, grau, componentesConexas, ponte, articulacao))
            {
                cout<<"Grafo bipartido não pode ser feito com a descrição dada!"<<endl;
                limpaArquivo(outFile, grafo);
                return;
            }
        } 
        else if (arvore)
        {
            if(componentesConexas != 1 || grau >= ordem || grau <0 || ordem <=0  || (ordem == 1 && ponte) || ((ordem == 1 || ordem == 2) && articulacao) || (ordem >2 && grau == 1))
            {
                    cout<<"Grafo arvore não pode ser feito com a descrição dada!"<<endl;
                    limpaArquivo(outFile, grafo);
                    return;
            }
            criaArvore(outFile, ordem, arestaPonderada, direcionado, grau);
        }
        outFile.close();
    }

    void limpaArquivo(ofstream& outFile, string nomeArquivo) {
        outFile.close();
        outFile.open(nomeArquivo, ios::trunc);
        outFile.close();
    }
    void imprimeGrafo()
    {
        cout<<"grafo.txt"<<endl;
        cout<<endl;
        cout<<"Grau: "<<getGrau()<<endl;
        cout<<"Ordem: "<<getOrdem()<<endl;
        cout<<"Direcionado: "<<imprmeSimNao(eh_direcionado())<<endl;
        cout<<"Componentes conexas: "<<getNConexo()<<endl;
        cout<<"Vertices ponderados: "<<imprmeSimNao(verticePonderado())<<endl;
        cout<<"Arestas ponderadas: "<<imprmeSimNao(arestaPonderada())<<endl;
        cout<<"Completo: "<<imprmeSimNao(eh_completo())<<endl;
        cout<<"Bipartido: "<<imprmeSimNao(eh_bipartido())<<endl;
        cout<<"Arvore: "<<imprmeSimNao(eh_arvore())<<endl;
        cout<<"Aresta Ponte: "<<imprmeSimNao(possuiPonte())<<endl;
        cout<<"Vertice Articulação: "<<imprmeSimNao(possuiArticulacao())<<endl;
    }

    string imprmeSimNao(bool valor)
    {
        if(valor)
        {
            return "Sim";
        }
        return "Não";
    }

};
#endif