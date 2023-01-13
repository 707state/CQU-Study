/*�鲢����2 O(nlogn)��
    �Ż��鲢����
1. �ϲ���������ʱ����β����ӣ������жϸ��������Ƿ�Խ��
2. ����С����ʹ�ò�������
*/
#include <iostream>
#include <time.h>
using namespace std;
#define THRESHOLD 16

void inssort(int A[],int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(A[j]<A[j-1]){
                int tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
            }
            else{
                break;
            }
        }
    }
}
void mergesort(int A[],int tmp[],int left,int right){
    if(right-left<=THRESHOLD){
        inssort(&A[left],right-left+1);     //С��ģ�����ò�������
        return;
    }
    int mid=(left+right)/2;
    mergesort(A,tmp,left,mid);
    mergesort(A,tmp,mid+1,right);
    for(int i=left;i<=mid;i++){
        tmp[i]=A[i];
    }
    for(int i=1;i<=right-mid;i++){
        tmp[mid+i]=A[right-i+1];
    }
    for(int i=left,j=right,k=left;k<=right;k++){
        if(tmp[i]<tmp[j]){
            A[k]=tmp[i++];
        }
        else{
            A[k]=tmp[j--];
        }
    }
}

int main(){
    int a[1024];
    int tmp[1024];
    for(int i=0;i<1024;i++){
        int temp=rand()%1000;
        a[i]=temp;
    }
    mergesort(a,tmp,0,1023);
    for(int i=0;i<1024;i++){
        cout<<a[i]<<" ";
        if(i!=0&&i%20==0){
            cout<<endl;
        }
    }
    
    return 0;
}
