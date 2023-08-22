#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 定义边的结构体
struct Edge {
    int src, dest, weight;
};

// 定义并查集
class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

// 定义比较函数用于排序边
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Kruskal最小生成树算法
vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    // 对边按照权重进行排序
    sort(edges.begin(), edges.end(), compareEdges);

    vector<Edge> result;
    int edgeCount = 0, i = 0;

    UnionFind uf(V);

    // 遍历每条边
    while (edgeCount < V - 1 && i < edges.size()) {
        Edge currentEdge = edges[i++];
        int srcRoot = uf.find(currentEdge.src);
        int destRoot = uf.find(currentEdge.dest);

        // 判断是否形成环路
        if (srcRoot != destRoot) {
            result.push_back(currentEdge);
            uf.unite(srcRoot, destRoot);
            edgeCount++;
        }
    }

    return result;
}

int main() {
    int V = 4; // 顶点的个数
    vector<Edge> edges; // 存储边的集合

    // 添加边
    edges.push_back({0, 1, 10});
    edges.push_back({0, 2, 6});
    edges.push_back({0, 3, 5});
    edges.push_back({1, 3, 15});
    edges.push_back({2, 3, 4});

    // 使用Kruskal算法求解最小生成树
    vector<Edge> result = kruskalMST(edges, V);

    // 输出最小生成树的边
    cout << "Edges in Minimum Spanning Tree:" << endl;
    for (const auto& edge : result) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
