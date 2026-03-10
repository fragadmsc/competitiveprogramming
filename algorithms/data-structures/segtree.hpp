#pragma once
#include <vector>
#include <cassert>

struct DummyApply {
    template<class Node, class Lazy>
    Node operator()(Node a, Lazy b, int l, int r) const { return a; }
};

struct DummyAddLazy {
    template<class Lazy>
    Lazy operator()(Lazy a, Lazy b) const { return a; }
};

/*
Builds a segtree

Assumes that the size of vector is a power of two
@param
Node - the node type
Lazy - the lazy node type
Merge(Node a, Node b) - a function to merge two nodes
apply(Node a, Lazy b, int l, int r) - a function to combine the lazy tag into a node
AddLazy(Lazy a, Lazy b) - a function on how to stack two lazy updates*/
template<class Node, class Merge, class Lazy = int, class Apply = DummyApply, class AddLazy = DummyAddLazy>
struct SegTree {
    int n;
    //seg[node] must always be correct, and lz[node] is a todo list for the children
    std::vector<Node> seg;
    std::vector<Lazy> lz;
    Node id_Node;
    Lazy id_Lazy;
    
    Merge merge;
    Apply apply;
    AddLazy addLazy;
    
    /*range updates constructor*/
    template<typename Iterator>
    SegTree(Iterator first, Iterator last, Node id_N, Merge merget, Lazy id_L, Apply applyt, AddLazy addLazyt) : 
        n(last-first), id_Node(id_N), id_Lazy(id_L), merge(merget), apply(applyt), addLazy(addLazyt) {
        
        seg.resize(2*n, id_Node);
        lz.resize(2*n, id_Lazy);
        for(int i = n; i < 2 * n; i++) {
            seg[i] = first[i-n];
        }
        for(int i = n-1; i >= 1; i--) {
            seg[i] = merge(seg[2*i], seg[2*i+1]);
        }
    }

    /*point updates constructor*/
    template<typename Iterator>
    SegTree(Iterator first, Iterator last, Node id_N, Merge merget) : 
        n(last-first), id_Node(id_N), id_Lazy(0), merge(merget), apply(Apply()), addLazy(AddLazy()) {
        
        seg.resize(2*n, id_Node);
        lz.resize(2*n, 0); // Fills dummy lazy array with 0
        for(int i = n; i < 2 * n; i++) seg[i] = first[i-n];
        for(int i = n-1; i >= 1; i--) seg[i] = merge(seg[2*i], seg[2*i+1]);
    }

    void unlazy(int node, int l, int r) {
        if(lz[node] == id_Lazy) return;
        
        int mid = (l+r)/2;
        
        if(l != r) {
            //1st child
            seg[2*node] = apply(seg[2*node], lz[node], l, mid);
            lz[2*node] = addLazy(lz[2*node], lz[node]);
            
            //2nd child
            seg[2*node + 1] = apply(seg[2*node + 1], lz[node], mid+1, r);
            lz[2*node + 1] = addLazy(lz[2*node + 1], lz[node]);
        }
        
        lz[node] = id_Lazy;
    }

    Node query(int indl, int indr, int l, int r, int node) {
        if(r < indl || indr < l) {
            return id_Node;
        }
        unlazy(node, l, r);
        if(l >= indl && r <= indr) {
            return seg[node];
        }

        int mid = (l+r)/2;
        return merge (query(indl, indr, l, mid, 2*node), 
                     query(indl, indr, mid+1, r, 2*node+1));
        
    }

    void update(int indl, int indr, int l, int r, int node, Lazy v) {
        if(r<indl || indr<l) {
            return;
        }

        unlazy(node, l, r);

        if(l >= indl && r <= indr) {
            seg[node] = apply(seg[node], v, l, r);
            lz[node] = addLazy(lz[node], v);
            return;
        }

        int mid = (r+l)/2;
        
        update(indl, indr, l, mid, 2*node, v);
        update(indl, indr, mid+1, r, 2*node+1, v);
        
        seg[node] = merge(seg[2*node], seg[2*node+1]);
    }
    
    void set(int p, int l, int r, int node, Node v) {
        if(l == r) {
            seg[node] = v;
            return;
        }
        
        int mid = (r+l)/2;
        
        if(p > mid) {
            set(p, mid+1, r, 2*node+1, v);
        } else {
            set(p, l, mid, 2*node, v);
        }
        
        seg[node] = merge(seg[2*node], seg[2*node+1]);
    }
    
    //simpler versions for use

    void update(int l, int r, Lazy v) {update(l, r, 0, n-1, 1, v);}
    
    Node query(int l, int r) {return query(l, r, 0, n-1, 1);}
    
    /*set and lazy updates DONT mix, if you want to use lazy progation use update*/
    void set(int pos, Node value) {set(pos, 0, n-1, 1, value);}

};

