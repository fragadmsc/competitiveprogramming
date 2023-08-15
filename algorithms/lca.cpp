#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010
#define MAXLOG 31

/*
This is an algorithm to compute te least common ancestor from 2 vertex in a tree in O(logn)
We are using binary lifting
*/
int prox[MAXLOG][MAXN];//prox[i][j] is where you end if you start from j and walk 2^i times
int pai[MAXN];//this vector defines the father of a given node, you can easely find this by making a dfs
int nivel[MAXN];//this vector defines the distance of a given node from the roor of the tree, it can be encontered by a dfs

void init() {//this function just initiates the prox matrix
    int i, j;
    for(i=1;i<=MAXN;i++) {
        prox[0][i]=pai[i];//by definition, pai[i] is the next vertice from i
    }
    for(j=0;j<=MAXLOG-1;j++) {//the -1 is for not accessing an invalid memory location
        for(i=1;i<=MAXN;i++) {
            prox[j][i]=prox[j-1][prox[j-1][i]];//here, i start form i and walk 2^(j-1)+ 2^(j-1)=2^j
        }
    }
}

int lca(int a, int b) {
    if(nivel[a]<nivel[b]) swap(a,b);//here we define a to have the lowest level 
    int andar=nivel[a]-nivel[b];//this what what we have to walk to make the level of both equal
    for(int i=0;i<=MAXLOG;i++) {
        if((1<<i) & andar) {
            a=prox[i][a];
        }
    }
    if(a==b) return a; //if we continue the program, we will return pai[a], what is wrong
    //now a and b are on the same level
    for(int i=MAXLOG;i>=0;i++) {//we always try to walk the maximum possible
        if(prox[i][a]!=prox[i][b]) {
            a=prox[i][a];
            b=prox[i][b];
        }
    }
    //the value of a is the maximum that we can walk for a and b still be diferent, so we return its father
    return pai[a];
}

