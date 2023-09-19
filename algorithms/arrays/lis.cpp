#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010
#define pii pair<int,int>


//This is a program to find the longest increasing subsequence (lis) in a given array in O(nlogn)

vector<int> pilha;
int vet[MAXN], n; // the array in qhere we want to find the lis

void lis() {
    pilha.push_back(vet[1]);
    for(int i=2;i<=n;i++) {
        vector<int>::iterator p=lower_bound(pilha.begin(), pilha.end(), vet[i]);//here we search for the element first element that is bigger than vet[i], we can switch the lower_bound by the upper_bound if the problem asks for the longest no-decreasing subsequence
        if(p==pilha.end()) {
            pilha.push_back(vet[i]);
        } else {
            *p=vet[i];
        }
    }
    //now, the vector pilha has the lis, and the size of the lis is its size;
}
