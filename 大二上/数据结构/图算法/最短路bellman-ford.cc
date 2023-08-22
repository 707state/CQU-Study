//Bellmax-Ford算法
#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int from,to,cost;
    /* data */
};
#define MAX_N 1001
edge es[MAX_N];//边
int d[MAX_N];//最短距离
int V,E;//V是顶点数，E是边数
//求解从s点出发到所有点的最短距离
void shortest_path(int s){
    for(int i=0;i<V;i++){
        d[i]=INFINITY;
    }
    s[d]=0;
    while(true){
        bool update=false;
        for(int i=0;i<E;i++){
            edge e=es[i];
            if(d[e.from]!=INFINITY &&d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                update=true;
            }
        }
        if(!update) break;
    }
}
bool find_negative_loop(){
    memset(d,0,sizeof(d));
    for(int i=0;i<V;i++){
        for(int j=0;j<E;j++){
            edge r=es[j];
            if(d[r.to]>d[r.from]+r.cost){
                d[r.to]=d[r.from]+r.cost;
            }
            if(i==V-1) return true;
        }
    }
    return false;
}
//检查负圈