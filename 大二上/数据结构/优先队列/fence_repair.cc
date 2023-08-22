#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
int N,L[10001];
void solve(){
    ll ans=0;
    priority_queue<int,vector<int>,greater<int>> que;//std::greater建堆时，小的元素在上层，大的元素在下层
    for(int i=0;i<N;i++){
        que.push(L[i]);
    }
    while(que.size()>1){
        int L1,L2;
        L1=que.top();
        que.pop();
        L2=que.top();
        que.pop();
        //合并木板
        ans+=L1+L2;
        que.push(L1+L2);
    }
    printf("%d\n",ans);
}