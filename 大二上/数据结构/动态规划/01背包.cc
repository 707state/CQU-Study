#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
//n个物品，重量和价值分别为w,v，挑选总重量不超过W的物品，同时价值总和最大
int n;
struct bags
{
    int w,v;
    /* data */
}b[100];
int W;
int rec(int i,int j){
    //从第i个选取总量不超过j的部分
    int res;
    if(i==n){
        res=0;//没有剩余物品
    }else if(j<b[i].w){
        res=rec(i+1,j);
    }else{
        res=max(rec(i+1,j),rec(i+1,j-b[i].w+b[i].v));
    }
    return res;
}
//上面版本未优化
//改进后，使用了记忆化搜索
int dp[1001][1001];
int rec(int i,int j){
    if(dp[i][j]>=0){
        //已经计算过就直接使用之前的结果
        return dp[i][j];
    }
    int res;
    if(i==n){
        res=0;
    }else if(j<b[i].w){
        res=rec(i+1,j);
    }else{
        res=max(rec(i+1,j),rec(i+1,j-b[i].w+b[i].v));
    }
    return dp[i][j]=res;//结果记录在数组里
}
//不使用递归的方法，改用二重循环
//借用上面算法的dp数组
void solve(){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=W;j++){
            if(j<b[i].w){
                dp[i][j]=dp[i+1][j];
            }else{
                dp[i][j]=max(dp[i+1][j],dp[i+1][j-b[i].w+b[i].v]);
            }
        }
    }
    printf("%d\n",dp[0][W]);
}
//正向进行
void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            if(j<b[i].w){
                dp[i+1][j]=dp[i][j];
            }else{
                dp[i+1][j]=max(dp[i][j],dp[i][j-b[i].w+b[i].v]);
            }
        }
    }
    printf("%d\n",dp[n][W]);
}
