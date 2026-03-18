#include <iostream>
#include <vector>

using namespace std;

bool vertice_isolado(int v, const vector<vector<int>>& adj)
{
    if(adj[v].size() == 0)
        return true;
    return false;
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

    LA[2].push_back(0);
    LA[2].push_back(1);

    cout << "Verifica se o vértice 3 está isolado: " << vertice_isolado(3, LA) << endl;
    return 0;
}