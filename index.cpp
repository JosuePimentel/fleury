#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;

void limparTerminal();
int ver_adj(vector<vector<int>>&G, int V_Prox, int v);
void fleury(vector<vector<int>>&G, vector<int>&G_Visitado, int e, int v);

int main() {
    int v,e;

    limparTerminal();
    printf("Obs -> Insira um Grafo nas seguintes condicoes:\n* Quantidade de arestas de cada vertices tem que ser par.\n* Grafo conexo.\n* Os vertices vao de 1 ate n\n\n");
    printf("Escreva a quantidade de vertices(v) e quantidade de arestas(e) do Grafo(G): ");
    cin >> v >> e;
    vector<vector<int>> G(v, vector<int>(v, 0));

    // Faz a ligação das arestas entre os vertices
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

    //Codigo de fleury
    vector<int> G_Visitado;
    fleury(G, G_Visitado, e, v);

    //Escreve o caminho encontrado
    printf("Caminho euleriano encontrado: ");
    for (int i = 0; i < G_Visitado.size(); i++)
    {
        printf("%i ", G_Visitado[i] + 1);
    }
    cout << endl;
}

void fleury(vector<vector<int>>&G, vector<int>&G_Visitado, int e, int v) {
    int V_Atual = 0, i;
    G_Visitado.push_back(V_Atual);

    //Enquanto a quantidade de grafos visitados for menor que o numero de arestas + 1
    while(G_Visitado.size() < e+1)
    { 
        //Percorrendo as arestas do Vertice Atual
        for(i = 0; i < v; i++)
        {   
            if(G[V_Atual][i])
            {
                if( ver_adj(G, i, v) > 1 || ver_adj(G, V_Atual, v) <= 1 )
                {
                    G[V_Atual][i] = 0;
                    G[i][V_Atual] = 0;
                    G_Visitado.push_back(i);
                    V_Atual = i;

                    break;
                }
            }
        }
    }
}

//Funcao de ver a quantidade de adj de um vertice
int ver_adj(vector<vector<int>>&G, int V_Prox, int v) {
    int qtd_adj = 0;
    for(int i = 0; i < v; i++)  
        if(G[V_Prox][i])
            qtd_adj++;

    return qtd_adj;
}

void limparTerminal() {
    system("cls || clear");
}
