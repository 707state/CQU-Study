#include<bits/stdc++.h>
using std::vector;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]!=0){
                nums[l++]=nums[r];
            }
        }
        for(;l<nums.size();l++){
            nums[l]=0;
        }
    }
};
class SOlution{
    public:
    void moveZeros(vector<int> &nums){
        int slow=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                std::swap(nums[slow++],nums[i]);
            }
        }
    }
};