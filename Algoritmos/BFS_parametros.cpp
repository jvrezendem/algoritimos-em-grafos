#include <iostream>
#include <vector>
#include <queue>


using namespace std;

using adj = vector<vector<int>>;
using vetor = vector<int>;

#define B 0
#define C 1
#define P 2

#define cores 1
#define distancias 2
#define pais 3

//algoritmo com O(V+E)

vetor BFS(const adj &lista_adjacencia, int raiz, int retorno){

    //define estruturas auxiliares
    int n = lista_adjacencia.size();
    vetor cor(n, B);
    vetor dist(n, 0);
    vetor pai(n, 0);
    queue<int> fila_auxiliar;

    try{
        if(raiz >= n)
            throw "Raiz inválida, o grafico não contem esse vértice";

        //troca a cor da raiz para cinza
        cor[raiz] = C;
        //distancia em ralação a raiz é 0
        dist[raiz] = 0;
        //não tem ancestral
        pai[raiz] = -1;
        //coloca a raiz dentro da fila de execução
        fila_auxiliar.push(raiz);

        while(!fila_auxiliar.empty()){
            int vertice_analizado = fila_auxiliar.front();
            //remove o vertice explorado
            fila_auxiliar.pop();
            cor[vertice_analizado] = C;
            
            //para cada vizinho do vertice analizado
            for(int vizinho: lista_adjacencia[vertice_analizado]){
                if(cor[vizinho] == B){
                    cor[vizinho] = C;
                    dist[vizinho] = dist[vertice_analizado] + 1;
                    pai[vizinho] = vertice_analizado;
                    fila_auxiliar.push(vizinho);
                }
            }

            cor[vertice_analizado] = P;

        }

        if(retorno == cores){
            return cor;
        }

        else if(retorno == distancias){
            return dist;
        }

        else if(retorno == pais){
            return pai;
        }

        else{
            throw "Opção Inválida";
        }
        
    }catch(string erro){
        cerr << "***ERRO: "<< erro << ".***"<< endl;
    }

    return vetor();
}

int main(){

    //definição do grafico G=(V,A)
    int V, A;
    cin>> V>> A;

    //define lista de adjacencias
    adj lista_adjacencia(V);

    //inserir arestas grafo orientado
    for(int i = 0; i < A; i++){
        int u, v;
        cin >> u >> v;
        lista_adjacencia[u].push_back(v);
        lista_adjacencia[v].push_back(u);
    }

    int retorno;
    cout << "Insitra o que quer retornar: |1-cores|2-distancias|3-pais|: " << endl;
    cin >> retorno;

    vetor resposta = BFS(lista_adjacencia, 13, retorno);

    for(int i = 0; i < resposta.size(); i++){


        cout << "vertice " << i << ": "<< resposta[i]<< endl;

    }

    return 0;
}