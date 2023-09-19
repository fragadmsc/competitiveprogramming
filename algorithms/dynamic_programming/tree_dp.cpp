// lucas fraga 10/06
#include <bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> pii;
typedef long long ll;

#define pb push_back
#define mp make_pair
#define MAXLOG 30
#define MAXN 100005//use com cuidado
#define MOD 1000000007
#define inf 1000000010
#define f first 
#define s second 
#define all(x) x.begin(), x.end()
#define KAMEKAMEHA ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) (int)x.size()

ll dp[MAXN];//com a aresta i preta e com a aresta i branca
vector<int> grafo[MAXN];

void dfs(int n, int ant) {
    if(sz(grafo[n])==1 && grafo[n][0]==ant) {
        return;
    }
    ll summaxa=1, summaxb=1, summaxc=1;
    for(auto v : grafo[n]) {
        if(v==ant) continue;
        dfs(v, n);
    }
}

int main() {//lembre sempre de usar ll
    KAMEKAMEHA
    ll n;
    cin>>n;
    for(ll i=1;i<n;i++) {
        int a, b;
        cin>>a>>b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    dfs(1, -1);
    
    cout<<1<<endl;

} // terminado
