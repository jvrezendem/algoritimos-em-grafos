#include <iostream>
#include <vector>
#include <stack>

using namespace std;

using vetor = vector<int>;
using adj = vector<vetor>;


void dfs_visit(int vertice, adj &lsita_adjacencia, stack<int> &ordem_tempos, vector<bool> &visitado, int &contador_dfs){
    
    visitado[vertice] = true;
    contador_dfs++;

    for(int v: lsita_adjacencia[vertice]){
        if(!visitado[v]){
            dfs_visit(v, lsita_adjacencia, ordem_tempos, visitado, contador_dfs);
        }
    }

    contador_dfs++;
    ordem_tempos.push(vertice);
}

void dfs(adj &lista_adjacencia, stack<int> &ordem_tempos, int &contador_dfs, vector<bool> &visitado){

    for(int v = 0; v < lista_adjacencia.size(); v++){
        if(!visitado[v]) 
            dfs_visit(v, lista_adjacencia, ordem_tempos, visitado, contador_dfs);
    }
}

adj transpor_grafo(adj lista_adjacencia){

    adj transposto(lista_adjacencia.size());

    for(int v = 0; v < lista_adjacencia.size();v++){
        for(int vizinho: lista_adjacencia[v]){
            transposto[vizinho].push_back(v);
        }
    }

    return transposto;
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
    int contador_dfs = 0;
    vector<bool> visitado(n, false);
    vetor tempo_termino(n, 0);
    stack<int> ordem_tempos;

    //realizar primeira dfs;
    dfs(lista_adjacencia, ordem_tempos, contador_dfs, visitado);

    //transpor o grafo
    adj transposto = transpor_grafo(lista_adjacencia);
    vector<bool> visitado_transposto(n, false);

    //realizar dfs no grafo transposto a partir da ordem da pilha
    while(!ordem_tempos.empty()){
        int v_atual = ordem_tempos.top();
        ordem_tempos.pop();

        //criar pilha da cfc
        stack<int> cfc;

        if(!visitado_transposto[v_atual]){
            dfs_visit(v_atual, transposto, cfc, visitado_transposto, contador_dfs);

            cout << "Componente Fortemente Conexa: ";

            while(!cfc.empty()){
                int v = cfc.top();
                cfc.pop();

                cout << v << " ";
            }
            cout << endl;
        }
    }
}