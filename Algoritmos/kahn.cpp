#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
using vetor = vector<int>;
using adj = vector<vetor>;
using pilha = stack<int>;
using fila = queue<int>;

pilha ordem_topologica_Kahn(adj &lista_adjacencia){

    int n = lista_adjacencia.size();
    pilha ordem_topologica;
    fila fila_auxiar;
    vetor grau_entrada(n, 0);

    for(int i = 0; i < n; i++){
        for(auto vizinho: lista_adjacencia[i]){
            grau_entrada[vizinho]++;
        }
    }

    for(int i = 0; i < n; i++){
        if(grau_entrada[i] == 0){
            fila_auxiar.push(i);
        }
    }

    while(!fila_auxiar.empty()){
        int vertice_atual = fila_auxiar.front();
        fila_auxiar.pop();
        ordem_topologica.push(vertice_atual);

        for(int vizinho: lista_adjacencia[vertice_atual]){
            grau_entrada[vizinho]--;
            if(grau_entrada[vizinho] == 0){
                fila_auxiar.push(vizinho);
            }
        }
    }

    return ordem_topologica;
}


int main(){

    int n, m;
    cin >> n >> m;
    adj lista_adjacencia(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        lista_adjacencia[u].push_back(v);
    }

    pilha ordem_topologica = ordem_topologica_Kahn(lista_adjacencia);

    //printar a ordem topologica
    while(!ordem_topologica.empty()){
        cout << ordem_topologica.top() << " ";
        ordem_topologica.pop();
    }

    return 0;
}