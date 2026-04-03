#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using adj = vector<vector<int>>;
using vetor = vector<int>;
using fila = queue<int>;

#define COR1 1
#define COR2 2

int main(){

    int caso = 0, v, a;
    adj lista_adjacencia;
    vetor cor;

    while(cin >> v and v != 0){
        cin >> a;
        lista_adjacencia.clear();
        string resultado = "BICOLORABLE.";
        cor.clear();

        lista_adjacencia.resize(v);
        cor.resize(v, 0);
        fila fila_bfs;

        for(int i = 0; i < a; i++){
            int u, w;
            cin >> u >> w;
            lista_adjacencia[u].push_back(w);
            lista_adjacencia[w].push_back(u);
        }

        for(int i = 0; i < v; i++){
            if(cor[i] == 0){
                cor[i] = COR1;
                fila_bfs.push(i);

                while(!fila_bfs.empty()){
                    int vertice = fila_bfs.front();
                    fila_bfs.pop();

                    for(int vizinho : lista_adjacencia[vertice]){
                        
                        if(cor[vizinho] == 0){
                            fila_bfs.push(vizinho);
                            if(cor[vertice] == COR1) cor[vizinho] = COR2;
                            if(cor[vertice] == COR2) cor[vizinho] = COR1;
                        }

                        if((cor[vertice] == COR1 and cor[vizinho] == COR1) or (cor[vertice] == COR2 and cor[vizinho] == COR2)){
                            resultado = "NOT BICOLORABLE.";
                        }

                    }
                }
            }
        }

        cout << resultado << endl;
    
    }
}