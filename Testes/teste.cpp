#include <iostream>
#include <vector>

using namespace std;

int grau(int v, vector<vector<int>> MA, int n){
    int res = 0;
    for(int i = 0; i < n; i++){
        res += MA[v-1][i];
    }

    return res;
}

int main(){

    const int n = 4;
    vector<vector<int>> matrix = {{0, 1, 1, 1}, {1, 0, 0, 1}, {1, 0, 0, 0}, {1, 1, 0, 0}};

    int grau_vertice = grau(1, matrix, 4); 

    cout << "Grau do vertice " << 1 << " é " << grau_vertice;

    return 0;
}