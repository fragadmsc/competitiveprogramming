#include <bits/stdc++.h>
using namespace std;

//here we are building and using a segment tree
//it is a data structure that can be build in O(n), can change values in O(logn) and anwers queries about intervals in a array in O(logn)
//it is very useful because it allows us to make any kind od question about an interval, if all the numbers in the interval have the same importance (ex: sum, xor, min, max, product)

//this is the vector in witch the tree will be build
vector<int> tree;

void build(int n, vector<int> array ) {//this builds the tree in O(n), its working principles are pretty easy, its a binary indexed tree, qhere 1 is the root and every node i has sons 2*i, 2*i+1 
    tree.resize(2*n);
    for(int i=n;i<2*n;i++) {
        tree[i]=array[i-n];
    }
    for(int i=n-1;i>=1;i--) {
        tree[i]=tree[2*i]+tree[2*i+1];//here we use any operation that we want, xor, etc.
    }
}

void update(int x, int v, int n) {// this updates the value in x to v, in O(logn)
    tree[n+x]=v;
    x=(n+x)/2;
    while(x>=1) {
        tree[x]=tree[2*x]+tree[2*x+1];//again, here we can put any operation
        x/=2;//the parent of a node
    }
}

int sum(int indl, int indr, int nodel, int noder, int node) {
    //indl and indr are the indexes of the interval that we want
    if(indl<=nodel && indr>=noder) {
        return tree[node];
    }
    if(indl>noder || indr<nodel) {
        return 0;//in the case of the sum, for min we return inf, etc.
    }
    int mid=(indl+indr)/2;
    return sum(indl, indr, nodel, mid, 2*node) + sum(indl, indr, mid+1, noder, 2*node+1);
}

int main() {
    int n, a, b;
    vector<int> array;//the number of elements in the array(n) mus be a power of two, if not, we can just place 0 at the end
    sum(a, b, 0, n-1, 1);//for making a sum we always star from the root
}
