#pragma once
#include <vector>
#include <utility>

template<typename T>
struct union_find{
    int n;
    std::vector<T> pai;
    std::vector<int> tam;

    union_find(int _n) : n(_n), pai(_n), tam(_n, 1) {
        for(int i = 0; i < n; i++) {
            pai[i] = i;
        }
    }

    T find(T x) {
        if(pai[x] == x) return x;
        return pai[x] = find(pai[x]);
    }

    /*returns false if both are already in the same component*/
    bool join(T a, T b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(tam[a] < tam[b]) std::swap(a, b);
        pai[b] = a;
        tam[a] += tam[b]; 
        return true;
    }

    /*returns the size of the component of a*/
    int gtam(T a) {
        return tam[find(a)];
    }
};

using ufind = union_find<int>;