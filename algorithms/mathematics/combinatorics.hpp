#pragma once

#include "modular_arithmetic.hpp"
#include <vector>

template<int MOD>
struct Z {
    int n;
    vector<ModInt<MOD>> fat;

    Z(int _n) : n(_n+1), fat(n+1) {
        fat[0] = 1;
        for(int i = 1; i < n; i++) {
            fat[i] = fat[i-1]*i;
        }
    }

    /*n choose k*/
    ModInt<MOD> choose(int n, int k) {
        return fat[n]/(fat[k]*fat[n-k]);
    }

    /*returns 1/n*/
    ModInt<MOD> inv(int n) {
        return ModInt<MOD>(1)/n;
    }
};

using Z98 = Z<998244353>;

using Z10 = Z<(int)1e9 + 7>;
