#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int grau_saida(int v, vector<tuple<int, int, int>> &MI)
{
    int count = 0;
    
    for(int i = 0; i < MI.size(); i++){

        if(get<1>(MI[i]) == v)
            count++;
    }

    return count;
}

int main()
{

    vector<tuple<int, int, int>> matrizInc;

    /*
        ADICIONAR ARESTAS ENTRE U E V
        matrizInc.push_back(make_tuple(id,u,v))

        =>É comum colocar um identificador para a aresta na tupla
    */

    matrizInc.push_back(make_tuple(0, 0, 1));
    matrizInc.push_back(make_tuple(1, 0, 2));
    matrizInc.push_back(make_tuple(2, 2, 1));
    matrizInc.push_back(make_tuple(3, 2, 3));
    matrizInc.push_back(make_tuple(4, 3, 1));

    for(int i = 0; i < matrizInc.size(); i++){
        int id_aresta = get<0>(matrizInc[i]);
        int saida = get<1>(matrizInc[i]);
        int entrada = get<2>(matrizInc[i]);

        cout << "Aresta: " << id_aresta << " | " << saida << " --> " << entrada << endl;
    }

    cout << "Grau de saida o vértice 0: " << grau_saida(0, matrizInc) << endl;

    return 0;
}