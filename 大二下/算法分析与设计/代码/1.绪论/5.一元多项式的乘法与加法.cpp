/*һԪ����ʽ�ĳ˷���ӷ�����
��Ŀ����ƺ����ֱ�������һԪ����ʽ�ĳ˻���͡�
���룺��2�У�ÿ�зֱ��ȸ�������ʽ������ĸ���������ָ���ݽ���ʽ����һ������ʽ������ϵ����ָ��������
    ֵ��Ϊ������1000�������������ּ��Կո�ָ���
�������2�У��ֱ���ָ���ݽ���ʽ����˻�����ʽ�Լ��Ͷ���ʽ�������ϵ����ָ�������ּ��Կո�ָ�������
    β�����ж���ո������ʽӦ���0 0��
��������:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
�������:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a[2002]={0};
    int b[2002]={0};
    int sum[2002]={0};
    int product[4002]={0};
    int A,B;
    cin>>A;
    for(int i=0;i<A;i++){
        int ratio,index;            //ϵ����ָ��
        cin>>ratio>>index;
        a[1000+index]=ratio;        //��ֹ��ָ��
    }
    cin>>B;
    for(int i=0;i<B;i++){
        int ratio,index;
        cin>>ratio>>index;
        b[1000+index]=ratio;
    }
    for(int i=0;i<2002;i++){
        sum[i]=a[i]+b[i];
    }
    for(int i=0;i<2002;i++){
        for(int j=0;j<2001;j++){
            product[i+j]+=a[i]*b[j];
        }
    }
    //finished
    bool flag1=0,flag2=0;
    for(int i=4001;i>=0;i--){
        if(product[i]!=0){
            if(flag1!=0){
                cout<<" ";
            }
            else{
                flag1=1;
            }
            cout<<product[i]<<" "<<i-2000;
        }
    }
    if(flag1==0){
        cout<<"0 0";
    }
    cout<<endl;
    for(int i=2001;i>=0;i--){
        if(sum[i]!=0){
            if(flag2!=0){
                cout<<" ";
            }
            else{
                flag2=1;
            }
            cout<<sum[i]<<" "<<i-1000;
        }
    }
    if(flag2==0){
        cout<<"0 0";
    }

    return 0;
}