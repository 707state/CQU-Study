#include<bits/stdc++.h>
using namespace std;
string a,b;
int n,m;//长度
int dp[1001][1001];
void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }else{
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
}