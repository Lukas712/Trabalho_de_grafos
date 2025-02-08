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
                atualizaAresta(arestas, j+1);
                arestas->removeNode(noAresta);
            }

        void removeVertice(int id) {
        NodeVertex* no = getNodeById(id);
        if (no == nullptr){
            return;
        }

        NodeVertex* current = getPrimeiro();
        while (current != nullptr) {
            Linked_list<NodeEdge>* arestas = current->getArestas();
            NodeEdge* edge = arestas->getPrimeiro();
            while (edge != nullptr) {
                if (edge->getValue() == id) {
                    NodeEdge* auxEdge = edge;
                    edge = (NodeEdge*)edge->getProx();
                    arestas->removeNode(auxEdge);
                }
                else if(edge->getValue() > id)
                {
                    edge->setValue(edge->getValue()-1);
                    edge->setId(edge->getId()-1);
                    edge = (NodeEdge*)edge->getProx();
                }
                else
                {
                    edge = (NodeEdge*)edge->getProx();
                }
            }
            current = (NodeVertex*)current->getProx();
        }

        removeNode(no);
        
        NodeVertex* p = getPrimeiro();
        int newId = 0;
        while (p != nullptr) {
            p->setId(newId++);
            p = (NodeVertex*)p->getProx();
        }
    }

    void atualizaAresta(Linked_list<NodeEdge>* arestas, int val)
    {
        NodeEdge* atualizaId = (NodeEdge*)arestas->getPrimeiro();
        while(atualizaId != nullptr)
        {
            if(atualizaId->getValue() > val)
            {
                atualizaId->setValue(atualizaId->getValue()-1);
                atualizaId->setId(atualizaId->getId()-1);
            }
            atualizaId = (NodeEdge*)atualizaId->getProx();
        }
    }
    };
#endif