#include<iostream>
#include<algorithm>
using namespace std;
#include<queue>
#include<bits/stdc++.h>
#define MAX_V 10001
int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V;
int prim(){
    for(int i=0;i<V;i++){
        mincost[i]=INFINITY;
        used[i]=false;
    }
    mincost[0]=0;
    int res=0;
    while(true){
        int v=-1;
        //从不属于X的顶点中选取从X到其权值最小的顶点
        for(int u=0;u<V;u++){
            if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
        }
        if(v==-1) break;
        used[v]=true;
        res+=mincost[v];
        for(int u=0;u<V;u++){
            mincost[u]=min(mincost[u],cost[v][u]);
        }
    }
    return res;
}