//#undef FRAGA

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>    
using namespace std;
using namespace __gnu_pbds;
    

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<pii, ll> ppi;
typedef pair<ll, pii> pip;
typedef vector<ll> vl;
typedef long double ld;
typedef priority_queue<int, vector<int>, greater<int>>  minqueue;//priority queue com menor no topo 
typedef complex<ll> point;
    
typedef tree<
pii, 
null_type, 
less<pii>,
rb_tree_tag, 
tree_order_statistics_node_update
> ordered_set;
//#define x real()
//#define y imag()
    
#ifndef FRAGA
const long long MAXN = 2*1e5+10;// 1e4*15+200;
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2", "bmi", "bmi2", "lzcnt", "popcnt")
#endif
    
#ifdef FRAGA
const long long MAXN = 50;// 1e4*15+200;
#endif
    
const long long MAXLOG = 32;
const long long MAXK = 13;//60;// 1e4*15+200;
const long long MOD2 = 1e9 + 7;
const long long MOD = 998244353;
const long long inf = 1e18 + 10;
    
#define pb push_back
#define f first
#define s second
#define KAMEKAMEHA ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
    
void setIO(string s) {
    if (!freopen((s + ".in").c_str(), "r", stdin)) {
        cerr << "ERROR: Could not open input" << s << ".in" << "\n";
    }
    if (!freopen((s + ".out").c_str(), "w", stdout)) {
        cerr << "ERROR: Could not open output " << s << ".out" << "\n";
    }
}

void tc() {
    ll n;
    cin>>n;
    cout<<2*n<<endl;
}
    
int main() {
    KAMEKAMEHA
    #ifdef FRAGA
        setIO("etc/teste"); 
        auto start = chrono::high_resolution_clock::now();
    #endif

    ll t;
    cin>>t;
    while(t--) {
        tc();
    }

    #ifdef FRAGA
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> tm = end - start;
        cout<<"time: "<<tm.count()<<"s"<<endl;
    #endif
}