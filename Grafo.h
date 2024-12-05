class Grafo
{
private:
    /* data */
public:
    Grafo();
    ~Grafo();
    
    int nConexo();
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
