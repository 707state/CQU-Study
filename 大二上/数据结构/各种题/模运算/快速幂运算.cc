//对任意1<x<n都有x^n=x(mod n)成立的合数叫做Carmichael number
//给出n，判断它是不是这样的数
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod_pow(ll x,ll n,ll mod){
    ll res=1;
    while(n>0){
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
//优化做法
ll mod_pow(ll x,ll n,ll mod){
    if(n==0) return 1;
    ll res=mod_pow(x*x%mod,n/2,mod);
    if(n&1) res=res*x%mod;
    return res;
}