#include<bits/stdc++.h>
using namespace std;
//n条绳子，每条长度分别为Li，切割成k条等长的绳子，求每根绳子的最大长度
int N,K;
#define MAX_N 10000
double L[MAX_N];
bool c(double x){
    int num=0;
    for(int i=0;i<N;i++){
        num+=(int)(L[i]/x);
    }
    return num>=K;
}
void solve(){
    double lb=0,ub=INFINITY;
    for(int i=0;i<100;i++){
        double mid=(lb+ub)/2;
        if(c(mid)) lb=mid;
        else ub=mid;
    }
    printf("%.2f\n",floor(ub*100)/100);
}