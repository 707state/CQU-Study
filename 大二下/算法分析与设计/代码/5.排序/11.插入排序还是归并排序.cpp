/*���������ǹ鲢����
��Ŀ�����������ǵ����㷨����һ����������ݣ��𲽲��������������С�ÿ�������У��㷨������������ȡ��
    һԪ�أ���֮����������������ȷ��λ�á���˵���ֱ��ȫ��Ԫ������
    �鲢����������µ������������Ƚ�ԭʼ���п��� N ��ֻ���� 1 ��Ԫ�ص����������У�Ȼ��ÿ�ε����鲢
    �������ڵ����������У�ֱ�����ֻʣ�� 1 ����������С�
    �ָ���ԭʼ���к���ĳ�����㷨�������м����У������жϸ��㷨���������������㷨��
���룺�ڵ�һ�и��������� N (��100)�����һ�и���ԭʼ���е� N �����������һ�и�����ĳ�����㷨������
    �м����С�������������Ŀ���������������ּ��Կո�ָ���
����������ڵ� 1 �������Insertion Sort��ʾ�������򡢻�Merge Sort��ʾ�鲢����Ȼ���ڵ� 2 ������
    ���ø������㷨�ٵ���һ�ֵĽ�����С���Ŀ��֤ÿ����ԵĽ����Ψһ�ġ����ּ��Կո�ָ���������β
    �����ж���ո�
ע�⣺�˴��鲢�������ϸ�Ĺ鲢���򣬶��������ϲ���û�д�N���ֵĹ���
    ��ƹ��̷��֣�N����2������ָ����ʱ���ֽ�Ϊ�������������ǰ��N����2������ָ������������
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N;                  //NΪʵ�ʳ���
int cmp[101];           //�м�����

bool equal(int a[],int b[],int n){
    bool flag=1;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            flag=0;
        }
    }
    return flag;
}

int insflag=0;
void inssort(int A[],int A2[],int n){
    for(int i=1;i<n;i++){
        bool flag=0;            //��¼����ѭ���Ƿ񽻻�
        for(int j=i;j>0;j--){
            if(equal(A,cmp,n)){
                insflag=1;
            }
            if(A[j]<A[j-1]){
                int tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                if(insflag==1){         //��¼�ҵ��м����к���һ��ִ��
                    flag=1;
                }
            }
            // if(insflag==1){          //��Ҫ���������һ��ִ���˵Ľ�����������Ĳ���
            //     for(int k=0;k<N;k++){
            //         A2[k]=A[k];
            //     }
            //     insflag++;
            //     return;
            // }
            else{
                break;
            }
            // if(insflag==1){          //��Ҫ��һ�ֽ�������
            //     for(int k=0;k<N;k++){
            //         A2[k]=A[k];
            //     }
            //     insflag++;
            //     return;
            // }
        }
        if(insflag==1 && flag==1){
            for(int k=0;k<N;k++){
                A2[k]=A[k];
            }
            insflag++;                  //ʹ����ѭ�����ٱ�����
            return;
        }
    }
    
}
//�˴�Ϊ��ʡ�£��鲢�����ڲ�����������sort�������
int mrgflag=0;
void mergesort(int A[],int A2[],int n){
    for(int i=2;i<=n;i*=2){
        // for(int j=0;j<n;j++){
        //     cout<<A[j]<<" ";
        // }
        // cout<<endl;
        int tmp[129]={0};       //��¼sortǰ��A�Ƿ�仯
        for(int j=0;j<N;j++){
            tmp[j]=A[j];
        }
        if(equal(A,cmp,N)){     //���ܱȽϵ�N0
            mrgflag=1;
        }
        for(int j=0;j<n;j+=i){
            sort(A+j,A+j+i);
        }
        if(mrgflag==1 && !equal(A,tmp,N)){
            for(int k=0;k<N;k++){
                A2[k]=A[k];
            }
            mrgflag++;
        }
    }
}

int main(){
    cin>>N;
    int N0=N;           //N0��ʾ��С��N��2����С��������
    int cnt=log(N)/log(2);
    if(pow(2,cnt)!=N){
        N0=pow(2,cnt+1);
    }
    int a1[101];        //a1,b1��ʾ����������
    int b1[129];        //N����ȡ2����С������������֤��������
    int a2[101];        //a2,b2��ʾ�������һ�ֽ��
    int b2[129];
    for(int i=0;i<N;i++){
        cin>>a1[i];
        b1[i]=a1[i];
    }
    for(int i=N;i<N0;i++){      //N~N0��ΪINFI
        b1[i]=9999;
    }
    for(int i=0;i<N;i++){
        cin>>cmp[i];
    }
    inssort(a1,a2,N);
    mergesort(b1,b2,N0);
    // for(int i=0;i<N;i++){
    //     cout<<b[i]<<" ";
    // }
    // cout<<"insflag:"<<insflag<<" mrgflag:"<<mrgflag<<endl;
    if(insflag){
        cout<<"Insertion Sort"<<endl;
        cout<<a2[0];
        for(int i=1;i<N;i++){
            cout<<" "<<a2[i];
        }
    }
    else if(mrgflag){
        cout<<"Merge Sort"<<endl;
        cout<<b2[0];
        for(int i=1;i<N;i++){
            cout<<" "<<b2[i];
        }
    }
    
    return 0;
}
