#pragma once

#include <vector>
#include <algorithm>

/*returns a vector with the lis of the given sequence*/
template<typename T> 
std::vector<T> lis(const std::vector<T>& vt, bool strictly_increasing = true) {
    if(vt.empty()) return {};

    int dist;
    std::vector<T> stack;
    std::vector<int> stack_id;
    std::vector<int> parent(vt.size(), -1);

    for(int i = 0; i < std::size(vt); i++) {
        
        typename std::vector<T>::iterator p;
        
        if(strictly_increasing) {
            p = std::lower_bound(stack.begin(), stack.end(), vt[i]);
        } else {
            p = std::upper_bound(stack.begin(), stack.end(), vt[i]);
        }

        dist = p - stack.begin();

        if(p == stack.end()) {
            stack.push_back(vt[i]);
            stack_id.push_back(i);
        } else {
            *p = vt[i];
            stack_id[dist] = i;
        }

        if(dist > 0) {
            parent[i] = stack_id[dist-1];
        }
    }

    std::vector<T> ans;
    int curr = stack_id.back();
    while(curr != -1) {
        ans.push_back(vt[curr]);
        curr = parent[curr];
    }
    std::reverse(ans.begin(), ans.end());

    return ans;
}
