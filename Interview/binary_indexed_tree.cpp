#include <bits/stdc++.h> 

using namespace std;

vector<int> nums;
vector<int> bit;

void update(int idx, int val) {
    ++idx;
    while(idx<=nums.size()) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int sum(int idx) {
    ++idx;
    int ret = 0;
    while(idx>0) {
        ret += bit[idx];
        idx -= idx & -idx;
    }
    return ret;
}

int main() {
    nums = {1, 2, 3};
    bit = vector<int>(nums.size()+1, 0);
    for(int i=0; i<nums.size(); i++) update(i, nums[i]);
    cout<<sum(0)<<endl;
    return 0;
}