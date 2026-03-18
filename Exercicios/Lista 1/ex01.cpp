#include <iostream>
#include <vector>

using namespace std;

int grau_maximo(const vector<vector<int>>& adj)
{
    int max_grau = 0;

    for(int i = 0; i < adj.size(); i++){
        int grau = adj[i].size();

        if(grau > max_grau)
            max_grau = grau;
    }

    return max_grau;
}

int main()
{

    //Define a lista
    int n = 4;
    vector<vector<int>> LA(n);

    LA[0].push_back(1);
    LA[0].push_back(2);

    LA[1].push_back(0);
    LA[1].push_back(2);
    LA[1].push_back(3);

    LA[2].push_back(0);
    LA[2].push_back(1);

    LA[3].push_back(1);

    cout << "Grau máximo do Grafo: " << grau_maximo(LA) << endl;

    return 0;
}