#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[100]={0};     //a�����洢����ķ��ظ�Ԫ��,����Ĭ��ֵδ֪��Ҫ��ʼ��
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        a[m]+=1;
    }
    int M=1;
    for(int i=0;i<100;i++){
        if(a[i]>1){
            int p=1;
            for(int j=1;j<=a[i];j++){
                p*=j;
            }           //����a[i]�Ľ׳�
            M*=p;       //����׳˵ĳ˻�
        }
    }

    int N=1;
    for(int i=1;i<=n;i++){
        N*=i;
    }
    
    cout<<N/M;          //�������˼��
    
    return 0;
}