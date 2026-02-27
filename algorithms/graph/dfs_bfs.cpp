#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000
/*
This is a program about search in graphs, using two algorithms, dfs(depth first search) and bfs(breadth first search)
Both have a time complexity of O(m+n), where m is the number of edges in the graph and m is the number of vertices, but the dfs is usually a little faster
*/

vector<int> grafo[MAXN]; //listt of adjacency
int componente[MAXN];

void dfs(int x) {
    for(auto i : grafo[x]) { //
        int v=grafo[x][i];//vertex that is connect to x
        if(componente[v] != -1) {
            componente[v]=componente[x];
            //here you can do anything you want, depending on the problem
            //common things to do are define the parent of a vertex, the level, etc.
            dfs(v);
        }
    }
}


queue<int> fila;

void bfs(int x) {
    fila.push(x);
    while(!fila.empty()) {
        int v=fila.front();//next vertex to be analised
        fila.pop();
        for(auto i : grafo[v]) { //
            int z=grafo[v][i];//vertex that is connect to x
            if(componente[z] != -1) {
                componente[z]=componente[v];
                //here you can do anything you want, depending on the problem
                //common things to do are define the parent of a vertex, the level, etc.
                fila.push(z);
            }
        }
    }
}
