/*�������� O(n):
    ǰ��ļ�������ʽ��Ϊ�Ƚ�����ƽ�����Ӷ����Ҳ����nlogn�������������˼���ǽ������������ֵ
ת��Ϊ�ٿ�һ��������±꣬�ø������¼ÿ��Ԫ�س��ֵĴ�����Ȼ����ӵ������б�ÿһλ����С����������
���Եõ���λ���ֵ�׼ȷλ�á�
�˴�����A[n]�����B[n]�������ռ�C[k]
���ƣ�
    1.����ֵ������ǷǸ�����
    2.�������������ֵ��ģ������n�ɱ������磺A=[1,10**9]�����鳤������
*/
#include <iostream>
#include <time.h>
using namespace std;

void countingsort(int A[],int B[],int n){
    int C[20001]={0};
    int max=0;
    for(int i=0;i<n;i++){
        if(max<A[i])    max=A[i];
    }
    for(int i=0;i<n;i++){
        C[A[i]]++;
    }                       //��ʱC[i]��ʾA[n]��i�ĸ���ΪC[i]
    for(int i=1;i<=max;i++){
        C[i]+=C[i-1];
    }                       //��ʱC[i]��ʾA[n]��С�ڵ���i�ĸ���ΪC[i]
    //�Ӵ�С��A[i]����B[i]������ά��������ȶ��ԣ�û�иı�A[n]�����ֵ��˳��
    for(int i=n-1;i>=0;i--){
        B[C[A[i]]]=A[i];
        C[A[i]]--;          //������£���
    }
}

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

int main(){
    int a[10000];
    int b[10000];
    int c[10000];
    for(int i=0;i<10000;i++){
        int tmp=rand()%20000;
        a[i]=b[i]=tmp;
    }
    clock_t start1,start2,end1,end2;
    start1=clock();
    countingsort(a,c,10000);
    end1=clock();
    start2=clock();
    inssort(b,10000);
    end2=clock();
    cout<<"Time cost of countingsort:"<<double(end1-start1)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
    cout<<"Time cost of inssort:"<<double(end2-start2)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
    
    return 0;
}
