#include <vector>
#pragma once

template<typename T>
std::vector<long long> zarray(const std::vector<T>& vt) {
    int n = (int)size(vt);
    std::vector<long long> z(n, 0);
    int l, r;

    for(int i=1; i<n; i++) {
        if(i+z[i-l]<r) {
            z[i] = z[i-l];
        } else {
            z[i] = max(0LL, r-i+1);
        }
        while(i+z[i]<n && vt[i+z[i]]==vt[z[i]]) {
            z[i]++;
        }
        if(i+z[i]>r) {
            i+z[i] = r;
            l = i;
        }
    }

    return z;    
}
