#include<iostream>
#define MAX_N 10001
int par[MAX_N];
int rank[MAX_N];
void init(int n){
    //初始化n个元素
    for(int i=0;i<=n;i++){
        par[i]=i;
        rank[i]=0;
    }
}
int find(int x){
    //查询树根
    if(par[x]==x){
        return x;
    }else{
        return par[x]=find(par[x]);
    }
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return;
    }else{
        if(rank[x]<rank[y]) par[x]=y;
        else if(rank[x]>rank[y]) par[y]=x;
        else rank[x]++;
    }
}
bool same(int x,int y){
    //判断是否在同一集合
    return find(x)==find(y);
}