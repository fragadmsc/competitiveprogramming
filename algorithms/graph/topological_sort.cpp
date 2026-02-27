#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010

/*
This is an algorithm to sort the vertexes in a graph topologically, qhere we only take out the graph the vertexes that dont have any edges arriving to them*/

vector<int> grafo[MAXN], ordem;
int grau[MAXN], n;//we must initialize the grau[i] with the nuber of edges that arrive in the vertex i

void topological_sort() {
    queue<int> fila;
    for(int i=1;i<=n;i++) {//here we push the vertex that already has grau 0
        if(grau[i]==0) {
            fila.push(i);
            ordem.push_back(i);
        }
    }
    while(!fila.empty()) {
        int v=fila.front();
        fila.pop();
        for(auto i : grafo[v]) {//if we take out a vertex and the garu of its neighbour becomes 0, we push him in the queue also
            grau[grafo[v][i]]--;
            if(grau[grafo[v][i]]==0) {
                ordem.push_back(grafo[v][i]);
                fila.push(grafo[v][i]);
            }
        }
    }
}//in the end the vector ordem has the order in witch we can take out the vertexes
//if the vector ordem has size less than n, this means the graph has a cycle
