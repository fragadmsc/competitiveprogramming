#pragma once

#include "modular_arithmetic.hpp"
#include <vector>

template<int MOD>
struct Z {
    int n;
    vector<ModInt<MOD>> fat;

    Z(int _n) : n(_n+1), fat(n+1) {
        fat[0] = 1;
        for(int i = 1; i <= n; i++) {
            fat[i] = fat[i-1]*i;
        }
    }

    /*n choose k*/
    ModInt<MOD> choose(int _n, int k) {
        return fat[_n]/(fat[k]*fat[_n-k]);
    }

    /*returns 1/n*/
    ModInt<MOD> inv(int _n) {
        return ModInt<MOD>(1)/_n;
    }

    /*returns the nth catalan number
    it will expand the factorial up to 2*n, if necessary*/
    ModInt<MOD> catalan(int _n) {
        if(2*_n > n) {
            fat.resize(2*_n + 1);
            for(int i = n+1; i <= 2*_n; i++) {
                fat[i] = fat[i-1]*i;
            }
            n = 2*_n;
        }
        return choose(2*_n, _n)/ModInt<MOD>(_n+1);
    }
};

using Z98 = Z<998244353>;

using Z10 = Z<(int)1e9 + 7>;
