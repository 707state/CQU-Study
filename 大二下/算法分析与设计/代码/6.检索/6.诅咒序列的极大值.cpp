/*�������еļ���ֵ��
��Ŀ��������A�е�Ԫ��A[i]����A[i]>max(A[i?1],A[i+1])ʱ����Ԫ����A�е�һ������ֵ������N��������
    ͬ�������������飬���������Ǵ��в��ҳ�һ������ֵ���������ֵ��λ�á������ҵ���������鱻��
    ��һ�����������CursedArray���棬������operator[i]ȥѯ�ʵ�i��Ԫ�ص�ֵ(1��i��N)������ѯ���ܴ�
    �����ܳ���3(��ȥ��log(N)+1)�������������ҵ���ֵ��ʲô���ᱻ��Ϊ����ʧ�ܡ�
�����ӿڶ��壺
    int search_maximum (CursedArray& A, const int N);
    ����N��ֵ������30000��A����CursedArray��ʵ�������飩������A[0]=A[N+1]=0��0<A[i],A[j]��1000000 
��A[i]!=A[j] (1��i<j��N)�������뷵��A[1]��A[N]��һ������ֵ��λ�á�
����������
    ��һ�и���N, �ڶ��и���N�����������ÿո�ֿ�
    15
    42 68 35 1 70 25 79 59 63 65 6 46 82 28 62
���������
    41
ע������ֵ��68,70,79,65,82,62������ҵ�����һ��λ���Ҳ�ѯ����������15����������(82+1)/2=41
˼·����Ȼ���Ʒ��ʴ�������ô��Ȼ����˳����ʣ����������Ǵ�1~Nÿ�η���i-1,i,i+1������Ҫ3N��
    ��˲��ö��ֲ��ҵ�˼����Ҽ���ֵ��λ�ã����Ҵ���������3?log(N)?+1
    A[middle]>A[middle-1] && A[middle]>A[middle+1]���ҵ�
    A[middle]>A[middle-1] && A[middle]<=A[middle+1]���Ұ벿��
    A[middle]<=A[middle-1] && A[middle]>A[middle+1]����벿��
    ��Ϊ���Ʒ��ʴ��������ÿ������н�A[middle]�ȸ����������Լ��ٷ��ʴ���
*/

#include <iostream>
using namespace std; 

int search_maximum (CursedArray& A, const int N){
    int low=1,high=N;
    int middle=(low+high)/2;
    while(low<=high){
        middle=(low+high)/2;
        int a=A[middle-1];
        int b=A[middle];
        int c=A[middle+1];
        if(b>a && b>c){
            return middle;
        }
        else if(b>a){
            low=middle+1;
        }
        else{
            high=middle-1;
        }
    }
    return -1;
}


int main(){
    
    
    return 0;
}
