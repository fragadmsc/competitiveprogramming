// lucas fraga 10/06
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<long long,long long> pii;
typedef long long ll;
 
#define pb push_back
#define mp make_pair
#define MAXLOG 30
#define MAXN 1005 //use com cuidado
#define MOD 1000000007
#define inf 1000000010
#define f first 
#define s second 
#define all(x) x.begin(), x.end()
#define KAMEKAMEHA ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) (int)x.size()
 
struct point{
    ll x, y;
    void read() {
        cin>>x>>y;
    }
    void print() {
        cout<<x<<' '<<y;
    }
    point operator -(point& p) const {
        return point{x-p.x, y-p.y};
    }
    ll operator *(point p) {
        return x*p.y-y*p.x;
    }
    ll triangle(const point& P1, const point& P2) {// negativo ponto p1 a esquerda de thisP2
        return (P1 - *this) * (P2 - *this);
    }
    bool operator <(const point& p) const {
        return make_pair(x,y) < make_pair(p.x,p.y);
    }
};

int main() {//lembre sempre de usar ll
    KAMEKAMEHA

} // terminado
