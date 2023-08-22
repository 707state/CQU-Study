#include<bits/stdc++.h>
using namespace std;
#define MAX_V 1001
int cost[MAX_V][MAX_V];
//cost[u][v]表示边e=(u,v)的权值
int d[MAX_V];//顶点s出发的最短距离·
bool used[MAX_V];//已经使用过的图
int V;//顶点shu
//从起点s出发到各个顶点的距离
void dijistra(int s){
    fill(d,d+V,INFINITY);//初始化成INF
    fill(used,used+V,false);//初始化成未走过
    d[s]=0;
    while(true){
        int v=-1;
        //从尚未使用过的顶点中选择距离最小的一个顶点
        for(int u=0;u<V;u++){
            if(!used[u]&&(v==-1||d[u]<d[v])){
                v=u;
            }
        }
        if(v==-1) break;
        used[v]=true;
        for(int u=0;u<V;u++){
            d[u]=min(d[u],d[v]+cost[v][u]);
        }//重点过程
    }
}
//上面算法未优化
//下面是优化过的
struct edge
{
    int to,cost;
};
typedef pair<int,int> P;//first是最短距离，second是顶点编号
// int V;
vector<edge> G[MAX_V];
// int d[MAX_V];d延用上面的
void dijistra(int s){
    priority_queue<P,vector<P>,greater<P>> que;
    //通过指定greater<P>参数，堆按照first从小到大的顺序取出值
    fill(d,d+V,INFINITY);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}


