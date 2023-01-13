/*ɾ���ظ�Ԫ�أ�
    ��Ŀ���ź��������A��ɾ�����ظ�Ԫ�أ��������ö���ռ�
    ˼·����size���������Чλ�ã���ֵΪ0����i=1��ʼ����A[i]!=A[size]����size++��Ȼ��A[size]=A[size]
*/
#include <iostream>
#include <algorithm>
using namespace std;

int removedup(int A[],int n){
    int size=0;
    for(int i=0;i<n;i++){
        if(A[i]!=A[size]){
            A[++size]=A[i];
        }
    }
    return size+1;
}

int main(){
    int a[100];
    for(int i=0;i<100;i++){
        a[i]=rand()%80;
    }
    sort(a,a+100);
    for(int i=0;i<100;i++){
        cout<<a[i]<<" ";
        if(i!=0 && i%20==0){
            cout<<endl;
        } 
    }
    cout<<endl;
    int res=removedup(a,100);
    cout<<"Different number:"<<res<<endl;
    for(int i=0;i<res;i++){
        cout<<a[i]<<" ";
        if(i!=0 && i%20==0){
            cout<<endl;
        } 
    }
    
    return 0;
}
