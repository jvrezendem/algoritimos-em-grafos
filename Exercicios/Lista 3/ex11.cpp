#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using vetor = vector<int>;
using adj = vector<vetor>;
using fila = queue<int>;

#define B 0
#define C 1
#define P 2

int diametro_arvore(adj &grafo, int raiz){

    int n = grafo.size();
    int diametro = 0;

    int mais_distante = -1;
    fila fila_bfs;
    vetor distancia(n, 0);
    vetor cor(n, B);

    //definindo cor da raiz
    cor[raiz] = C;
    fila_bfs.push(raiz);

    while(!fila_bfs.empty()){
        int vertice = fila_bfs.front();
        fila_bfs.pop();

        for(int vizinho: grafo[vertice]){
            if(cor[vizinho] == B){
                distancia[vizinho] = distancia[vertice]+1;
                if(distancia[vizinho] > diametro){
                    mais_distante = vizinho;
                    diametro = distancia[vizinho];
                }
                
                fila_bfs.push(vizinho);
                cor[vizinho] = C;
            }

            cor[vertice] = P;
        }
    }

    diametro = 0;

    cor.assign(n, B);
    distancia.assign(n, 0);
    fila_bfs.push(mais_distante);
    cor[mais_distante] = C;

    while(!fila_bfs.empty()){
        int vertice = fila_bfs.front();
        fila_bfs.pop();

        for(int vizinho: grafo[vertice]){
            if(cor[vizinho] == B){
                distancia[vizinho] = distancia[vertice]+1;
                if(distancia[vizinho] > diametro)
                    diametro = distancia[vizinho];
                
                fila_bfs.push(vizinho);
                cor[vizinho] = C;
            }

        }

        cor[vertice] = P;
    }

    return diametro;

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


    int diametro = diametro_arvore(grafo, 0);
    cout << "DIÂMETRO DA ÁRVORE: " << diametro << endl;


    return 0;
}