/*ѡ������ O(n*n)��
    ��i������ѡ�������е�iСԪ�ط��ڵ�iλ����ÿ�ζ���δ����������ѡ����СԪ�ط����俪ͷ��
*/
#include <iostream>
#include <algorithm>
using namespace std;

template<typename E,typename Comp>
void selsort(E A[],int n){
    for(int i=0;i<n-1;i++){
        int index=i;
        for(int j=n-1;j>i;j--){
            if(Comp::prior(A[j],A[index])){
                index=j;
            }
        }
        swap(A,i,index);
    }
}

int main(){
    int N,M;
    cin>>N>>M;
    
    return 0;
}
