#include<bits/stdc++.h>
using namespace std;
#define MAX_V 1001
int d[MAX_V][MAX_V];//初始化成INFINITY
int V;
void warshall_floyd(){
    for(int i=0;i<V;i++){
        for(int k=0;k<V;k++){
            for(int j=0;j<V;j++){
                d[k][j]=min(d[k][j],d[k][i]+d[i][j]);
            }
        }
    }
}