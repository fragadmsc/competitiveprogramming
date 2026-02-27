#include <bits/stdc++.h>
using namespace std;
const int maxn=100;//the time complexity is O(n^3)

int main() {
    int dist[maxn][maxn], weigth[maxn][maxn], n;//the graph is stored in an adjacency matrix (weigth)
    //we initialize dist[i][j] with the distance from i to j, 0 if if i==j and inf if there is no direct path from i to j
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);//in each iteration over k, we have the values of the shortest paths beetween all nodes if we only pass by intemediate nodes with index up to k
            }
        }
    }
}