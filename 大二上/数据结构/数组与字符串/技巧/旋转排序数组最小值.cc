#include<bits/stdc++.h>
using std::vector;
class Solution{
    public:
    int findMin(vector<int> &nums){
        return min_num(nums,0,nums.size()-1);
    }
    int min_num(vector<int> &nums,int start,int end){
        if(start==end) return nums[start];
        int min1,min2,mid;
        mid=(start+end)>>1;
        min1=min_num(nums,start,mid);
        min2=min_num(nums,mid+1,end);
        return min1>min2?min2:min1;
    }
};

