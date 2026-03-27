#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

stack<int> bfs_ordenacao_topologica(vector<vector<int>> &lista_adjacencia)
{
    //definição das estruturas auxiliares
    vector<int> grau(lista_adjacencia.size(), 0);
    stack<int> resposta;
    queue<int> fila;

    //definir os graus dos vertices
    for(int i = 0; i < lista_adjacencia.size(); i++){
        for(auto vizinho: lista_adjacencia[i])
            grau[vizinho]++;  
    }

    //escolher vertices de grau 0 para começar a resposta
    for(int i = 0; i < lista_adjacencia.size(); i++){
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
    
    int n = 9;

    //lista de adjacencia
    vector<vector<int>> lista_adjacencia(n);

    lista_adjacencia[0].push_back(1);
    lista_adjacencia[0].push_back(4);

    lista_adjacencia[1].push_back(2);
    lista_adjacencia[1].push_back(4);

    lista_adjacencia[2].push_back(8);

    lista_adjacencia[3].push_back(4);

    lista_adjacencia[6].push_back(7);
    lista_adjacencia[6].push_back(2);

    lista_adjacencia[7].push_back(8);

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