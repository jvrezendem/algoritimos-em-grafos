#include <iostream>
#include <vector>

using namespace std;

using vetor = vector<int>;
using adj = vector<vetor>;

#define B 0
#define C 1
#define P 2

void dfs_visit(adj &lista_adjacencia, vetor &cor,vetor &d,int &contador, int vertice, vetor &pai){
    cor[vertice] = C;
    d[vertice] = contador++;

    for(int vizinho: lista_adjacencia[vertice]){
        pai[vizinho] = vertice;
        if(cor[vizinho] == B){
            cout << "Aresta (" << vertice << "," << vizinho << ") de ARVORE" << endl;
            cor[vizinho] = C;
            dfs_visit(lista_adjacencia, cor, d, contador ,vizinho, pai);

        }

        if(cor[vizinho] == C and vizinho != pai[vertice]){
            cout << "Aresta (" << vertice << "," << vizinho << ") de RETORNO" << endl;
        }
    }

    cor[vertice] = P;
}

void dfs(adj &lista_adjacencia){
    int n = lista_adjacencia.size();
    vetor cor(n, B);
    vetor d(n, 0);
    vetor pai(n, -1);
    int contador = 0;


    for(int i = 0; i < n; i++){
        if(cor[i] == B){
            dfs_visit(lista_adjacencia, cor, d, contador ,i, pai);
        }
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    adj grafo(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    dfs(grafo);

    return 0;
}