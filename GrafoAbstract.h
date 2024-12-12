#ifndef GRAFOABSTRACT_H
#define GRAFOABSTRACT_H
class GrafoAbstract
{   
    public:    
        virtual int nConexo() = 0;
        virtual int getGrau() = 0;
        virtual int getOrdem() = 0;

        virtual void carregaGrafo() = 0;
        virtual void novoGrafo() = 0;

        virtual bool verticePonderado() = 0;
        virtual bool arestaPonderada() = 0;
        virtual bool eh_bipartido() = 0;
        virtual bool eh_direcionado() = 0;
        virtual bool eh_completo() = 0;
        virtual bool eh_arvore() = 0;
        virtual bool possuiArticulacao() = 0;
        virtual bool possuiPonte() = 0;

};

#endif