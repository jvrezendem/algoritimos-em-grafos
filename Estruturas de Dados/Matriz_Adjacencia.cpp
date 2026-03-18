#include <iostream>
#include <vector>

using namespace std;

//determinar o grau de um vertice de um grafo não direcionado
int grau_vertice_nao_direcionado(int v, vector<vector<int>> &MA)
{
    int grau = 0;
    for(int i = 0; i < MA[v].size(); i++){
        if(MA[v][i])
            grau++;
    }

    return grau;
}

//determinar o grau de vertice de um grafo direcionado
int grau_vertice_direcionado(int v, vector<vector<int>> &MA)
{
    int grau_saida = 0, grau_entrada = 0, grau = 0;;
    for(int i = 0; i < MA[v].size(); i++){
        if(MA[v][i])
            grau_saida++;
    }

    for(int j = 0; j < MA[v].size(); j++){
        if(MA[j][v])
            grau_entrada++;
    }

    grau = grau_entrada + grau_saida;

    return grau;
}


//determinar vizinhos de um vertice em grafo nao direcionado
vector<int> vizinhos_n_direcionado(int v, vector<vector<int>> &MA)
{
    vector<int> vizinhos;
    for(int i = 0; i < MA[v].size(); i++){
        if(MA[v][i] == 1)
            vizinhos.push_back(i);
    }

    return vizinhos;
}

//determinar vizinhos de um vertice em grafo direcionado
vector<int> vizinhos_direcionado(int v, vector<vector<int>> &MA)
{
    vector<int> vizinhos;
    bool control = true;

    for(int i = 0; i < MA[v].size(); i++){
        if(MA[v][i] == 1)
            vizinhos.push_back(i);
    }

    for(int j = 0; j < MA[v].size(); j++){
        if(MA[j][v] == 1)
        {
            for(int u = 0; u < vizinhos.size(); u++){
                if(j == vizinhos[u])
                    control = false;    
            }
            if (control)
                vizinhos.push_back(j);
        }
        control = true;
    }

    return vizinhos;
}

int main()
{
    //numero de vertices
    int n = 4;

    //definição da matriz de adjacencia cheia de 0
    vector<vector<int>> matrizAdj(n, vector<int>(n, 0));
    
    /*
        ADICIONANDO ARESTAS ENTRE U E V
        matrizAdj[u][v] = 1
        matrzAdj[v][u] = 1
    */

    matrizAdj[0][3] = 1;
    matrizAdj[0][1] = 1;
    matrizAdj[1][3] = 1;
    matrizAdj[2][3] = 1;

    //imprime a matriz
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<< matrizAdj[i][j] << " ";
        }
        cout << endl;
    }

    //informando o grau dos vertices
    cout << "Vertice 1: " << grau_vertice_direcionado(0, matrizAdj) << endl;
    cout << "Vertice 2: " << grau_vertice_direcionado(1, matrizAdj) << endl;
    cout << "Vertice 3: " << grau_vertice_direcionado(2, matrizAdj) << endl;
    cout << "Vertice 4: " << grau_vertice_direcionado(3, matrizAdj) << endl;

    //informando os vizinhos dos vertices

    vector<int> vizinhos = vizinhos_direcionado(3, matrizAdj);
    cout << "Vizinhos Vertice 4: ";
    for(int i = 0; i < vizinhos.size(); i++){
        cout << vizinhos[i] << " ";
    }
    cout << endl;
    
    return 0;
}