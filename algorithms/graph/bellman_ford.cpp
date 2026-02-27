#include <bits/stdc++.h>
using namespace std;

#define mp make_pair 
#define f first 
#define s second 
const int inf=1e5;

vector<pair<int, pair<int,int>>> edges;//implementando uma lista de adjacência pair<peso, pair<ini,fim>>

int main() {
    int n, m;//the number of points and the number of edges in the graph
    cin>>n>>m;
    for(int i=1;i<=m;i++) {//here we are reading the full graph (it is a directed graph)
        int a, b, cost;
        cin>>a>>b>>cost;
        edges.push_back(mp(cost,mp(a,b)));
    }
    vector<int> dist(n+1);
    for(int i=1;i<=n;i++) {//here we are setting the initial distance of infinity
        dist[i]=inf;
    }
    int node_start=1;
    dist[node_start]=0;
    for(int i=1;i<=n-1;i++) {//here we will be relaxing edges n-1 times. It is sufficient because in each relaxation, at least one vetex has its minimum distance achieved
        for(auto edge : edges) {
            if(dist[edge.s.f]+edge.f<dist[edge.s.s]) {
                dist[edge.s.s]=dist[edge.s.f]+edge.f;
            }
        }
    }
    //if there are no negative cycles in the graph the program can end here, and we will have the minimum distance in the vector dist
    //to find negative cycles we repeat the process, but this time, if one edge is relaxed, we update its value to -inf
    for(int i=1;i<=n-1;i++) {//here we will be relaxing edges n-1 times. It is sufficient because in each relaxation, at least one vetex has its minimum distance achieved
        for(auto edge : edges) {
            if(dist[edge.s.f]+edge.f<dist[edge.s.s]) {
                dist[edge.s.s]=-inf;
            }
        }
    }
    //all the vertex with the value -inf are in a cycle or are impacted by a negative cycle
    cout<<dist[n]<<endl;
}