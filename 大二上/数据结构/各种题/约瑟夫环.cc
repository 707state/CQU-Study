#include<bits/stdc++.h>
using namespace std;
//例题：约瑟夫游戏的大意：30个游客同乘一条船，因为严重超载， 加上风浪大作，危险/
//万分。因此船长告诉乘客，只有将全船 一半的旅客投入海中，其余人才能幸免于难。无奈，\
大家只 得同意这种办法，并议定30 个人围成一圈，由第一个人数起，依次报数，数到第9人，便\
把他投入大海中，然后再从 他的下一个人数起，数到第9人，再将他投入大海中，如此 循环地进行，\
直到剩下 15 个游客为止。问：哪些位置是将 被扔下大海的位置
int sollve(int sum,int value,int n){
    if(n==1){
        return (sum+value+1)%sum;
    }else{
        return (sollve(sum-1,value,n-1)+value)%sum;
    }
}//sum是总人数,value是每次报道最大数,n是第n次
