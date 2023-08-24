//滑动窗口，二分搜索，前缀和
#include<bits/stdc++.h>
using std::vector;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int quick,slow,sum=0,ans=nums.size();
        quick=slow=0;
        for(;quick<nums.size();quick++){
            sum+=nums[quick];
            if(sum>=target){
                while(1){
                    if(sum-nums[slow]>=target)sum-=nums[slow++];
                    else break;
                }
                if(quick-slow+1<ans)ans=quick-slow+1;
            }
        }   
        if(ans<nums.size()+1) return ans;
        else return 0;
    }
};