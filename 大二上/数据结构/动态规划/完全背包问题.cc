#include<bits/stdc++.h>
using namespace std;
//每样东西可以选择多件

int n;
struct bag
{
    int w,v;
    /* data */
}bags[100];
int W;

//没有优化的解法
int dp[1001][1001];
void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            for(int k=0;k*bags[i].w<=j;k++){
                dp[i+1][j]=max(dp[i][j-k*bags[i].w+k*bags[i].v],dp[i+1][j]);
            }
        }
    }
    printf("%d\n",dp[n][W]);
}
//优化掉k这一层
void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            if(j<bags[i].w){
                dp[i+1][j]=dp[i][j];
            }else{
                dp[i+1][j]=max(dp[i][j],dp[i+1][j-bags[i].w+bags[i].v]);
            }
        }
    }
    printf("%d\n",dp[n][W]);
}
//使用一个数组
int dp2[1001];
void solve(){
    for(int i=0;i<n;i++){
        for(int j=bags[i].w;j<=W;j++){
            dp2[j]=max(dp2[j],dp2[j-bags[i].w+bags[i].v]);
        }
    }
    printf("%d\n",dp[W]);
}