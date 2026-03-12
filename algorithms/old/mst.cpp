#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010
#define pii pair<int,int>

/*
This is an algorithm for finding the minimum spanning tree in a given graph in O(M)(amortized), the real complexity is a little above that
*/
priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> arestas;
int pai[MAXN];
//here I declare the functions of the union-find, for seeing if the two nodes conected are in the same graph

int find(int a) {
    if(pai[a] == a) return a;
    return pai[a]=find(pai[a]);
}

void join(int a, int b) {
    pai[find(a)]=pai[find(b)];//this is the union find without all the optimizations
}

int mst() {//this function returns the size of the mst
    int mst_size=0;
    while(!arestas.empty()) {//this is a greedy algorithm, we try to put always the edge with the smallest value on the graph
        auto atual = arestas.top();
        arestas.pop();
        int a=atual.second.first;
        int b=atual.second.second;
        if(find(a)==find(b)) {//this means they are already in the same conex component
            continue;
        } else {
            join(a,b);
            mst_size+=atual.first;
        }
    }
    return mst_size;
}
