#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> numbers;
//O(n^2)复杂度的解法
int dp[1001];
void solve(){
    int res=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(numbers[j]<numbers[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
            
        }
        res=max(res,dp[i]);
    }
    printf("%d\n",res);
}
//经过优化
int dp2[1001];
void solve(){
    fill(dp2,dp+n,INFINITY);
    for(int i=0;i<n;i++){
        *lower_bound(dp2,dp2+n,numbers[i])=numbers[i];//利用了c++标准可
    }
}