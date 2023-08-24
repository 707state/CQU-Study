#include<bits/stdc++.h>
using std::vector;
class Solution {
public:
    
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,1);
        if(rowIndex<2) return ans;
        for(int i=1;i<rowIndex+1;i++){
            for(int j=i;j>0;j--){
                ans[j]=ans[j]+ans[j-1];
            }
        }
        return ans;
    }
};