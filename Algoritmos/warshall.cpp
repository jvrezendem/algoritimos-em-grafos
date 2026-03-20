#include <iostream>
#include <vector>

using namespace  std;

vector<vector<int>> warshall(vector<vector<int>> &matriz_adjacencia, int n)
{

    vector<vector<int>> matriz_alcançabilidade = matriz_adjacencia;
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matriz_alcançabilidade[i][j] = matriz_alcançabilidade[i][j] or (matriz_alcançabilidade[i][k] and matriz_alcançabilidade[k][j]);
            }
        }
    }
    return matriz_alcançabilidade;

}

int main()
{

    //definir a matriz de adjacências
    vector<vector<int>> MA = {
        {0, 1, 0, 0}, 
        {0, 0, 1, 0}, 
        {0, 0, 0, 1}, 
        {0, 0, 0, 0}
    };

    return 0;
}