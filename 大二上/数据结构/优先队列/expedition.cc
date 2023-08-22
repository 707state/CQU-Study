// #include<bits/stdc++.h>
#include<iostream>
#include<queue>
//L:驾车需要行驶的距离，N:路途上的加油站数目\
P:卡车上的油量，每行驶一个单位距离消耗一单位油，A:表示加油站距离出发点的距离\
B:表示每个Ai可以给车加多少单位油
using namespace std;
int N,L,P;
int A[100],B[100];
//问：如果能到达终点，最少需要加几次油
//在经过加油站时，在优先队列里加入Bi
//在燃料空了时,1.如果优先队列也是空的，则无法到达终点.2.否则取出优先队列中的最大值，并用来给卡车加油
void solve(){
    A[N]=L;//把终点也认为是加油站
    B[N]=0;
    N++;
    //维护加油站的优先队列
    priority_queue<int> que;
    //ans:加油次数,pos:现在所在位置,tank:油箱油量
    int ans=0,pos=0,tank=P;
    for(int i=0;i<N;i++){
        int d=A[i]-pos;//接下来要前进的距离
        while(tank-d<0){
            if(que.empty()){
                printf("-1");//表示无法到达
                return;
            }
            tank=que.top();
            que.pop();
            ans++;
        }
        tank-=d;
        pos=A[i];
        que.push(B[i]);
    }
    printf("%d",ans);
    // while()
}