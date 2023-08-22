#include<bits/stdc++.h>
typedef long long ll;
#define MAX_V 10001
#define MAX_SQRT_B 10001
bool is_prime[MAX_V];
bool is_prime_small[MAX_SQRT_B];
#define max(a,b) (a>b?a:b)
void segment_sieve(ll a,ll b){
    for(int i=0;(ll)i*i<b;i++) is_prime_small[i]=1;
    for(int i=0;(ll)i*i<b-1;i++) is_prime[i]=1;
    for(int i=2;(ll)i*i<b;i++){
        if(is_prime_small[i]){
            for(int j=2;(ll)j*j<b;j+=i){
                is_prime_small[j]=false;
                
            }
            for(ll j=max(2LL,(a+i-1)/i)*i;j<b;j+=i) is_prime[j-a]=false;
        }
    }
}