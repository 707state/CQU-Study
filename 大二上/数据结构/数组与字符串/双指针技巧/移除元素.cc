#include<bits/stdc++.h>
using std::vector;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0,r=0;
        for(r=0;r<nums.size();r++){
            if(nums[r]!=val){
                nums[l++]=nums[r];
            }
        }
        return l;
    }
};

