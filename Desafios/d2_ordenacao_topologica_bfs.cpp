#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define BRANCO 0
#define CINZA 1
#define PRETO 2

stack<int> bfs_ordenacao_topologica(vector<vector<int>> &lista_adjacencia)
{
    //definição das estruturas auxiliares
    vector<int> cor(lista_adjacencia.size());
    vector<int> grau(lista_adjacencia.size());
    stack<int> resposta;
    queue<int> fila;

    //definir os graus dos vertices
    for(int i = 0; i < lista_adjacencia.size(); i++){
        grau.push_back(lista_adjacencia[i].size());   
    }

    //escolher vertices de grau 0 para começar a resposta
    for(int i = 0; i < grau.size(); i++){
        if(grau[i] == 0){
            fila.push(i);
        }
    }

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
        resposta.push(u);

        for(auto vizinho: lista_adjacencia[u]){
            grau[vizinho]--;
            if(grau[vizinho] == 0){
                fila.push(vizinho);
            }
        }

    }

    return resposta;
    
}

int main(){
    
    int n;
    cin >> n;

    //lista de adjacencia
    vector<vector<int>> lista_adjacencia(n);

    for(int i = 0; i < n; i++){
        int vizinho = 0;
        cout << "vizinhos do vertice " << i <<": ";
        while(vizinho != -1){
            cin >> vizinho;
            if(vizinho != -1)
                lista_adjacencia[i].push_back(vizinho);
        }

        cout << "fim dos vizinhos do vertice "<<i<<endl;

    }

    stack<int> oredem_topologica = bfs_ordenacao_topologica(lista_adjacencia);

    cout << "Ordem topológica:" << endl;
    while(!oredem_topologica.empty()){
        int u = oredem_topologica.top();
        oredem_topologica.pop();
        cout <<  u<< " ";   
    }
    cout << endl;
    return 0;
}