#pragma once
#include <vector>
#include <cassert>


template<typename T, typename Op>
struct SparseTable{
    int N;
    Op op;
    vector<int> log; //gets the log of a given value in O(1)
    vector<vector<T>> table;

    template<typename Iterator>
    SparseTable(Iterator first, Iterator last, Op opr = Op()) : N(last-first), op(opr), log(N+1) {
        for(int i = 2; i <= N; i++) {
            log[i] = 1 + log[i>>1]; //smart way to calculate logs
        }
        table.resize(log[N]+1); //smaller dimention first to avoid cache misses
        table[0] = std::vector<T>(first, last);
        for(int i = 0; i < log[N]; i++) {
            table[i+1].resize(N);
            for(int j = 0; j + (1<<(i+1)) <= N; j++) {
                table[i+1][j] = op(table[i][j], table[i][j + (1<<i)]);
            }
        }
    }

    T query(int l, int r) const {
        assert(l < r && l >= 0 && r <= N && "invalid interval on sparse table");
        int dist = log[r - l];
        return op(table[dist][l], table[dist][r - (1<<dist)]);
    }

};

template <typename T>
struct MinFunctor {
    T operator()(const T& a, const T& b) const { return std::min(a, b); }
};

template <typename T>
struct MaxFunctor {
    T operator()(const T& a, const T& b) const { return std::max(a, b); }
};

using RMinQ = SparseTable<long long, MinFunctor<long long>>;

using RMaxQ = SparseTable<long long, MaxFunctor<long long>>;


