#include <iostream>
#include <vector>

using namespace std;
using vetor = vector<int>;
using adj = vector<vetor>;

#define B 0
#define C 1
#define P 2

void DFS_visita(adj &lista_adjacencia, int raiz, int &count_dfs, vetor &cor, vetor &tempo_descoberta, vetor &tempo_final, vetor &predecessor){
    
    count_dfs++;
    tempo_descoberta[raiz] = count_dfs;
    cor[raiz] = C;
    for(int vizinho: lista_adjacencia[raiz]){
        if(cor[vizinho] == B){
            predecessor[vizinho] = raiz;
            cor[vizinho] = C;
            tempo_descoberta[vizinho] = count_dfs;

            cout << "aresta (" << raiz << "," << vizinho << ") de arvore" << endl;

            DFS_visita(lista_adjacencia, vizinho,count_dfs ,cor, tempo_descoberta, tempo_final, predecessor);
        }
        else if(cor[vizinho] == C){
            cout << "aresta (" << raiz << "," << vizinho << ") de retorno" << endl;
        }

        else if(cor[vizinho] == P and tempo_descoberta[raiz] > tempo_descoberta[vizinho]){
            cout << "aresta (" << raiz << "," << vizinho << ") cruzada" << endl;
        }
    }

    count_dfs++;
    cor[raiz] = P;
    tempo_final[raiz] = count_dfs;
}

void DFS(adj &lista_adjacencia){


    int n = lista_adjacencia.size();
    //definição das estruturas auxiliares
    vetor cor(n, B);
    vetor tempo_descoberta(n, 0);
    vetor tempo_final(n, 0);
    vetor predecessor(n, -1);
    int contador_dfs = 0;

    for(int i = 0; i < n; i++){
        if(cor[i] == B){
            DFS_visita(lista_adjacencia, i,contador_dfs ,cor, tempo_descoberta, tempo_final, predecessor);
        }
    }
}

int main(){

    //definição do grafico G=(V,A)
    int V, A;
    cin>> V>> A;

    //define lista de adjacencias
    adj lista_adjacencia(V);

    //inserir arestas grafo orientado
    for(int i = 0; i < A; i++){
        int u, v;
        cin >> u >> v;
        lista_adjacencia[u].push_back(v);
    }

    DFS(lista_adjacencia);

    return 0;
}