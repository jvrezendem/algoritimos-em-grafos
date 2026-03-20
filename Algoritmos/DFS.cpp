#include <iostream>
#include <vector>

using namespace  std;

//este programa mostra a implementação do algoritmo de busca em profundidade (DFS) de forma recursiva
//o algoritmo de DFS é utilizado para percorrer um grafo, visitando todos os vértices e arestas de forma recursiva
//a pilha ensinada na teoria do algoritmo de DFS é implementada implicitamente pela recursão, ou seja, cada chamada recursiva representa um novo nível da pilha de execução

//constantes das cores
#define BRANCO 0
#define CINZA 1
#define PRETO 2

void DFS_visit(vector<vector<int>> &lista_adjacencia, int vertice, vector<int> &cor)
{
    //muda a cor do vertice para cinza
    cor[vertice] = CINZA;
    //percorre os vizinhos do vertice
    for(auto vizinho : lista_adjacencia[vertice]){
        //se encontar um vizinho branco, ou seja, não visitado, visita o vizinho
        if(cor[vizinho] == BRANCO){
            //chama a função recursiva para visitar o vizinho
            DFS_visit(lista_adjacencia, vizinho, cor);
        }
    }

    //quando não tiver mais vizinhos brancos para visiatar, muda a cor do vertice para preto, ou seja, visitado
    cor[vertice] = PRETO;

}

int DFS(vector<vector<int>> &lista_adjacencia, int n_vertice)
{
    int componentes_conexas = 0;

    //define todos os vertices inicialmente como BRANCO, ou seja, não visitados
    vector<int> cor(n_vertice, BRANCO);

    //inicia a DFS para cada vertice do grafo
    for(int vertice = 0; vertice < n_vertice; vertice++){

        //se o vertice é branco, visita o vertice
        if(cor[vertice] == BRANCO){
            //vertice branco indica que o vertice ainda não foi visitado, ou seja, é um novo componente conexo
            componentes_conexas++;
            DFS_visit(lista_adjacencia, vertice, cor);
        }
    }

    return componentes_conexas;
}


int main()
{
    //definições do grafo por lista de adjacências
    int n = 6;
    vector<vector<int>> lista_adjacencia(n);

    lista_adjacencia = {
        {1,3}, //vértice 0
        {2}, //vértice 1
        {3}, //vértice 2
        {1}, //vértice 3
        {2,5}, //vértice 4
        {5} //vértice 5
    };

    int componentes_conexas = DFS(lista_adjacencia, n);
    cout << "Número de componentes conexas: " << componentes_conexas << endl;

    return 0;
}