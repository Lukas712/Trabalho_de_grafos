#include "GrafoAbstract.h"

class Grafo_matriz : public GrafoAbstract
{
    private:
        int* matriz_adjacencia;
    public:
        Grafo_matriz();
        ~Grafo_matriz();
        int n_conexo();
        int getGrau();
        int getOrdem();

        void carregaGrafo();
        void novoGrafo();

        bool verticePonderado();
        bool arestaPonderada();
        bool eh_bipartido();
        bool eh_direcionado();
        bool eh_completo();
        bool eh_arvore();
        bool possuiArticulacao();
        bool possuiPonte();
};

