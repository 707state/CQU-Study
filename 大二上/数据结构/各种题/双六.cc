#include<iostream>
//给出a,b，求a,y，使ax+by=1
int extgcd(int a,int b,int &x,int &y){
    int d=a;
    if(b!=0){
        d=extgcd(b,b%a,y,x);
        y-=(a/b)*x;
    }else{
        x=1;y=0;
    }
    return d;
}