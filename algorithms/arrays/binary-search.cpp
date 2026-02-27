#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000

int vet[MAXN], n;//the vector on witch we will make the binary search

bool check(int a) {
    /*
    This is a simple function to check if some condition for a given number is true
    */

}

int binary_searchl(int x) {
    /*
    This is a simple function that can find numbers in ordered arrays in O(logn)
    It works by always cutting the search interval in half, what explains the complexity
    This is just a template, the condition and what you do after the condition is checked is very changeable
    */
    int ini=1, fim=n, mid;
    while(ini<=fim) {
        mid=ini+(fim-ini)/2;
        if(check(vet[mid])) {
            ini=mid+1;
        } else {
            fim=mid-1;
        }
    }
    return mid;
}

int main() {
    int n, x;
    cin>>n>>x;
    binary_searchl(x);
}
