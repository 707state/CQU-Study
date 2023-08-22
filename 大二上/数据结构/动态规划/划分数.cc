#include<iostream>
using namespace std;
//n个无区别的物体，把他们划分成不超过m组，求出划分方法数模M的余数
int n,m,M;

int dp[1001][1001];
void solve(){
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(j-i>=0){
                dp[i][j]=(dp[i-1][j]+dp[i][j-i])%M;
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    printf("%d\n",dp[m][n]);
}
