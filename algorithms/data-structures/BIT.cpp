/*
Example file for a implementation of a binary indexed tree(BIT)
Lucas Fraga Damasceno, 23/07/2023
*/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010

int BIT[MAXN], n; 
/* Here we define the BIT[i] as the sum of all number with indexes in range [i-lsb(i)+1, i] of an hipothetical array v[MAXN]
The idea here is being able to update the array and get the sum of a continuous subarray in O(logn)
More simply, BIT[i] is the sum of the previous lsb(i) elements of i
*/

void upd(int x, int v) {
    /* This function takes for parameter a int x, the index of the vector where we should ada a int v
    The function works because for each i bigger than x, BIT[i] contains x if and only if the lsb(i) >=lsb(x) and (i-x)=2^n
    We can prove the fact above by a proof by absurd, qhere we assume there is an y bigger than x that the lsb<lsb(x) ou (y-x) != 2^n
    O(logn)
    */
    for(;x <= n; x += x&(-x)) {
        BIT[x]+=v;
    }
}

int soma(int x) {
    /* This functions takes as parameter an int x, and return the sum of all number with index in range [1,x]
    The understanding of the function is best visualized by an example
    soma(14=1110)= BIT[1110] + BIT[1100] + BIT[1000] 
    */
    int ans=0;
    for(;x>0;x-=(x&(-x))) {
        ans+=BIT[x];
    }
    return ans;
}


int32_t main() {

} 
