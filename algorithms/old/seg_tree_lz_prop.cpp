#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//this is a code for a segment tree with lazy propagation that makes sum of intervals

vector<ll> tree, lz;

void unlazy(ll node, ll nodel, ll noder) {
    if(lz[node]==0) return;
    tree[node]+=lz[node];
    if(nodel != noder) {
        lz[2*node]+=lz[node]/2;
        lz[2*node+1]+=lz[node]/2;
    }
    lz[node]=0;
}

ll query(ll indl, ll indr, ll nodel, ll noder, ll n, ll node) {
    unlazy(node, nodel, noder);
    if(nodel>=indl && noder<=indr) {
        return tree[node];
    }
    if(noder<indl || indr<nodel) {
        return 0;
    }
    ll mid=(nodel+noder)/2;
    return query(indl, indr, nodel, mid, n, 2*node) +
           query(indl, indr, mid+1, noder, n, 2*node+1);//this is a sum query, so we return a sum
}

void update(ll indl, ll indr, ll nodel, ll noder, ll n, ll node, ll v) {//here we want to atualize the value at position p to v
    unlazy(node, nodel, noder);
    if(nodel>=indl && noder<=indr) {
        lz[node]=(noder-nodel+1)*v;
        unlazy(node, nodel, noder);
        return;
    }
    if(noder<indl || indr<nodel) {
        return;
    }
    ll mid=(noder+nodel)/2;
    update(indl, indr, nodel, mid, n, 2*node, v);
    update(indl, indr, mid+1, noder, n, 2*node+1, v);
    tree[node]=tree[2*node]+tree[2*node+1];
}


int main() {
    ll n;//size of the segtree, here we are considering that n is a power of two
    cin>>n;
    vector<ll> vet(n+1);//vet that starts the segment tree
    for(ll i=1;i<=n;i++) {
        cin>>vet[i];
    }
    //here we are builsing the tree and the lazy vector
    tree.resize(2*n);
    lz.resize(2*n);
    for(ll i=n;i<2*n;i++) {
        tree[i]=vet[i-n+1];
    }
    for(ll i=n-1;i>=1;i--) {
        tree[i]=tree[2*i]+tree[2*i+1];
    }

    //now we can make queries and updates
    ll q;
    cin>>q;
    while(q--) {
        ll op;
        cin>>op;
        if(op==1) {
            ll indl, indr, val;
            cin>>indl>>indr>>val;
            update(indl, indr, 1, n, n, 1, val);
        } else {
            ll indl, indr;
            cin>>indl>>indr;
            cout<<query(indl, indr, 1, n, n, 1)<<endl;
        }
    }
}
