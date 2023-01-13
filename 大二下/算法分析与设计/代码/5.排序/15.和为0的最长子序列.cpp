/*��Ϊ0��������У�
��Ŀ������һ������A[n]��������Ϊ0���������
˼·��
    ��һ������������O(n**2)
    ���������η���O(nlogn)
    ѡȡ�������м�Ԫ����Ϊ��׼���ݹ��Ԫ����ߵĺ�Ϊ0��������г���L���ұߵĺ�Ϊ0���������
����R���ٻ�ú���м�Ԫ�صĺ�Ϊ0��������г���M���Ƚ�L,M,R������ֵ����
    ��˻�ú���м�Ԫ�صĺ�Ϊ0��������г��ȼ�Ϊ�ص㡣��������������LS[],RS[]�������м䵽
���ߵ����飬�±��ʾ�����鳤�ȣ�ֵ��ʾ������ĺͣ���LS[i]+RS[j]=0ʱ��Ϊһ���⡣����ʱ����ֱ��
�����������ӶȻ���O(n**2)�����ü��������˼�룬������B[]��¼LS[]�ķ������飬����Ϊi��������
�еĳ���ΪB[i]���ٱ����������У�i��0��RS.length�������B[-RS[i]]>0�����ʾB[-RS[i]]+iΪһ
���⣬��M��С�Ƚϼ��ɡ�
ע�⣺�±�Ϊ�����±��������ƽ��
*/
#include <iostream>
using namespace std;

int max(int a,int b,int c){
    if(a>b){
        if(a>c) return a;
        else    return c;
    }
    else{
        if(b>c) return b;
        else    return c;
    }
}
int Middle(int A[],int l,int m,int r){
    int LS[100]={0};
    int RS[100]={0};
    for(int i=1;i<=m-l;i++){
        LS[i]=LS[i-1]+A[m-i+1];
    }
}

int LongestZeroSum(int A[],int l,int r){
    if(l==r){
        if(A[l]=0)  return 1;
        else        return 0;
    }
    int mid=(l+r)/2;
    int L=LongestZeroSum(A,l,mid);
    int R=LongestZeroSum(A,mid+1,r);
    int M=Middle(A,l,mid,r);

    return max(L,M,R);
}

int main(){
    
    
    return 0;
}
