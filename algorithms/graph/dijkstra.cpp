#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000
#define pii pair<int,int>
#define inf 1000000000

int dist[MAXN], mark[MAXN], n;
vector<pii> grafo[MAXN];
priority_queue<pii,vector<pii>,greater<pii>> pq;

void djikstra(int s) { //definimos s como o vetor de onde sairemos
    for(int i=1;i<=n;i++) {//definimos todas as distancias inicialmente como inf pois nao conhecemos nenhum caminho para elas
        dist[i]=inf;
    }
    pq.push(make_pair(0,s));
    while(!pq.empty()) {
        int v=pq.top().second;//vemos o vertice com menor distancia atual
        pq.pop();
        if(mark[v]) continue; //vemos se ele ja foi visitado, e temos certeza da menor distancia
        mark[v]=1;
        for(auto i : grafo[v]) {//i representa a aresta ligada a v, i.first eh a aresta e i.second eh o peso
            int w=grafo[v][i.first].second;
            int x=grafo[v][i.first].first;
            if(dist[x]>dist[v]+w) {//essa condicao eh a mais basica, mas dependendo do problema pode ser necessario usar outro tipo de condicao
                dist[x]=dist[v]+w;
                pq.push(make_pair(dist[x],x));
                //nessa parte do algoritmo tambem é possivel inseriri informacoes, como o pai de x ou outra informacao
            }
        }
    }
} // ao final do algoritmo o vetor dist armazena a menor distancia para aquele vertice partindo de s
//a complexidade do algoritmo eh O(m*logn), pois faremos o processo para todas as aretas(duas vezes) e cada operacao na pq custa logn
