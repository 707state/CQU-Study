/*�鲢���� O(nlogn)��
    ��nԪ�����鲻�϶�����ÿ��ֻ��1��Ԫ�أ�Ȼ��ʼ�ϲ����ϡ����ֱȽ����ף��ϲ�ʱ���������ϲ������
��λ��ʼ�Ƚϣ�����С�ķ��������ļ��ϼ��ɡ�Ϊ�˲�����ռ�ù���ռ䣬ֻʹ�����������ֻ�����
*/
#include <iostream>
#include <time.h>
using namespace std;

void mergesort(int A[],int tmp[],int left,int right){//left��ʾA[0]�±꣬right��ʾA[n-1]�±�
    if(left==right) return;
    int mid=(left+right)/2;
    mergesort(A,tmp,left,mid);      //���µݹ飬���ּ��ϲ�����
    mergesort(A,tmp,mid+1,right);
    for(int i=left;i<=right;i++){
        tmp[i]=A[i];
    }
    int i1=left,i2=mid+1;           //i1,i2��ʾ�������ϲ����飨���Զ��������׸�δ����Ԫ���±�
    for(int curr=left;curr<=right;curr++){
        if(curr==mid+1){            //left��������ɺϲ�
            A[curr]=tmp[i2++];
        }
        else if(i2>right){          //right��������ɺϲ�
            A[curr]=tmp[i1++];
        }
        else if(tmp[i1]<tmp[i2]){
            A[curr]=tmp[i1++];
        }
        else{
            A[curr]=tmp[i2++];
        }
    }
}

int main(){
    int a[10000];
    int tmp[10000];
    for(int i=0;i<10000;i++){
        int tmp=rand()%20000;
        a[i]=tmp;
    }
    clock_t start,end;
    start=clock();
    mergesort(a,tmp,0,9999);
    end=clock();
    cout<<"Time cost of shellsort:"<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    //cout<<start<<" "<<end<<endl;
    
    return 0;
}
