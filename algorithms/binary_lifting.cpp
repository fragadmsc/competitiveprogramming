#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010
#define MAXLOG 31

/*
This is an algorithm to compute the Kth ancestral of a node in a tree in O(logn)
*/

int prox[MAXLOG][MAXN];//prox[i][j] is where you end if you start from j and walk 2^i times
int pai[MAXN];//this vector defines the father of a given node, you can easely find this by making a dfs

int main() {
    //first we need to initialize the prox matrix, in n*logn
    int i, j;
    for(i=1;i<=MAXN;i++) {
        prox[0][i]=pai[i];//by definition, pai[i] is the next vertice from i
    }
    for(j=0;j<=MAXLOG-1;j++) {//the -1 is for not accessing an invalid memory location
        for(i=1;i<=MAXN;i++) {
            prox[j][i]=prox[j-1][prox[j-1][i]];//here, i start form i and walk 2^(j-1)+ 2^(j-1)=2^j
        }
    }
    //now we can process queries in O(logn)
    int s, k;//we want to start from s and walk k times
    for(i=0;i<=MAXLOG-1;i++) { 
        if((1<<i) & k) {//here we check if the i bit is in k
            s=prox[i][s];
        }
    }
    //now s is the value that we wanted


}

