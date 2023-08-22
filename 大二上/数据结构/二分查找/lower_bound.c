#include<stdio.h>
int n,k;
#define MAX_N 1001
int a[MAX_N];
void solve(){
    int lb=-1,ub=n;
    while(ub-lb>1){
        int mid=(lb+ub)/2;
        if(a[mid]>=k){
            //mid满足条件，则解的范围在左侧
            ub=mid;
        }else{
            lb=mid;
        }
    }
    //这时,lb+1=ub
    printf("%d\n",ub);
}