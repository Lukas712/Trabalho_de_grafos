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
        virtual void setVerticePonderado(bool val) = 0;
        virtual void setArestaPonderada(bool val) = 0;
        virtual bool verticePonderado() = 0;
        virtual bool arestaPonderada() = 0;
        virtual void imprimeGrafo() = 0;
        virtual void insereVertice(int val) = 0;
        virtual void insereAresta(int origem, int destino, int val) = 0;
        
        int getNConexo(){return nCompConexo;};
        int getGrau(){return grau;};
        int getOrdem(){return ordem;};

        bool eh_bipartido(){return grafoBipartido;};
        bool eh_direcionado(){return grafoDirecionado;};
        bool eh_completo(){return grafoCompleto;};
        bool eh_arvore(){return grafoArvore;};
        bool possuiArticulacao(){return temArticulacao;};
        bool possuiPonte(){return temPonte;};
        
        void setGrau(int val){grau = val;};
        void setOrdem(int val){ordem = val;};
        
        void setBipartido(bool val){grafoBipartido = val;};
        void setDirecionado(bool val){grafoDirecionado = val;};
        void setCompleto(bool val){grafoCompleto = val;};
        void setArvore(bool val){grafoArvore = val;};
        void setArticulacao(bool val){temArticulacao = val;};
        void setPonte(bool val){temPonte = val;};



        void setNConexo(int val){
            this->nCompConexo = val;
        };
        
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

        bool criaBipartido(ofstream& outFile, int ordem, bool arestaPonderada, bool direcionado, int grau, int componentesConexas, int ponte, int articulacao) {
            int tamanho[componentesConexas] = {0};
            int base = ordem / componentesConexas;
            int sobra = ordem % componentesConexas;

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
                                    outFile<<calculoVertice+ somaTamanhoComponentes<<" "<<j+1+somaTamanhoComponentes<<" "<<endl;
                                }
                                
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
                                    outFile<<calculoVertice-ladoMenor+(ladoMenor-ladoMaior)+somaTamanhoComponentes<<" "<<j+1+somaTamanhoComponentes<< " "<<endl;
                                }
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



    void carregaGrafo() {
        ifstream inFile("grafo.txt");
        if (!inFile.is_open()) {
            cerr << "Erro ao abrir o arquivo grafo.txt" << endl;
            inFile.close();
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
        } else {
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

    void novoGrafo() {
        srand(time(0));
        ifstream descFile("Descricao.txt");
        if (!descFile.is_open()) {
            cerr << "Erro ao abrir o arquivo Descricao.txt" << endl;
            descFile.close();
            return;
        }
        
        bool direcionado,verticePonderado, arestaPonderada, completo, bipartido, arvore, ponte,  articulacao;
        int grau = 0, ordem, componentesConexas;

        descFile >> grau >> ordem >> direcionado >> componentesConexas >> verticePonderado >> arestaPonderada;
        descFile >> completo >> bipartido >> arvore >> ponte >> articulacao;

        descFile.close();
        ofstream outFile("grafo.txt", ios::trunc);
        if (!outFile.is_open()) {
            cerr << "Erro ao criar o arquivo grafo.txt" << endl;
            outFile.close();
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
                limpaArquivo(outFile);
                return;
            }
            criaCompleto(outFile, ordem, arestaPonderada, direcionado);
        }
        else if (bipartido) {
            if(!criaBipartido(outFile, ordem, arestaPonderada, direcionado, grau, componentesConexas, ponte, articulacao))
            {
                cout<<"Grafo bipartido não pode ser feito com a descrição dada!"<<endl;
                limpaArquivo(outFile);
                return;
            }
        } 
        else if (arvore)
        {
            if(componentesConexas != 1 || grau >= ordem || grau <0 || ordem <=0  || (ordem == 1 && ponte) || ((ordem == 1 || ordem == 2) && articulacao) || (ordem >2 && grau == 1))
            {
                    cout<<"Grafo arvore não pode ser feito com a descrição dada!"<<endl;
                    limpaArquivo(outFile);
                    return;
            }
            criaArvore(outFile, ordem, arestaPonderada, direcionado, grau);
        }
        outFile.close();
    }

    void limpaArquivo(ofstream& outFile) {
        outFile.close();
        outFile.open("grafo.txt", ios::trunc);
        outFile.close();
    }
};
#endif