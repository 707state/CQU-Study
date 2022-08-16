/*˫����ʵ��ջ��
��Ŀ����1,2,...,N������ջQStack<int>, �ж�����N���������ɵ���������<a1,a2,��,aN> �Ƿ�Ϊ��Ч�ĳ�ջ
    ˳��ͬʱ�����޶�ջ��ֻ�ܴ洢K������(0<K<=N)����������ջ��������stack.length()<K, ���
    stack.length()==K, ֻ�ܴ��е���1�����ϵ���������һ������������ջ����ע��ջ������������ڻ�
    ����K��
���룺��һ��������������N��K��m��N��ʾ��ջ�����������KΪջ�д洢�������������ޣ�m��ʾ��������m����
    �룬ÿһ�ж���1��N��������һ�����У��ո�ֿ�����
�����m���ַ�T��F, ��i�е��ַ�T(F), ��ʾ��i������Ϊ��Ч����Ч���ĳ�ջ˳�� (1<=i<=m)
˫����ʵ��ջ��˼·����������������ͬ��ֻ��һ���ǿգ�pushʱѹ��ǿն��У�popʱ����QA,QB�������ǿն�
    �е����һ��Ԫ��
��Ŀ˼·���ʺ�ƿ�������㣬��
*/
#include <iostream>
using namespace std;

template <typename E>
class QStack{
private:
    int maxSize;    //ջ������
    E* QA;
    E* QB;          //��������ʵ�ֵĶ���
    int sizeA;
    int sizeB;
public:
    QStack(int size=0){
        maxSize = size;
        QA=new E[size];
        QB=new E[size];
        sizeA=0;
        sizeB=0;
    }
    ~QStack() {}
    void clear(){
        if(sizeA){
            for(int i=0;i<sizeA;i++){
                QA[i]=0;
            }
            sizeA=0;
        }
        else{
            for(int i=0;i<sizeB;i++){
                QB[i]=0;
            }
            sizeB=0;
        }
    }
    void push(const E& it){         //��������Ĭ����ѹ��QB
        if(sizeA){
            QA[sizeA]=it;
            sizeA++;
        }
        else{
            QB[sizeB]=it;
            sizeB++;
        }
    }
    E pop(){
        if(sizeA){
            E tmp=QA[sizeA-1];
            for(int i=0;i<sizeA-1;i++){
                QB[i]=QA[i];
                QA[i]=0;
            }
            sizeB=sizeA-1;
            sizeA=0;
            return tmp;
        }
        else if(sizeB){
            E tmp=QB[sizeB-1];
            for(int i=0;i<sizeB-1;i++){
                QA[i]=QB[i];
                QB[i]=0;
            }
            sizeA=sizeB-1;
            sizeB=0;
            return tmp;
        }
        else{               //��Ϊ��
            return NULL;
        }
    }
    const E& topValue() const {
        if(sizeA){
            return QA[sizeA-1];
        }
        else if(sizeB){
            return QB[sizeB-1];
        }
        else{
            return NULL;
        }
    }
    int length() const {
        if(sizeA){
            return sizeA;
        }
        else{
            return sizeB;
        }
    }
};

int main(){
    int N,K,m,n;
    cin>>N>>K>>m;
    for(int i=0;i<m;i++){
        int num=1;
        QStack<int> st(N);
        bool flag=1;
        for(int j=0;j<N;j++){
            cin>>n;
            if(n>=num){
                while(num<=n){
                    if(st.length()<K){
                        st.push(num);
                    }
                    else{
                        flag=0;
                    }
                    num++;
                }
                st.pop();
            }
            else{
                if(st.length()!=0 && st.topValue()==n){
                    st.pop();
                }
                else{
                    flag=0;
                }
            }
        }
        if(flag){
            cout<<"T"<<endl;
        }
        else{
            cout<<"F"<<endl;
        }
    }


    return 0;
}
