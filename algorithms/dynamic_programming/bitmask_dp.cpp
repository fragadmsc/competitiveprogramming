//code to the problem hamiltoniam flights in the cses

#include <bits/stdc++.h>
using namespace std;
 
typedef pair<long long,long long> pii;
typedef long long ll;
 
#define pb push_back
#define mp make_pair
#define MAXLOG 30
#define MAXN 21//05 //use com cuidado
#define MOD 1000000007
#define inf 1000000010
#define ff first 
#define ss second 
#define all(x) x.begin(), x.end()
#define KAMEKAMEHA ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) (int)x.size()
 
int main() {//lembre sempre de usar ll
    KAMEKAMEHA
    ll n, m;
    ll dp[(1<<MAXN)][MAXN];
    cin>>n>>m;
    vector<ll> vempara[MAXN];
    for(ll i=1;i<=m;i++) {
        ll a, b;
        cin>>a>>b;
        vempara[b].pb(a);
    }
    dp[1][1]=1;
    for(ll s=1;s<(1<<n);s++) {
        if(s&(1<<(n-1)) && s != (1<<n)-1) continue;
 
        for(ll i=1;i<=n;i++) {
            if((s&(1<<(i-1)))==0) continue;
            for(auto v : vempara[i]) {
                if((1<<(v-1))&s) {
                    ll prev=s-(1<<(i-1));
                    dp[s][i]+=dp[prev][v];
                    dp[s][i]%=MOD;
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n]<<endl;
 
} // terminado
