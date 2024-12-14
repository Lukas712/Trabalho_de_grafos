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

};
#endif