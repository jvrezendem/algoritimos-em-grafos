#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define BRANCO 0
#define CINZA 1
#define PRETO 2

void dfs_visit(vector<vector<int>> &matriz_adjacencia, int vertice, vector<int> &cor, int bloqueado)
{
    if(vertice == bloqueado) return;


    cor[vertice] = CINZA;

    for(int vizinho = 0; vizinho < matriz_adjacencia.size(); vizinho++){
        if(matriz_adjacencia[vertice][vizinho] == 1 && cor[vizinho] == BRANCO){
            dfs_visit(matriz_adjacencia, vizinho, cor, bloqueado);
        }
    }
    cor[vertice] = PRETO;
}

vector<int> dfs(vector<vector<int>> &matriz_adjacencia, int vertice, int bloqueado)
{

    vector<int> cor(matriz_adjacencia[0].size(), BRANCO);
    dfs_visit(matriz_adjacencia, vertice, cor, bloqueado);

    return cor;
}

int main() {

    int T, N;

    cin >> T >> N;
    vector<vector<int>> matriz_adjacencia(N, vector<int>(N));

    for(int i = 0; i < T; i++)
    {
        for(int j = 0; j <N; j++){
            for(int k = 0; k < N; k++){
                cin >> matriz_adjacencia[j][k];
            }
        }


        //realiza a busca em profundiade
        vector<int> cor_original = dfs(matriz_adjacencia, 0, -1);

        vector<vector<char>> resposta(N, vector<char>(N, 'N'));


        cout << "Case" << i+1 << endl; 

         string linha = "+";
        for (int i = 0; i < 2 * N - 1; i++) 
            linha += "-";
        linha += "+";

        cout << linha << endl;

        for (int bloqueado = 0; bloqueado < N; bloqueado++) {
            vector<int> cor_bloqueado = dfs(matriz_adjacencia, 0, bloqueado);

            for (int y = 0; y < N; y++) {
                if (cor_original[y] != BRANCO && cor_bloqueado[y] == BRANCO)
                    resposta[bloqueado][y] = 'Y';
                else
                    resposta[bloqueado][y] = 'N';
            }
        }

        for (int i = 0; i < N; i++) {
            cout << "|";
            for (int j = 0; j < N; j++) {
                cout << resposta[i][j] << "|";
            }
            cout << endl;
            cout << linha << endl;
        }
    }
    return 0;
}