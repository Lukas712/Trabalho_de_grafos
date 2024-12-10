#include "GrafoAbstract.h"
#include "Linked_Vertex.h"
class Grafo_lista : public GrafoAbstract
{
    private:
        Linked_Vertex* Vertice;
        int* ordem;
        int* grau;
        int* nCompConexo;
    public:
        Grafo_lista();
        ~Grafo_lista();
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
