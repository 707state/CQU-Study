#include<bits/stdc++.h>
using namespace std;
//n是边数
//G是图
vector<int> G[1001];
int V;//顶点数
int color[1001];//顶点的颜色
bool dfs(int v,int c){
    color[v]=c;
    //把顶点v染成c
    for(int i=0;i<G[v].size();i++){
        if(color[G[v][i]]==c) return false;//相邻的顶点同色
        if(color[G[v][i]]==0 &&!dfs(G[v][i],-c)) return false;
        //如果相邻的顶点还没有被染色就染成-c
    }
    return true;
}//比较巧妙，值得多看
void solve(){
    for(int i=0;i<V;i++){
        if(color[i]==0){
            if(!dfs(i,1)){
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}