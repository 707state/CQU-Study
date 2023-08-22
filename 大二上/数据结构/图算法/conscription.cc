#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
//征募女兵N人，男兵M人，每征募一个人需要花费10000美元，但如果已经征募的人\
中有一些关系紧密的人，那么可以少花一些钱
//给出若干男女之间的1-9999的亲密度，征募某个人的费用是10000-(已经征募的人中和自己的亲密度的最大值)
//要求通过适当的征募顺序使得征募所有人的花费最小
//把人看成点，关系看作边，转化为求解无向图的最大权森林问题，这个问题又可以通过把所有边取反之后用最小生成树的算法求解
#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define Mod 1000000007
#define eps 1e-6
#define ll long long
#define INF 0x3f3f3f3f
#define MEM(x, y) memset(x, y, sizeof(x))
#define Maxn 1000000 + 10
using namespace std;
int N, M, R;
int x[Maxn], y[Maxn], d[Maxn];//男孩 女孩 关系度
struct edge
{
    int u, v, cost;//u到v的距离为cost
};
bool cmp(const edge &e1, const edge &e2)//从小到大排序
{
    return e1.cost < e2.cost;
}
edge es[Maxn];
int par[Maxn];
void init(int n)//初始化并查集
{
    for (int i = 0; i <= n; i++)
        par[i] = i;
}
int findr(int x)//寻根
{
    if (par[x] == x)
        return x;
    return par[x] = findr(par[x]);
}
void unite(int x, int y)//合并
{
    x = findr(x);
    y = findr(y);
    if (x == y)
        return;
    par[x] = y;
}
bool same(int x, int y)//判断根是否相同
{
    return findr(x) == findr(y);
}
int kruskal(int V, int E)//kruskal算法求最小生成树
{
    sort(es, es + E, cmp);
    init(V);
    int res = 0;
    for (int i = 0; i < E; i++)
    {
        edge e = es[i];
        if (!same(e.u, e.v))
        {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)//T组测试样例
    {
        scanf("%d%d%d", &N, &M, &R);//存数据
        for (int i = 0; i < R; i++)
            scanf("%d%d%d", &x[i], &y[i], &d[i]);
        int V, E;
        V = N + M;//顶点个数
        E = R;//边个数
        for (int i = 0; i < E; i++)//存入结构体
        {
            es[i] = (edge){
                x[i], N + y[i], -d[i]};
        }
        printf("%d\n", 10000 * (N + M) + kruskal(V, E));
    }
    return 0;
}