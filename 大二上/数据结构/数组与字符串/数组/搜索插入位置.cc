#include<bits/stdc++.h>
class Solution {
public:

    int searchInsert(std::vector<int>& numbers, int targets) {
       int l=0,r=numbers.size()-1,result=-1;
       if(targets>numbers.back()){
        return numbers.size();
       }
       while(l<=r){
        int mid=(l+r)>>1;
        if(numbers[mid]<targets){
            result=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
       } 
       
       return result+1;
    }
};