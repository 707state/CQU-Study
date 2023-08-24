#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left=0;
        int left_sum=0;
        int sum_all=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++){
          if(left_sum<<1==(sum_all-nums[i])) {
            return i;
          }
          left_sum+=nums[i];
        }   
        return -1;
    }
};