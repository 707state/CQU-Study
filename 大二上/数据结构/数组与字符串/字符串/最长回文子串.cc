//定义dp[][]为数组，dp[i][j]表示i,j之间为回文串
#include<bits/stdc++.h>
using std::string;
using std::vector;
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
        string ans="";
        for(int i=0;i<s.length();i++){
            for(int j=0;j<s.length()-i;j++){
                int k=i+j;
                if(i==0) dp[j][k]=1;
                else if(i==1) dp[j][k]=(s[k]==s[j]);
                else dp[j][k]=dp[j+1][k-1]&&(s[k]==s[j]);
                if(dp[j][k]&&i+1>ans.size()) ans=s.substr(j,i+1);
            }
        }
        return ans;
    }
};