#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

using vetor = vector<int>;
using adj = vector<vector<int>>;
using pilha = stack<int>;

int qtd_cfc = 0;

void tarjan_cfc(adj &lista_adjacencia, vetor &low, vetor &d, int &contador_dfs, pilha &pilha_dfs, vector<bool> &na_pilha, int vertice)
{

    pilha_dfs.push(vertice);
    low[vertice] = d[vertice] = ++contador_dfs;
    na_pilha[vertice] = true;

    for(int vizinho: lista_adjacencia[vertice]){
        if(d[vizinho] == 0){
            tarjan_cfc(lista_adjacencia, low, d, contador_dfs, pilha_dfs,na_pilha,vizinho);
            low[vertice] = min(low[vertice], low[vizinho]);
        }else if(na_pilha[vizinho]){
            low[vertice] = min(low[vertice], d[vizinho]);
        }
    }


    if(low[vertice] == d[vertice]){
        qtd_cfc++;
        while(true){
            int u = pilha_dfs.top();
            pilha_dfs.pop();
            na_pilha[u] = false;

            if(u == vertice) break;
        }
    }
    
}


int main(){

    int n, m, p;

    while(cin >> n >> m){
        if (n == 0 and m == 0) break;
        adj lista_adjacencia(n+1);
        pilha pilha_dfs;
        int v, w;
        int g = 1;
        for(int i = 1; i <= m; i++){
            cin >> v >> w >> p;
            lista_adjacencia[v].push_back(w);
            if(p == 2) lista_adjacencia[w].push_back(v);
        }

        vetor low(n+1, 0);
        vetor d(n+1, 0);
        int contador_dfs = 0;
        vector<bool> na_pilha(n + 1, false);      

        for(int i = 1; i <= n; i++){
            if(d[i] == 0) tarjan_cfc(lista_adjacencia, low, d, contador_dfs,pilha_dfs, na_pilha, i);
        }

        if(qtd_cfc != 1) g = 0;

        cout << g << endl;

        qtd_cfc = 0;

    }
}