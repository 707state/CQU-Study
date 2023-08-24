#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> m;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    m.push_back({i,j});
                }
            }
        }
        for(int i=0;i<m.size();i++){
            for(int j=0;j<matrix.size();j++){
                matrix[j][m[i][1]]=0;
            }
            for(int j=0;j<matrix[0].size();j++){
            matrix[m[i][0]][j]=0;
            }
        }
    }
};