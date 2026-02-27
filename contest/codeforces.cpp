//#undef FRAGA

#include <bits/stdc++.h>
#include "algorithms/geometry/geometry.cpp"     
#include "algorithms/common.hpp"     

    
#ifndef FRAGA
    const long long MAXN = 2*1e5+10;// 1e4*15+200;
#else
    const long long MAXN = 50;// 1e4*15+200;
#endif
    
const long long MAXLOG = 32;
const long long MOD2 = 1e9 + 7;
const long long MOD = 998244353;


void tc() {
    ll n;
    point p;
    cin>>p.x;
    cout<<2*p.x<<endl;
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