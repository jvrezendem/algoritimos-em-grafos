#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using fila = queue<int>;
using vetor = vector<int>;
using adj = vector<vetor>;

#define NAO_VISITADO 0;
#define VISITADO 1;

fila ordenacao_bfs(adj &lista_adjacencia)
{
    int n = lista_adjacencia.size();
    vetor grau_entrada(n, 0);
    fila fila_bfs;
    fila ordenacao;

    //encontrar graus de entrada
    for(int i = 0; i < n; i++){
        for(int vizinho: lista_adjacencia[i]){
            grau_entrada[vizinho]++;
        }
    }

    for(int i = 0; i < n; i++){
        if(grau_entrada[i] == 0)
            fila_bfs.push(i);
    }

    while(!fila_bfs.empty()){
        int vertice = fila_bfs.front();
        fila_bfs.pop();
        ordenacao.push(vertice);

        for(int vizinho: lista_adjacencia[vertice]){
            grau_entrada[vizinho]--;
            if(grau_entrada[vizinho] == 0){
                fila_bfs.push(vizinho);
            }
        }
    }

    return ordenacao;
}

int main(){

    int n, m;
    cin >> n >> m;

    adj grafo(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
    }

    fila ordenacao = ordenacao_bfs(grafo);

    cout << "Ordenação topológica: " << endl;

    while(!ordenacao.empty()){
        int v = ordenacao.front();
        cout << v << " ";
        ordenacao.pop();
    }

    return 0;
}