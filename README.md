# Trabalho de Grafos

## Descrição
Este repositório contém a implementação de um trabalho de Teoria dos Grafos. O projeto inclui a criação e manipulação de grafos utilizando listas encadeadas e matrizes de adjacência, com funcionalidades avançadas como cálculo de distâncias utilizando o algoritmo de Dijkstra.

## Funcionalidades Principais

### Grafo

- `getVertice(int id)`: Retorna o nó caso exista o id desejado.
- `getAresta(int origem, int destino)`: Retorna a aresta caso exista.
- `insereVertice(float val)`: Insere um vértice com peso.
- `insereAresta(int origem, int destino, float val)`: Insere uma aresta entre dois nós com peso.
- `removeVertice(int id)`: Remove o vértice com o id passado como parâmetro.
- `removeAresta(int origem, int destino)`: Remove a aresta caso exista.
- `eh_direcionado()`: Retorna se o grafo é direcionado ou não.
- `verticePonderado()`: Retorna se os vértices do grafo são ponderados ou não.
- `arestaPonderada()`: Retorna se as arestas do grafo são ponderadas ou não.
- `getOrdem()`: Retorna a ordem do grafo.
- `setOrdem(int val)`: Define a ordem do grafo.
- `setDirecionado(bool val)`: Define se o grafo é direcionado ou não.
- `setVerticePonderado(bool val)`: Define se o grafo possui vértices ponderados.
- `setArestaPonderada(bool val)`: Define se o grafo possui arestas ponderadas.
- `getGrau()`: Retorna o grau do grafo.
- `eh_completo()`: Retorna se o grafo é completo.
- `carregaGrafo(string grafo)`: Carrega o grafo na estrutura.
- `imprimeGrafo()`: Imprime o grafo de acordo com a descrição do trabalho.
- `maiorMenorDistancia(int ponto1, int ponto2)`: Calcula a menor distância entre dois pontos utilizando o algoritmo de Dijkstra.

### Grafo_lista

- `insereVertice(float val)`: Insere um vértice com peso.
- `insereAresta(int origem, int destino, float val)`: Insere uma aresta entre dois nós com peso.
- `removeAresta(int i, int j)`: Remove uma aresta entre dois nós.
- `removeVertice(int id)`: Remove um vértice.
- `getVertice(int id)`: Retorna o nó caso exista o id desejado.
- `getAresta(int origem, int destino)`: Retorna a aresta caso exista.

### Grafo_matriz

- `insereVertice(float val)`: Insere um vértice com peso.
- `insereAresta(int origem, int destino, float val)`: Insere uma aresta entre dois nós com peso.
- `removeAresta(int origem, int destino)`: Remove uma aresta entre dois nós.
- `removeVertice(int id)`: Remove um vértice.
- `getVertice(int id)`: Retorna o nó caso exista o id desejado.
- `getAresta(int origem, int destino)`: Retorna a aresta caso exista.

### Node

- `getProx()`: Retorna o próximo nó.
- `setProx(Node prox)`: Define o próximo nó.
- `setValue(float value)`: Define o valor do nó.
- `getValue()`: Retorna o valor do nó.
- `setId(int val)`: Define o id do nó.
- `getId()`: Retorna o id do nó.

### NodeEdge

- `getPeso()`: Retorna o peso da aresta.
- `setPeso(float val)`: Define o peso da aresta.

### NodeVertex

- `getArestas()`: Retorna a lista de arestas do vértice.
- `getGrau()`: Retorna o grau do vértice.
- `setGrau(int val)`: Define o grau do vértice.

### Linked_list

Classe template para criação do grafo por lista encadeada.

- `getTam()`: Retorna o tamanho da lista.
- `getNodeById(int val)`: Retorna o nó correspondente ao id passado.
- `getUltimo()`: Retorna o último nó.
- `getPrimeiro()`: Retorna o primeiro nó.
- `insereFinal(float val)`: Insere nó no final da lista.
- `removeNode(NodeType no)`: Remove o nó passado como parâmetro da lista.

### Linked_Vertex

Implementação da classe `Linked_list` para vértices.

- `insereAresta(int origem, int destino, float val)`: Insere uma aresta entre dois vértices.
- `removeAresta(int i, int j)`: Remove uma aresta entre dois vértices.
- `removeVertice(int id)`: Remove um vértice.

## Instalação

Para clonar e executar este projeto, você precisará do Git e de um compilador C++ instalado em seu sistema. No seu terminal:

```sh
# Clone o repositório
git clone https://github.com/seu-usuario/trabalho-de-grafos.git

# Entre no diretório do projeto
cd trabalho-de-grafos

# Compile os arquivos
g++ -g -o {nome do programa} main.cpp
```
###Uso
Após a instalação, você pode executar o programa utilizando o comando abaixo:
```sh
./{nome do programa} -d -l grafo.txt
```
ou
```sh
./{nome do programa} -d - grafo.txt
```


##Membros da Equipe
- Lukas Freitas de Carvalho - Matrícula: 202376033
