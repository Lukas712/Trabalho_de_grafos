struct noGrafo{
    int peso;
    // List<noAresta>* arestas;
    int id;
};

struct arestaGrafo{
    int peso;
    noGrafo* origem;
    noGrafo* destino;
};

class Grafo{
    public:
    Grafo();
    ~Grafo();
    noGrafo* getNo(int id);
    arestaGrafo* getAresta(int origem, int destino);
    void insereNo(float peso);
    void insereAresta(int origem, int destino, float peso);
    arestaGrafo** getVizinhos(int id);
    bool removeNo(int id);
    bool removeAresta(int id);
};