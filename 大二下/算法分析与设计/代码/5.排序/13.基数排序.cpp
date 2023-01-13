/*�������� O(n):
    ��������Ϊ��ؼ������򣬶���ֵ����ʱ���ð���λ����(LSD)���Ȱ���λ�ֵ�10����ͬ�ĺ��ӣ�ֱ�Ӱ���
��������Ԫ��˳�����м��ɣ���Ȼ���ٰ�ʮλ��...ֱ�����λ�����Ƕ��ַ������У�һ�㰴��λ���ȡ�
*/
#include <iostream>
using namespace std;
//�˴���0~999֮������Ϊ����������
void radixsort(int A[],int B[],int n){
    for(int ratio=1;ratio<=100;ratio*=10){
        int cnt[10]={0};
        int tmp[10][1000];          //��ʱ�����ʾÿ������Ԫ�أ�ֻ��Ҫ��ѭ���ڲ���������
        for(int i=0;i<n;i++){
            //int a=(A[i]/ratio)%10;    //�Ƕ�B��������A
            int a=(B[i]/ratio)%10;  //�ؼ���λ
            int b=cnt[a];
            //tmp[a][b]=A[i];
            tmp[a][b]=B[i];
            cnt[a]++;
        }
        int index=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<cnt[i];j++){
                B[index++]=tmp[i][j];
            }
        }
    }
}

int main(){
    int A[1000];            //A[n]Ϊ����������
    int B[1000];            //B[n]Ϊ���������
    for(int i=0;i<1000;i++){
        A[i]=rand()%1000;
        B[i]=A[i];
    }
    //int cnt[10]={0};        //cnt[10]�洢�ؼ���0~9 10�������и�������
    //int tmp[10][1000];      //tmp[10][n]Ϊÿ������Ԫ��
    
    radixsort(A,B,1000);
    for(int i=0;i<1000;i++){
        cout<<B[i]<<" ";
        if(i!=0&&i%30==0){
            cout<<endl;
        }
    }
    
    return 0;
}
