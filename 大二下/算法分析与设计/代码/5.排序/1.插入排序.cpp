/*�������� O(n*n)��
    �ȴ���ǰ2��Ԫ�أ��Ƚϴ�С���򼴿ɣ������ٴ���ǰ3��Ԫ�أ��鿴��3��Ԫ�صĺ���λ�ã�Ѱ�Ҳ���
����Ϊ �ӵ�3��λ����ǰ���������ҵ�����λ�ü�ֹͣ���ң���Ϊǰ2��Ԫ���Ѿ��ź�����˿���break����
ͬ������������Ԫ�ء�
*/
#include <iostream>
#include <algorithm>
using namespace std;

template<typename E,typename Comp>
void inssort(E A[],int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(Comp::prior(A[j],A[j-1])){       //A[j]<A[j-1](�˴�С�ڼ�����ǰ��)
                swap(A,j,j-1);
            }
            else{
                break;                          //A[j]�Ѵﵽ��ȷλ��(ʱ���Ż�)
            }
        }
    }
}

int main(){
    int N,M;
    cin>>N>>M;
    
    return 0;
}
