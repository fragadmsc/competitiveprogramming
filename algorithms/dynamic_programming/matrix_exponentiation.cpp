//this is a program that uses the concept of matrix exponentiation to calculate fibonacci in O(logN)
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<long long,long long> pii;
typedef long long ll;
typedef long double ld;
 
const long long MAXLOG=61;
const long long MAXN=(1LL<<20) ; //use com cuidado
const long long MOD=1e9+7; 
const long long inf=1e9+10;
 
#define pb push_back
#define mp make_pair
#define f first 
#define s second 
#define KAMEKAMEHA ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) (int)x.size()
 
int main() {
    //freopen("output.out", "w", stdout);
    ll n;
    cin>>n;
    if(n<=1) {
        cout<<n<<endl;
        return 0;
    }
    if(n==2) {
        cout<<1<<endl;
        return 0;
    }
    if(n==3) {
        cout<<2<<endl;
        return 0;
    }
 
    vector<pii> fib(MAXN);//fib[i].f=f2^i, .s=f2^i-1
    fib[0].f=0;
    fib[0].s=1;
    fib[1].f=1;
    fib[1].s=1;
    for(ll i=2;i<=MAXLOG;i++) {
        fib[i].s=(fib[i-1].f*fib[i-1].f + fib[i-1].s*fib[i-1].s) % MOD;
        fib[i].f=(fib[i-1].s*fib[i-1].f + fib[i-1].f*(fib[i-1].s + fib[i-1].f)) % MOD;
    }
    pii atu=mp(0LL,1LL);
    for(ll i=1;i<MAXLOG;i++) {
        if((1LL<<(i-1))&n) {
            ll aux=atu.f;
            atu.f=(atu.f*(fib[i-1].f+fib[i-1].s) + atu.s*fib[i-1].f) % MOD;
            atu.s=(atu.s*(fib[i-1].f+fib[i-1].s) + (aux-atu.s)*fib[i-1].f) % MOD;
        }
    }
    if(n%2) {
        cout<<(atu.f+atu.s) % MOD<<endl;
    } else {
        cout<<atu.f<<endl;
    }
    
}
