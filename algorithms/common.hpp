#pragma once

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
    
using pii = pair<int, int>;
using ppi = pair<pii, int>;
using pip = pair<int, pii>;

using ll = long long;
using pll = pair<ll, ll>;
using ppl = pair<pll, ll>;
using plp = pair<ll, pll>;
using vl = vector<ll>;

using ld = long double;

template<typename T>
using minqueue = priority_queue<T, vector<T>, greater<T>>;//priority queue com menor no topo 

using ordered_set = tree<
pii, 
null_type, 
less<ll>,
rb_tree_tag, 
tree_order_statistics_node_update
>;
const long long inf = 1e18 + 10;
    
#define pb push_back
#define f first
#define s second
#define KAMEKAMEHA ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (long long)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

/*set the standard input and output files to be s.in and s.out, respectively*/
void setIO(string s) {
    if (!freopen((s + ".in").c_str(), "r", stdin)) {
        cerr << "ERROR: Could not open input" << s << ".in" << "\n";
    }
    if (!freopen((s + ".out").c_str(), "w", stdout)) {
        cerr << "ERROR: Could not open output " << s << ".out" << "\n";
    }
}

/*Answer YES if t is true and NO otherwise*/
void answer(bool t) {
    if(t) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}

/*an overload for std::cout*/
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
    os<<p.first<<' '<<p.second;

    return os;
}

/*prints any iterable data structure and a newline at the end*/
template<typename T>
void printds(const T& ds, char end = ' ') {
    for(const auto& e : ds) {
        cout<<e<<end;
    }
    cout<<"\n";
}

#ifndef FRAGA
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2", "bmi", "bmi2", "lzcnt", "popcnt")
#endif
