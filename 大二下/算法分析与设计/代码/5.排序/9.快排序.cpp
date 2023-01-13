/*������ O(nlogn)��
    Ѱ����ֵ�����������λ���������˴�����ֵ�������ҵ�����λ����ֻ�Ǽٶ�����λ������Ȼ�󽫴�����ֵ
��Ԫ�ط������ұߣ�С����ֵ�ķ�������ߡ�Ȼ��������������������п��š�
*/
#include <iostream>
#include <time.h>
using namespace std;
/*partition�����������l+1~r-1����Ϊ��������ֵΪ�ֽ�Ĳ��֣���������ֵ���±꣨ʵ���ϸ�λԪ������
��һλ�����������������ֵ�±꣩
*/
int partition(int A[],int l,int r,int& pivot){  //l,rΪA[]�����ҷ�Χ��pivotΪ��ֵ
    do{
        while(A[++l]<pivot);                    //��������С����ֵ��Ԫ�أ���ֹ�ڴ�����ֵ�ĵط�
        while((l<r)&&(A[--r]>pivot));
        int tmp=A[r];
        A[r]=A[l];
        A[l]=tmp;
    }while(l<r);
    return l;
}

void qsort(int A[],int i,int j){
    if(i>=j)    return;
    int pivotindex=(i+j)/2;                 //���ѡȡ����ֵ
    int pivot=A[pivotindex];
    A[pivotindex]=A[j];
    A[j]=pivot;                             //����ֵ��ĩβԪ�ػ���
    pivotindex=partition(A,i-1,j,A[j]);     //��l+1~r-1����ֵ�ֲ��������ش�����ֵ����Ԫ���±�
    pivot=A[j];                             //��ֵ����ĩβ�ȴ�����
    A[j]=A[pivotindex];
    A[pivotindex]=pivot;
    qsort(A,i,pivotindex-1);
    qsort(A,pivotindex+1,j);
}
//��ͨ��������
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
    for(int i=0;i<10000;i++){
        int tmp=rand()%20000;
        a[i]=b[i]=tmp;
    }
    clock_t start1,start2,end1,end2;
    start1=clock();
    qsort(a,0,9999);
    end1=clock();
    start2=clock();
    inssort(b,10000);
    end2=clock();
    cout<<"Time cost of qsort:"<<double(end1-start1)/CLOCKS_PER_SEC<<"s"<<endl;
    cout<<"Time cost of inssort:"<<double(end2-start2)/CLOCKS_PER_SEC<<"s"<<endl;
    
    return 0;
}
