    #ifndef LINKED_VERTEX_H
    #define LINKED_VERTEX_H

    #include "Linked_list.hpp"

    class Linked_Vertex : public Linked_list<NodeVertex>
    {
        private:
            bool arestaPonderada;
            bool verticePonderado;
        public:
        /**Construtor da classe Lista encadeada para os vértices */
        Linked_Vertex();
        /**Destrutor da classe lista encadeada para os vértices */
        ~Linked_Vertex();
        /**Retorna se as arestas são ponderadas ou não */
        bool getArestaPonderada();
        /**Define se as arestas são ponderadas ou não */
        void setArestaPonderada(bool val);
        /**Retorna se os vértices são ponderados ou não */
        bool getVerticePonderado();
        /**Define se os vértices são ponderados ou não */ 
        void setVerticePonderado(bool val);
        /**Insere uma aresta entre dois vértices dentro da lista de vértices do vértice de origem */
        void insereAresta(int origem, int destino, int val);
        
        void removeAresta(int i, int j);

        void removeVertice(int id);
    };

#include "../src/Linked_Vertex.cpp"

#endif