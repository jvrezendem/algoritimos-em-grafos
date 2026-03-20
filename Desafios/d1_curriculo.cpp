#include <iostream>
#include <vector>

using namespace  std;

void imprime_matriz(vector<vector<int>> &matrix, int n)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> matriz_alcançabilidade(vector<vector<int>> &MA)
{
    int n = MA[0].size();

    vector<vector<int>> MAlc = MA;

    //algoritmo de Warshall
    for(int k = 0; k < n; k++){        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(MAlc[i][k] == 1 and MAlc[k][j] == 1)
                    MAlc[i][j] =1;
            }
        }
    }

    return MAlc;

}

int main()
{

    vector<vector<int>> MA = {
        {0, 1, 0, 0}, 
        {0, 0, 1, 0}, 
        {0, 0, 0, 1}, 
        {0, 0, 0, 0}
    };

    /*
        DISCIPLINAS:
        0 - Algoritmos
        1 - Estrutura de Dados
        2 - Grafos
        3 - Mineração de Dados
        
        RELAÇÕES:
        Algoritmos → Estruturas de Dados
        Estruturas de Dados → Grafos
        Grafos → Mineração de Dados

    */

    cout << "Matriz de Alcançabilidade: " << endl;

     vector<vector<int>> MAlc = matriz_alcançabilidade(MA);

    imprime_matriz(MAlc, 4);

    return 0;
}