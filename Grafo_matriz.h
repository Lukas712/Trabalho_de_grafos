#include "GrafoAbstract.h"

class Grafo_matriz : public GrafoAbstract
{
    private:
        int* matriz_adjacencia;
    public:
        Grafo_matriz();
        ~Grafo_matriz();
        
        bool verticePonderado();
        bool arestaPonderada();
        void setVerticePonderado(bool val);
        void setArestaPonderada(bool val);
        void insereVertice(int val);
        void insereAresta(int origem, int destino, int val);

        void imprimeGrafo();
};
        

