#pragma once
#include <vector>
#include <cassert>

template<typename T, typename Op, typename Opinv>
struct BIT {
    int N;
    vector<T> vBIT; //vBIT[i] stores the range [i-lsb(i+1), i];
    Op op;
    Opinv opi;

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
        T res = T();
        for(; p != 0; p -= (p&-p)) {
            res = op(res, vBIT[p-1]);
        }
        return res;
    }

    T query(int l, int r) {
        assert(l>=0 && r<=N && r>l && "Error in the BIT range query");
        return opi(query(r), query(l));
    }

    void update(int p, T v) {
        //adds v to position p
        assert(p >= 0 && p < N && "Error in the BIT update range");
        p++;
        for(; p < N; p += (p&-p)) {
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

using BITXor = BIT<long long, XorFunctor<long long>, XorFunctor<long long>>;

using BITSum = BIT<long long, SumFunctor<long long>, SubFunctor<long long>>;


