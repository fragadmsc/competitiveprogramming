#pragma once

#include <vector>
#include <cassert>
#include <functional>

/*Op is the operation to merge nodes 
Opinv is the operation to combine [0,l] and [0, r] queries into [l, r] queries*/
template<typename T, typename Op = std::plus<T>, typename Opinv = std::minus<T>>
struct BIT {
    int N;
    std::vector<T> vBIT; //vBIT[i] stores the range [i-lsb(i+1), i];
    Op op;
    Opinv opi;

    /*builds a BIT from two iterators*/
    template<typename Iterator>
    BIT(Iterator first, Iterator last, Op opr  = Op(), Opinv opir = Opinv()) : N(last-first), vBIT(first, last), op(opr), opi(opir) {
        for(int i = 0; i < N; i++) {
            int x = i+1;

            for(int j = x - (x&-x); j < x-1; j++) {
                vBIT[i] = op(vBIT[i], first[j]);
            }
        }
    }

    T query(int p) {
        p++;
        T res = T();
        for(; p != 0; p -= (p&-p)) {
            res = op(res, vBIT[p-1]);
        }
        return res;
    }

    T query(int l, int r) {

        assert(l >= 0 && r < N && r >= l && "Error in the BIT range query");
        return opi(query(r), query(l-1));
    }

    void update(int p, T v) {
        //adds v to position p
        assert(p >= 0 && p < N && "Error in the BIT update range");
        p++;
        for(; p <= N; p += (p&-p)) {
            vBIT[p-1] = op(vBIT[p-1], v);
        }
    }

};

template <typename T>
struct XorFunctor {
    T operator()(const T& a, const T& b) const { return a xor b; }
};

template <typename T>
struct SumFunctor {
    T operator()(const T& a, const T& b) const { return a + b; }
};

template <typename T>
struct SubFunctor {
    T operator()(const T& a, const T& b) const { return a - b; }
};

/*Builds a xor BIT using two iterators for a vector*/
using BITXor = BIT<long long, XorFunctor<long long>, XorFunctor<long long>>;

/*Builds a sum BIT using two iterators for a vector*/
using BITSum = BIT<long long, SumFunctor<long long>, SubFunctor<long long>>;


