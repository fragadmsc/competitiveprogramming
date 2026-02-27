/*
Example file for the implementation of a Union-Find data structure
Lucas Fraga Damasceno, 24/07/2023
*/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 50010

int pai[MAXN], peso[MAXN], n; // Here I declare the global variable the will be used

/*The Union-Find data structure can unite two elements in a tree and aswer question about the conex components of that tree in O(1), aprox
*/


int find(int x) {
    /* This is a function the returns the pai of a given node x, it works simply by iterating over all nodes until we arrive to the last node
    It has a complexity of O(N), but after all optimizations, the complexity is basically O(1)
    The optimization made here is that for every time we search a node, we connect it directly to the root of the tree
    */
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    /* This is a function that connects two nodes, x and y, and it works by just making one the parent of the other
    It has a complexity of O(N), but after all optimizations, the complexity is basically O(1) (the same as the find() function)
    The optimization made here is that for every time we connect two nodes, we connect them in such a way that the diameter of the tree is reduced
    */
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (peso[x] < peso[y]) pai[x] = y;
    else if (peso[x] > peso[y]) pai[y] = x;
    else {
        pai[x] = y;
        peso[y]++;
    }
}

int32_t main() {
    return 0;
}
