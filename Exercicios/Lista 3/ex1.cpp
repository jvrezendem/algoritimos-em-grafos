#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using adj = vector<vector<int>>;
using vetor = vector<int>;
using fila = queue<int>;

#define BRANCO 0
#define CINZA 1
#define PRETO 2

vetor bfs(adj &grafo, int origem){

    int n = grafo.size();
    vetor cor(n, BRANCO);
    vetor distancia_origem(n, 0);
    fila auxiliar;

    //iniciando com origem
    auxiliar.push(origem);
    distancia_origem[origem] = 0;
    cor[origem] = CINZA;

    while(!auxiliar.empty()){
        int vertice_analise = auxiliar.front();
        auxiliar.pop();

        for(int vizinho: grafo[vertice_analise]){
            if(cor[vizinho] == BRANCO){
                distancia_origem[vizinho] = distancia_origem[vertice_analise] + 1;
                cor[vizinho] = CINZA;
                auxiliar.push(vizinho);
            }
        }

        cor[vertice_analise] = PRETO;
    }
    return distancia_origem;
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj grafo(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    vetor distancias_origem = bfs(grafo, 2);
    for(int i = 0; i < n; i++){
        cout << "Distancia do vertice 3 para o vertice " << i << ": " << distancias_origem[i] << endl;
    }

    return 0;
}