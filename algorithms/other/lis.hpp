#pragma once;

#include <vector>

template<typename T> 
std::vector<T> lis(const std::vector<T>& vt) {
    //returns a vector with the lis of the given sequence
    std::vector<T> stack;
    for(int i=0; i<(int)size(vt); i++) {
        std::vector<int>::iterator p = lower_bound(stack.begin(), stack.end(), vt[i]);
        if(p == stack.end()) {
            stack.pb(p);
        } else {
            *p = vt[i];
        }
    }
    return stack;
}