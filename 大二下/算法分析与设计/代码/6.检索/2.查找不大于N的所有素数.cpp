/*���Ҳ�����N������������
    ��Ŀ������������N(N<=10000)���󲻴���N����������
    ˼·��������ΪN�����飬��ֵΪ1����2��ʼ������������N��2�ı������Ϊ0������������δ�����Ϊ
0����ֵ�����������С��N���������������±����ֵ���Ϊ0��ֱ��N
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N;
void markPrime(int A[],int start){
    for(int i=2;i*start<=N;i++){
        A[i*start]=0;
    }
}

int main(){
    cin>>N;
    int Prime[10001]={0};
    for(int i=2;i<=N;i++){
        Prime[i]=1;
    }
    for(int i=2;i<=N/2;i++){
        markPrime(Prime,i);
    }
    int cnt=0;
    for(int i=2;i<=N;i++){
        if(Prime[i]){
            cout<<i<<" ";
            cnt++;
        }
    }
    cout<<endl<<"Total number:"<<cnt<<endl;
    
    return 0;
}
