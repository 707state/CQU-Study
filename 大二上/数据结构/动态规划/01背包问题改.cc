//挑选总重量不超过W的物品，找出所有方案当中价值总和最大的一个
#include<bits/stdc++.h>
using namespace std;
int n;
struct bag
{
    int w,v;
    /* data */
}b[1001];
int W;

int dp[1001][1001];
void solve(){
    fill(dp[0],dp[0]+1001,INFINITY);
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=1000;j++){
            if(j<b[i].v){
                dp[i+1][j]=dp[i][j];
            }else{
                dp[i+1][j]=min(dp[i][j],dp[i][j-b[i].w+b[i].v]);
            }
        }
    }
    int res;
    for(int i=0;i<1001;i++) if(dp[n][i]<=W) res=dp[n][i];
    printf("%d",res);
}