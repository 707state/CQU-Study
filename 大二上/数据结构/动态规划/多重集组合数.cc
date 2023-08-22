#include<bits/stdc++.h>
using namespace std;
//n个物品,第i个物品有ai个，不同物品可以互相区分，但同种类没有区分度
int n,m,a[100],M;

int dp[1001][1001];
void solve(){
    for(int i=0;i=n;i++){
        dp[i][0]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            if(j-1-a[i]>=0){
                dp[i+1][j]=(dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]+M])%M;
            }else{
                dp[i+1][j]=(dp[i+1][j-1]+dp[i][j])%M;
            }
        }
    }
    printf("%d\n",dp[n][m]);
}