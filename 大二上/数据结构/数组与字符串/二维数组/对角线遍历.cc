#include<bits/stdc++.h>
using std::vector;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.size()==1) return mat[0];
        
        // int m=2*mat.size();
        int m=10000;
        vector<int> ans;
        vector<vector<int>> all;
        for(int i=0;i<=m;i++){
            vector<int> tmp;
            for(int j=i;j>=0;j--){
                if(j<mat.size()&&(i-j<mat[0].size()))
                tmp.push_back(mat[j][i-j]);
            }
            if(!tmp.empty())
            all.push_back(tmp);
        }
        for(int i=0;i<all.size();i++){
            if(i&1){
                std::reverse(all[i].begin(),all[i].end());
            }
            for(auto j:all[i]) ans.push_back(j);
        }
        return ans;
    }
};