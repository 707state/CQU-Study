#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>1
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define Mod 1000000007
#define eps 1e-6
#define ll long long
#define INF 0x3f3f3f3f
#define MEM(x,y) memset(x,y,sizeof(x))
#define Maxn 5000+5
#define P pair<int,int>//first最短路径second顶点编号
using namespace std;
int N,R;
struct edge
{
    int to,dis;
    edge(int to,int dis):to(to),dis(dis) {}
};
vector<edge>G[Maxn];//G[i] 从i到G[i].to的距离为dis
int d[Maxn][Maxn];//d[i][j]从i到j的最短距离
int d2[Maxn][Maxn];//d[i][j]从i到j的次短距离
void Dijk(int s)
{
    priority_queue<P,vector<P>,greater<P> >q;//按first从小到大出队
    for(int i=0; i<=N; i++)//初始化s到所有地方的最短路，次短路都是inf
        d[s][i]=INF,d2[s][i]=INF;
    d[s][s]=0;
    q.push(P(0,s));
    while(!q.empty())
    {
        P p=q.top();
        q.pop();
        int v=p.second;//点v
        if(d2[s][v]<p.first)//大于次短路径，肯定会大于最短路径，不用管他了
            continue;
        for(int i=0; i<G[v].size(); i++)
        {
            edge e=G[v][i];//枚举与v相邻的点
            int td=p.first+e.dis;//s到v的距离+v到e.to的距离
            if(d[s][e.to]>td)//s到e.to的最短路小于dt，更新d[s][e.to]
            {
                swap(d[s][e.to],td);
                q.push(P(d[s][e.to],e.to));
            }
            if(d[s][e.to]<td&&d2[s][e.to]>td)//td大于最短路，小于次短路，即td可以替换次短路
            {
                d2[s][e.to]=td;
                q.push(P(d2[s][e.to],e.to));
            }
        }
    }
}
int main()
{
    IOS;
    cin>>N>>R;
    for(int i=0; i<R; i++)
    {
        int u,v,d;
        cin>>u>>v>>d;
        G[u].push_back(edge(v,d));
        G[v].push_back(edge(u,d));
    }
    Dijk(1);//城市1到各个城市的最短距离，次短路
    cout<<d2[1][N]<<endl;
    return 0;
}