    #ifndef LINKED_VERTEX_H
    #define LINKED_VERTEX_H

    #include <iostream>
    #include "Linked_list.hpp"
    #include "NodeVertex.h"
    #include "NodeEdge.h"
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

            void removeAresta(int i, int j)
            {
                NodeVertex* no = getNodeById(i-1);
                Linked_list<NodeEdge>* arestas = no->getArestas();
                NodeEdge* noAresta = (NodeEdge*)arestas->getPrimeiro();
                while(noAresta != nullptr && noAresta->getValue() != j-1)
                {
                    noAresta = (NodeEdge*)noAresta->getProx();
                }
                arestas->removeNode(noAresta);
                NodeEdge* noAlteraId = (NodeEdge*)arestas->getPrimeiro();
            }

            void removeVertice(int id)
            {
                NodeVertex* no = getNodeById(id);
                removeNode(no);
                NodeVertex* noAux = getPrimeiro();
                for(int i = 0; i< getTam(); i+=1)
                {
                    // cout<<getAresta(i,id+1)->getValue()<<endl;
                    if(noAux != nullptr)
                    {
                        NodeEdge* aresta = noAux->getArestas()->getPrimeiro();
                        while(aresta != nullptr)
                        {
                            if(aresta->getValue() == id)
                            {
                                noAux->getArestas()->removeNode(aresta);
                            }
                            aresta = (NodeEdge*)aresta->getProx();
                        }
                    }
                    noAux = (NodeVertex*)noAux->getProx();
                }
            };
    };
#endif