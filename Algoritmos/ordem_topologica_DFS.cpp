#include <iostream>
#include <vector>
#include <stack>

//algoritmo de ordenação topológica utilizando DFS
//complexidade: O(V + E)
//obs: o grafo deve ser acíclico para que a ordenação topológica seja possível

using namespace std;
using vetor = vector<int>;
using adj = vector<vetor>;
using pilha = stack<int>;

#define B 0
#define C 1
#define P 2

void visita_DFS(adj &lista_adjacencia, int raiz, vetor &cor, pilha &ordem_topologica){

    cor[raiz] = C;

    for(int vizinho: lista_adjacencia[raiz]){
        if(cor[vizinho] == B)
            visita_DFS(lista_adjacencia, vizinho, cor, ordem_topologica);
    }

    cor[raiz] = P;
    ordem_topologica.push(raiz);
}

pilha ordem_topologica_DFS(adj &lista_adjacencia){

    int n = lista_adjacencia.size();


    vetor cor(lista_adjacencia.size(), B);
    pilha ordem_topologica;

    for(int i = 0; i < n; i++){
        if(cor[i] == B){
            visita_DFS(lista_adjacencia, i, cor, ordem_topologica);
        }
    }

    return ordem_topologica;
}


int main (){
    int n, m;
    cin >> n >> m;

    adj lista_adjacencia(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        lista_adjacencia[u].push_back(v);
    } 

    pilha ordem_topologica = ordem_topologica_DFS(lista_adjacencia);
    while(!ordem_topologica.empty()){
        cout << ordem_topologica.top() << " ";
        ordem_topologica.pop();
    }

    return 0;
}