/*ð������ O(n*n)��
    ��ĩβ��ʼ�Ƚ�����Ԫ�ش�С�����Ͻ���ֱ����ͷ����һ��ֻ�ý������ڶ���Ԫ�أ���Ϊ��СԪ�ؾ���
��һ�ν���һ���ﵽ��ͷ����
ע���������ֵ��ĩβ/��Сֵ����ͷ�����У�����д������
Comparison����������ı����ǽ�һ��δ֪Ԫ�ز��뵽�Ѿ��ź���������У�ð������ı����ǽ���ֵ����
    ����λ�ã����߱��ʲ�ͬ��
*/
#include <iostream>
#include <algorithm>
using namespace std;

template<typename E,typename Comp>
void bubsort(E A[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(Comp::prior(A[j],A[j-1])){
                swap(A,j,j-1);
            }
        }
    }
}

int main(){
    int N,M;
    cin>>N>>M;
    
    return 0;
}
