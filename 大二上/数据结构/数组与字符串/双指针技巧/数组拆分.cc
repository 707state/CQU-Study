#include<bits/stdc++.h>
using std::vector;
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n=nums.size()/2;
        std::sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=nums[i<<1];
        }
        return ans;
    }
};