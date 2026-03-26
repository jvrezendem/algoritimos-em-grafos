#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define NAO_VISITADO 0

int raiz;
vector<bool> articulacao;

void tarjan(vector<vector<int>> &lista_adjacencia, int origem, vector<int> &low, vector<int> &d, vector<int> &pai, int &cont_dfs, int &filhos_raiz)
{
    low[origem] = d[origem] = cont_dfs++;

    for(auto vizinho : lista_adjacencia[origem]){
        if(d[vizinho] == NAO_VISITADO){
            pai[vizinho] = origem;

            if(origem == raiz){
                filhos_raiz++;
            }

            tarjan(lista_adjacencia, vizinho, low, d, pai, cont_dfs, filhos_raiz);

            if(low[vizinho] >= d[origem])
            {
                articulacao[origem] = true;
            }

            if(low[vizinho] > d[origem])
            {
                cout << "Ponte (" << origem << ", " << vizinho << ") " << endl; 
            }

            low[origem] = min(low[origem], low[vizinho]);

        }

        else if(vizinho != pai[origem])
        {
            low[origem] = min(low[origem], d[vizinho]);
        }
    }
}

int main()
{

    int n_vertices, m_arestas;
    cin >> n_vertices >> m_arestas ;
    //estruturas auxiliares
    vector<int> low(n_vertices, NAO_VISITADO);
    vector<int> d(n_vertices, NAO_VISITADO);
    vector<int> pai(n_vertices, -1);
    int cont_dfs = 1;
    int filhos_raiz = 0;
    articulacao.assign(n_vertices, false);



    vector<vector<int>> lista_adjacencia(n_vertices);

    int u, v;
    for(int i = 0; i < m_arestas; i++)
    {
        cin >> u >> v;

        lista_adjacencia[u].push_back(v);
        lista_adjacencia[v].push_back(u);
    }

    //aplicação do algoritmo
    for(int i = 0; i < n_vertices; i++){

        if(d[i] == NAO_VISITADO){
            raiz = i;
            filhos_raiz = 0;
            tarjan(lista_adjacencia, i, low, d, pai, cont_dfs, filhos_raiz);

            articulacao[i] = (filhos_raiz > 1);
        }
    }

    for(int i = 0; i < n_vertices; i++)
    {
        if(articulacao[i])
            cout << "vertice de articulacao: " << i << endl;
    }

    return 0;
}