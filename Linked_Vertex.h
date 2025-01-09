    #ifndef LINKED_VERTEX_H
    #define LINKED_VERTEX_H

    #include <iostream>
    #include "Linked_list.hpp"
    #include "NodeVertex.h"
    class Linked_Vertex : public Linked_list<NodeVertex>
    {
        private:
            bool arestaPonderada;
            bool verticePonderado;
        public:
        /**Construtor da classe Lista encadeada para os vértices */
            Linked_Vertex() : Linked_list(){};
            /**Destrutor da classe lista encadeada para os vértices */
            ~Linked_Vertex(){
                this->limpaNodes();
                ultimo = nullptr;
                };
                /**Retorna se as arestas são ponderadas ou não */
            bool getArestaPonderada() { return this->arestaPonderada;};
            /**Define se as arestas são ponderadas ou não */
            void setArestaPonderada(bool val){this->arestaPonderada = val;};
            /**Retorna se os vértices são ponderados ou não */
            bool getVerticePonderado(){return this->verticePonderado;};
           /**Define se os vértices são ponderados ou não */ 
            void setVerticePonderado(bool val){this->verticePonderado = val;};
            /**Insere uma aresta entre dois vértices dentro da lista de vértices do vértice de origem */
            void insereAresta(int origem, int destino, int val)
            {
                NodeVertex* noOrigem = getNodeById(origem-1);
                Linked_list<NodeEdge>* arestas = noOrigem->getArestas();
                arestas->insereFinal(destino-1);
                arestas->getUltimo()->setPeso(val);
            };
    };
    #endif