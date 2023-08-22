//给定平面上两个格点P1,P2，在线段P1P2上还有几个格点(格点就是坐标线交点)
#include<bits/stdc++.h>
using namespace std;
int vertex_num(){
    int x1,x2,y1,y2;
    cin>>x1>>x2>>y1>>y2;
    int rres=__gcd(abs(x1-x2),abs(y1-y2))-1;
    return rres;
}