#pragma once

#include <vector>

template<typename T> 
std::vector<T> lis(const std::vector<T>& vt, bool strictly_increasing = true) {
    //returns a vector with the lis of the given sequence
    std::vector<T> stack;
    for(int i=0; i<(int)size(vt); i++) {
        if(strictly_increasing) {
            auto p = lower_bound(stack.begin(), stack.end(), vt[i]);
            if(p == stack.end()) {
                stack.push_back(vt[i]);
            } else {
                *p = vt[i];
            }
        } else {
            auto p = upper_bound(stack.begin(), stack.end(), vt[i]);
            if(p == stack.end()) {
                stack.push_back(vt[i]);
            } else {
                *p = vt[i];
            }
        }
    }
    return stack;
}