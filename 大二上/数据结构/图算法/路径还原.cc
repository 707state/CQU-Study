// #include<bits/stdc++.h>
#include<iostream>
#include<bits/stdc++.h>
// using namespace std;
//对dijistra的路径还原
#define fill std::fill
#define MAX_V 1001
int cost[MAX_V][MAX_V];
//cost[u][v]表示边e=(u,v)的权值
int d[MAX_V];//顶点s出发的最短距离·
bool used[MAX_V];//已经使用过的图
int V;//顶点shu
int prev[MAX_V];
void dijistra(int s){
    fill(d,d+V,INFINITY);
    fill(used,used+V,false);
    // fill(prev,prev+MAX_V,-1);
    fill(prev,prev+V,-1);
    d[s]=0;
    while(true){
        int v=-1;
        for(int u=0;u<V;u++){
            if(!used[u]&&(v==-1||d[u]<d[v])) v=u;
        }
        if(v==-1) break;
        used[v]=true;
        for(int u=0;u<V;u++){
            if(d[u]>d[v]+cost[v][u]){
                d[u]=d[v]+cost[v][u];
                prev[u]=v;
            }
        }
    }
}
#define vector std::vector
vector<int> get_path(int t){
    vector<int> path;
    for(;t!=-1;t=prev[t]) path.push_back(t);//不断延着prev[t]直到t==s
    std::reverse(path.begin(),path.end());
    return path;
}