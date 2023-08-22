#include<bits/stdc++.h>
using namespace std;
//第一种
vector<int> G[1001];
int make_graph(int argc, char const *argv[])
{
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int s,t;
        cin>>s>>t;
        G[s].push_back(t);//如果是无向图，还需要从t向s连边
    }
    return 0;
}

//第二种
struct vertex
{
    vector<vertex*> edge;
    /* data */
};
vertex G1[1001];
int makeGrp(){
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int s,t;
        cin>>s>>t;
        G1[s].edge.push_back(&G1[t]);
    }
}
