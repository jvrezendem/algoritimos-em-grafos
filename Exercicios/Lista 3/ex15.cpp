#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
const int MAX_PONTOS = 10000;

// Estrutura da malha urbana
vector<int> mapa[MAX_PONTOS];
int distancia[MAX_PONTOS];
bool inserido_na_fila[MAX_PONTOS];

void calcular_distancias_ambulancia(int origem, int n)
{
    // Inicializacao do estado do mapa
    for (int i = 0; i < n; i++)
    {
        distancia[i] = INF;
        inserido_na_fila[i] = false;
    }

    queue<int> fila;

    // Configuracao do ponto de partida ( Central de Ambulancias )
    distancia[origem] = 0;
    inserido_na_fila[origem] = true; // MARCACAO IMEDIATA NA ORIGEM
    fila.push(origem);

    while (!fila.empty())
    {
        int u = fila.front();
        fila.pop();
        inserido_na_fila[u] = true;

        for (int v : mapa[u])
        {
            // Se o ponto de intersecao ainda nao foi " descoberto " pela BFS
            if (!inserido_na_fila[v])
            {
                distancia[v] = distancia[u] + 1;
                fila.push(v);
                inserido_na_fila[v] = true;
            }
        }
    }
}

int main()
{
    int n = 5; // Exemplo com 5 cruzamentos

    // Simulacao da malha viaria
    mapa[0].push_back(1);
    mapa[0].push_back(2);
    mapa[1].push_back(3);
    mapa[2].push_back(1);
    mapa[2].push_back(4);
    mapa[3].push_back(4);

    int central = 0;
    calcular_distancias_ambulancia(central, n);

    cout << " --- RELATORIO DE ACESSIBILIDADE ( DISTANCIAS ) ---" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " Cruzamento " << i << ": ";
        if (distancia[i] == INF)
            cout << " Inalcancavel " << endl;
        else
            cout << distancia[i] << " via(s)" << endl;
    }
    return 0;
}
