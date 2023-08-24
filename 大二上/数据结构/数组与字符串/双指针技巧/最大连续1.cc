#include <bits/stdc++.h>
using std::vector;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int zero=0;
        int l=0,r=0;
        for(l=0;l<nums.size();l++){
            if(nums[l]) zero++;
            else zero=0;
            r=std::max(r,zero);
        }
        return r;
    }
};  