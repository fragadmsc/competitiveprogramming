#pragma once

#include <vector>
#include <functional>
#include "algorithms/other/random.hpp"
#include "algorithms/mathematics/modular_arithmetic.hpp"


namespace hash_st {
    const int rng_min = 1e9 - 1e8;
    const int rng_max = 1e9;
    const int rng_mod = 1e9 + 7;
};

/*T must be convertible to long long (char, int, etc.)*/
template<typename T>
struct HashString {
    using mA = ModInt<hash_st::rng_mod>;
    int B;
    int n;
    std::vector<mA> p;
    std::vector<mA> h;

    template<typename Iterator>
    HashString(Iterator first, Iterator last) : 
    B(get_rng(hash_st::rng_min, hash_st::rng_max)), n(last-first),  p(n), h(n) {
        if(n == 0) return;
        p[0] = 1;
        h[0] = (ll)first[0];
        for(int i = 1; i < n; i++) {
            h[i] = h[i-1]*B + (long long)first[i];
            p[i] = p[i-1]*B;
        }
    }

    /*hashes a vector with the parameters of the original string in O(n)*/
    template<typename Iterator>
    long long hash(Iterator first, Iterator last) {
        mA at = 0;
        for(Iterator i = first; i != last; i++) {
            at = at*B + *i;
        }
        return (long long)at;
    }


    /*hashes a vector*/
    template<typename Container>
    long long hash(const Container& c) {
        return hash(c.begin(), c.end());
    }

    /*hashes a string literal*/
    template<size_t N>
    long long hash(const char (&s)[N]) {
        return hash(s, s + N - 1);
    }

    /*hashes a literal braced list like {1, 2}*/
    long long hash(std::initializer_list<T> il) {
        return hash(il.begin(), il.end());
    }


    /*gets the hash of the original string from [l, r] in O(1)*/
    long long hash(int l, int r) {
        mA ret = h[r];
        if(l!=0) ret -= h[l-1]*p[r-l+1];
        return (long long)ret;
    }

};

using SHash = HashString<char>;