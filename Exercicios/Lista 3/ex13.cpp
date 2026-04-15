#include <iostream>
#include <vector>

using namespace std;

using vetor = vector<int>;
using adj = vector<vetor>;

#define B 0
#define C 1
#define P 2

void dfs_visit(adj &lista_adjacencia, vetor &cor, int vertice, bool &ciclo, vetor &pai){
    cor[vertice] = C;

    for(int vizinho: lista_adjacencia[vertice]){
        pai[vizinho] = vertice;
        if(cor[vizinho] == B){
            cor[vizinho] = C;
            dfs_visit(lista_adjacencia, cor,vizinho, ciclo, pai);

        }else if(cor[vizinho] != B and vizinho != pai[vizinho]) ciclo = true;
    }

    cor[vertice] = P;
}

bool dfs(adj &lista_adjacencia){
    int n = lista_adjacencia.size();
    vetor cor(n, B);
    vetor pai(n, -1);
    bool ciclo = false;



    for(int i = 0; i < n; i++){
        if(cor[i] == B){
            dfs_visit(lista_adjacencia, cor ,i, ciclo, pai);
        }
    }

    return ciclo;
}

bool contem_ciclos(adj &lista_adjacencia){
    int arestas = 0;
    int n = lista_adjacencia.size();
    for(int i = 0; i < n; i++){
        arestas += lista_adjacencia[i].size();
    }
    arestas = arestas/2;

    if(arestas < n)
        return false;
    else
        return dfs(lista_adjacencia);
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

    int ciclo = contem_ciclos(grafo);

    if(ciclo) cout << "O grafo possui ciclo!" << endl;
    else cout << "O grafo não possui ciclo!" << endl;
    

    return 0;
}