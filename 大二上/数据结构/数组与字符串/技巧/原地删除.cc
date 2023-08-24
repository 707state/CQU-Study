#include<bits/stdc++.h>
using std::vector,std::list;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0,r=0;
        while(r<nums.size()){
            while(r<nums.size()&&nums[r]==nums[l]) r++;
            while(r<nums.size()&&nums[r]!=nums[l]) nums[++l]=nums[r++];
        }
        return l+1;
    }
};