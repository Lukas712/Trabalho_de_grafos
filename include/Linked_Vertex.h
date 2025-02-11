    #ifndef LINKED_VERTEX_H
    #define LINKED_VERTEX_H

    #include "Linked_list.hpp"

    class Linked_Vertex : public Linked_list<NodeVertex>
    {
        public:
        /**Construtor da classe Lista encadeada para os vértices */
        Linked_Vertex();
        /**Destrutor da classe lista encadeada para os vértices */
        ~Linked_Vertex();
        /**Insere uma aresta entre dois vértices dentro da lista de vértices do vértice de origem */
        void insereAresta(int origem, int destino, int val);
        
        void removeAresta(int i, int j);

        void removeVertice(int id);
    };

#include "../src/Linked_Vertex.cpp"

#endif