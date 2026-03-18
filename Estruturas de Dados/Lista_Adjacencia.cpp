#include <iostream>
#include <vector>

using namespace std;

//descobrindo o grau de um vertice

int grau(int v, vector<vector<int>> &LA)
{
    return LA[v].size();
}

//determinando os vizinhos de um vertice
vector<int> vizinhos(int v, vector<vector<int>> &LA)
{
    return LA[v];
}

int main()
{
    //numero de vertices
    int n = 3;

    //definição da lista de adjacencia
    vector<vector<int>> listaAdj(n);

    /*
        ADICIONANDO ARESTAS ENTRE V E U
        listaAdj[v].push_back(u);
       
    */

    listaAdj[0].push_back(1);
    listaAdj[0].push_back(2);

    listaAdj[1].push_back(0);
    
    listaAdj[2].push_back(0);

    //imprimindo a lista de adjacencia
    for(int i = 0; i < n; i++)
    {
        cout << "Vertice " << i << ": ";
        for (int j = 0; j  < listaAdj[i].size(); j++)
        {
            cout << j << " ";
        }
        cout << endl;
        
    }

    //grau dos vertices
    cout << "Grau dos vertices:" << endl;
    cout << "Vertice 0: " << grau(0, listaAdj) << endl;
    cout << "Vertice 1: " << grau(1, listaAdj) << endl;
    cout << "Vertice 2: " << grau(2, listaAdj) << endl;
    

    return 0;
}