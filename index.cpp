#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;

void limparTerminal();
int ver_adj(vector<vector<int>>&G, int V_Prox, int v);

int main() {
    int v,e;

    limparTerminal();
    printf("Obs -> Insira um Grafo nas seguinte condicao:\n* Quantidade de arestas de cada vertices tem que ser par.\n* Grafo conexo.\n\n");
    printf("Escreva a quantidade de vertices(v) e quantidade de arestas(e) do Grafo(G): ");
    cin >> v >> e;

    vector<vector<int>> G(v, vector<int>(v, 0));

    for(int i = 0; i < e; i++)
    {
        printf("Escreva as arestas, do vertice inicial para o vertice final.\n");
        printf("Vertice Inicial Vertice Final: ");
        int from, to;
        cin >> from >> to;
        G[from-1][to-1]++;
        G[to-1][from-1]++;
        limparTerminal();
    }

    // for(int i = 0; i < v; i++)
    // {
    //     for (int j = 0; j < v; j++)
    //     {
    //         cout << G[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    vector<int> G_Visitado;
    int V_Atual = 0, i, teste;

    G_Visitado.push_back(V_Atual);

    while(G_Visitado.size() <= e+1)
    { 
        for(i = 0; i < v; i++)
        {   
            if(G[V_Atual][i])
            {
                // cout << V_Atual << endl;
                if( ver_adj(G, i, v) > 2 || ver_adj(G, V_Atual, v) < 2 )
                {
                    cout << 'a' << endl;
                    G[V_Atual][i] = 0;
                    G[i][V_Atual] = 0;
                    G_Visitado.push_back(i);
                    V_Atual = i;

                    cin >> teste;

                    break;
                }
            }
        }
    }

    for (int i = 0; i < G_Visitado.size(); i++)
    {
        cout << G_Visitado[i] << ' ';
    }
    
}

int ver_adj(vector<vector<int>>&G, int V_Prox, int v) {
    int qtd_adj = 0;
    for(int i = 0; i < v; i++)  
        if(G[V_Prox][i])
            qtd_adj++;
    // cout << 'a' << endl;
    // for(int i = 0; i < v; i++)
    // {
    //     for (int j = 0; j < v; j++)
    //     {
    //         cout << G[i][j] << ' ';
    //     }
    //     cout << "\n";
    // }
    // cout << "\n\n";

    return qtd_adj;
}

void limparTerminal() {
    system("cls || clear");
}