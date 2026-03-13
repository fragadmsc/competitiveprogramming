#pragma once

#include <vector>

/*returns the zarray*/
template<typename T>
std::vector<int> zarray(const std::vector<T>& vt) {
    int n = (int)size(vt);
    std::vector<int> z(n, 0);
    int l = 0, r = 0;

    for(int i = 1; i < n; i++) {
        /*r is an inclusive boundary*/
        if (i <= r) {
            z[i] = std::min(r-i+1, z[i-l]);
        }

        while(i+z[i] < n && vt[i+z[i]] == vt[z[i]]) {
            z[i]++;
        }
        
        if(i+z[i]-1 > r) {
            r = i+z[i]-1;
            l = i;
        }
    }

    return z;    
}
