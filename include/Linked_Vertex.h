    #ifndef LINKED_VERTEX_H
    #define LINKED_VERTEX_H

    #include "Linked_list.hpp"
    #include "NodeVertex.h"

    class Linked_Vertex : public Linked_list<NodeVertex>
    {
        public:
        /**
        * @brief Construtor da classe Lista encadeada para os vértices
        */
        Linked_Vertex();
        
        /**
        * @brief Destrutor da classe lista encadeada para os vértices
        */
        ~Linked_Vertex();
        
        /**
        * @brief Insere uma aresta entre dois vértices
        * @param origem Define o nó em que será inserido a aresta
        * @param destino Define o id do nó que a aresta corresponde
        * @param val Define o peso da aresta
        */
        void insereAresta(int origem, int destino, float val);
        
        /**
        * @brief Remove uma aresta entre dois vértices
        * @param i Nó em que será removida a aresta
        * @param j Id do nó que a aresta corresponde
        */
        void removeAresta(int i, int j);

        /**
        * @brief Remove um vértice
        * @param id Nó que será removido
        */
        void removeVertice(int id);
    };


#endif