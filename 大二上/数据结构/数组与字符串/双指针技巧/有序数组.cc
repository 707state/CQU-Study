#include<bits/stdc++.h>
using std::vector;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        vector<int> ans;
        while(l<r){
            if(numbers[l]+numbers[r]==target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }else if(numbers[l]+numbers[r]<target){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};