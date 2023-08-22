#include<bits/stdc++.h>
using namespace std;
//给定整数n,晒去0-n之间的素数
#define MAX_V 10001
int prime[MAX_V];
bool is_prime[MAX_V+1];
int sieve(int n){
    int p=0;
    for(int i=0;i<=n;i++){
        is_prime[i]=1;
    }
    is_prime[0]=is_prime[1]=false;
    for(int i=0;i<=n;i++){
        if(is_prime[i]){
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i) is_prime[i]=false;
        }
    }
    return p;
}