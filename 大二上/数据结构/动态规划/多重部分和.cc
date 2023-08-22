#include<bits/stdc++.h>
using namespace std;
//n种大小不同的数字，每种m_i个，判断是否可以从这些数字中选出若干使他们的和恰好为k
int n;
vector<int> each_amount;
int K;//目标和数
vector<int> each_number;
#define MAXNUM 1000
#define MAXK 1000
//未优化
bool dp[MAXNUM+1][MAXK+1];
void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<=K;j++){
            for(int k=0;k<=each_amount[i]&&k*each_number[i]<=j;k++){
                dp[i+1][j]|=dp[i][k-k*each_number[i]];
            }
        }
    }
    if(dp[n][K]) printf("Yes\n");
    else printf("No\n");
}

//采用记忆化查询
int dp2[MAXK+1];
void solve(){
    memset(dp2,-1,sizeof(dp2));
    dp2[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=K;j++){
            if(dp2[j]>=0){
                dp2[j]=each_amount[i];
            }else if(j<each_number[i]||dp[j-each_number[i]]<=0){
                dp2[j]=-1;
            }else{
                dp2[j]=dp2[j-each_number[i]-1];
            }
        }
    }
    if(dp[K]>=0) printf("YES\n");
    else printf("NO");
}
