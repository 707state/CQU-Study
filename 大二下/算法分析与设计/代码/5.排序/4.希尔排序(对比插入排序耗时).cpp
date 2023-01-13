/*ϣ������ O(n**1.5)��
    ϣ������������Σ��ֵķ�����ͬ�ڹ鲢����Ȼ��ϲ���������������ʱʹ�ò�������
    ֱ������ϣ������ĸ��ӶȺ���Ȳ������򻹸ߣ�����������εĴ���������˲�������ıȽϺͽ���������
�Ӷ������˸��Ӷȡ�
*/
#include <iostream>
#include <time.h>
using namespace std;
int cnt1=0;
int cnt2=0;
//��ͨ��������
void inssort(int A[],int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(A[j]<A[j-1]){
                int tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                cnt2++;
            }
            else{
                break;
            }
        }
    }
}
//ϣ������
void inssort2(int A[],int n,int incr){      //nΪ�������鳤�ȣ�incrΪ������Ԫ�ؼ��
    for(int i=incr;i<n;i+=incr){            //incr�൱�ڵ�1λԪ�أ�+incr�൱�ڼ��
        for(int j=i;(j>=incr)&&(A[j]<A[j-incr]);j-=incr){
            int tmp=A[j];
            A[j]=A[j-incr];
            A[j-incr]=tmp;
            cnt1++;
        }
    }
}
void shellsort(int A[],int n){
    for(int i=n/2;i>2;i/=2){            //i��ʾ�������߼��
        for(int j=0;j<i;j++){           //j��ʾ��i������ʱ��0��i����
            inssort2(&A[j],n-j,i);      //�Ե�j�����ݽ��в���������ʼλ�ã����ȣ������
        //��j��������A���±�:j,j+i,j+2i...��inssort2�д��������ʾΪ:&A[j],&A[j]+i,&A[j]+2i...
        }
    }
    inssort2(A,n,1);                    //�����������������
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
    shellsort(a,10000);
    end1=clock();
    start2=clock();
    inssort(b,10000);
    end2=clock();
    cout<<"Time cost of shellsort:"<<double(end1-start1)/CLOCKS_PER_SEC<<"s"<<endl;
    cout<<"Times of swap:"<<cnt1<<endl;
    cout<<"Time cost of inssort:"<<double(end2-start2)/CLOCKS_PER_SEC<<"s"<<endl;
    cout<<"Times of swap:"<<cnt2<<endl;
    // for(int i=0;i<10000;i++){
    //     cout<<a[i]<<" ";
    //     if(i!=0&&i%20==0){
    //         cout<<endl;
    //     }
    // }
    
    return 0;
}
