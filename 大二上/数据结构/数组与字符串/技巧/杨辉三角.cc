#include<bits/stdc++.h>
using std::vector;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(!numRows) return {};
       vector<vector<int>> ans(numRows,vector<int>(1,0));
    //    ans.push_back(std::move(vector<int>(1,1)));
        for(int i=1;i<=numRows;i++){
            ans[i-1].resize(i);
            ans[i-1][0]=1,ans[i-1][i-1]=1;
            // ans[i-1]=tmp;
        }
        for(int i=1;i<numRows;i++){
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
        }
        return ans;
    }
};