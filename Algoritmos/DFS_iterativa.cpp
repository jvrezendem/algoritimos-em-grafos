#include <iostream>
#include <vector>
#include <stack>

using namespace  std;


//este programa mostra a implementação do algoritmo de busca em profundidade (DFS) de forma iterativa
//o algoritmo de DFS é utilizado para percorrer um grafo, visitando todos os vértices e arestas de forma iterativa
//a pilha ensinada na teoria do algoritmo de DFS é implementada explicitamente pela estrutura de dados stack, ou seja, 
//cada elemento da pilha representa um vértice a ser visitado

//defines as cores para marcar os vértices durante a visita
#define BRANCO 0
#define CINZA 1
#define PRETO 2

void DFS_iterativa_visit(vector<vector<unsigned>> &lista_adjacencia, unsigned vertice, vector<unsigned> &cor)
{
    //define a pilha para o backtracking da busca
    stack<unsigned> pilha;
    
    cor[vertice] = CINZA; //marca o vértice como cinza, ou seja, em processo de visita

    //empilha o vertice na pilha
    pilha.push(vertice);

    while(!pilha.empty()){
        unsigned visita = pilha.top();
        for(unsigned vizinhos : lista_adjacencia[visita]){
            if(cor[vizinhos] == BRANCO){
                cor[vizinhos] = CINZA;
                pilha.push(vizinhos);
                
            }
        }

        cor[vertice] == PRETO;
        pilha.pop();
    }
}

unsigned DFS_iterativa(vector<vector<unsigned>> &lista_adjacencia, unsigned n_vertice)
{
    //estruturas auxiliares para a DFS iterativa
    vector<unsigned> cor(n_vertice, BRANCO); //vetor para marcar a cor de cada vértice
    stack<unsigned> pilha; //pilha para armazenar os vértices a serem visitados
    unsigned componentes_conexas = 0; //contador de componentes conexas

    //percorre todos os vértices do grafo
    for(unsigned vertice = 0; vertice < n_vertice; vertice++){
        if(cor[vertice] == BRANCO){
            DFS_iterativa_visit(lista_adjacencia, vertice, cor);
            componentes_conexas++;
        }
    }

    return componentes_conexas;
}

int main()
{  
    //definições do grafo por lista de adjacências
    unsigned n = 6;
    vector<vector<unsigned>> lista_adjacencia(n);
    lista_adjacencia[0] = {1, 3};
    lista_adjacencia[1] = {2};
    lista_adjacencia[2] = {3};
    lista_adjacencia[3] = {1};
    lista_adjacencia[4] = {2, 5};
    lista_adjacencia[5] = {5};

    unsigned componentes_conexas = DFS_iterativa(lista_adjacencia, n);
    cout << "Número de componentes conexas: " << componentes_conexas << endl;


    return 0;
}