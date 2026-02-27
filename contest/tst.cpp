#include <bits/stdc++.h>
// #pragma GCC optimize("O3", "unroll-loops")
// #pragma GCC target("avx2", "bmi", "bmi2", "lzcnt", "popcnt")
using namespace std;

typedef pair<long long, long long> pii;
typedef long long ll;
typedef pair<pii, ll> ppi;
typedef pair<ll, pii> pip;

typedef long double ld;
typedef priority_queue<int, vector<int>, greater<int>>  minqueue;//priority queue com menor no topo 
typedef complex<ll> point;
//#define x real()
//#define y imag()

#ifndef FRAGA
const long long MAXN = 1e5+10;// 1e4*15+200;
#endif

#ifdef FRAGA
const long long MAXN = 2*1e2 + 10;// 1e4*15+200;
#endif

const long long MAXLOG = 22;
const long long MAXN2 = 4*1e5+10;// 1e4*15+200;
const long long MOD = 676767677;
const long long MOD2 = 998244353;
const long long inf = 1e18 + 10;

#define pb push_back
#define f first
#define s second
#define KAMEKAMEHA ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
//#undef FRAGA

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}   

void solve() {
    ll n, x;
    cin>>n>>x;
    vector<ll> vt(n);
    for(ll i=0;i<n;i++) {
        cin>>vt[i];
    }
    sort(vt.begin(), vt.end());

    ll tt=0, at=0;
    vector<ll> ans;
    ll l=0, r=n-1;
    while(l<=r) {
        if((at+vt[l])/x > at/x) {
            at+=vt[r];
            ans.pb(vt[r]);
            tt += vt[r];
            r--;
        } else {
            at += vt[l];
            ans.pb(vt[l]);
            l++;
        }
    }
    cout<<tt<<endl;
    for(ll i=0;i<n;i++) {
        cout<<ans[i]<<' ';
    }
    cout<<endl;

}

int main() {
    KAMEKAMEHA

    #ifdef FRAGA
    setIO("teste");
    #endif

    ll t;
    cin>>t;
    while(t--) solve();
}
