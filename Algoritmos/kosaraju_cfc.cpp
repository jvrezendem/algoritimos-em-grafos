#include <iostream>
#include <vector>
#include <queue>
#include <stack>

//algoritmo de definição de componentes fortemente conexas utilizando o algoritmo de kosaraju
using namespace std;
using vetor = vector<int>;
using adj = vector<vetor>;
using pilha = stack<int>;
using fila = queue<int>;

void dfs_visit(adj &lista_adjacencia, vetor &visitados, int vertice_atual, vetor &tempo_termino, int &contador_tempo, pilha &ordem_maior_termino){
    visitados[vertice_atual] = 1;
    contador_tempo++;

    for(int vizinho: lista_adjacencia[vertice_atual]){
        if(visitados[vizinho] == 0){
            dfs_visit(lista_adjacencia, visitados, vizinho, tempo_termino, contador_tempo, ordem_maior_termino);
        }
    }

    contador_tempo++;
    tempo_termino[vertice_atual] = contador_tempo;
    ordem_maior_termino.push(vertice_atual);
}

void dfs(adj &lista_adjacencia){

    int n = lista_adjacencia.size();
    vetor visitados(n, 0);
    vetor tempo_termino(n, 0);
    int contador_tempo = 0;
    pilha ordem_maior_termino;

    for(int i = 0; i < n; i++){
        if(visitados[i] == 0){
            //chamar dfs para o vertice i
            dfs_visit(lista_adjacencia, visitados, i, tempo_termino, contador_tempo, ordem_maior_termino);
        }
    }

    //transpor o grafo
    adj grafo_transposto(n);
    for(int i = 0; i < n; i++){
        for(int vizinho: lista_adjacencia[i]){
            grafo_transposto[vizinho].push_back(i);
        }
    }

    //nova dfs para cada vertice na ordem de maior tempo de termino
    vetor visitados_transposto(n, 0);
    while(!ordem_maior_termino.empty()){
        int vertice_atual = ordem_maior_termino.top();
        ordem_maior_termino.pop();
        pilha componete_conexa;

        if(visitados_transposto[vertice_atual] == 0){
            //chamar dfs para o vertice atual no grafo transposto
            dfs_visit(grafo_transposto, visitados_transposto, vertice_atual, tempo_termino, contador_tempo, componete_conexa);

            //imprimir a componente conexa
            cout << "Componente fortemente conexa: ";
            while(!componete_conexa.empty()){
                cout << componete_conexa.top() << " ";
                componete_conexa.pop();
            }
        }

    }

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

    dfs(lista_adjacencia);

    return 0;
}