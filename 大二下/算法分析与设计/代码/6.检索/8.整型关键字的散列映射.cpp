/*���͹ؼ��ֵ�ɢ��ӳ�䣺
��Ŀ������һϵ�����͹ؼ��ֺ�����P���ó��������������ɢ�к���H(Key)=Key���ؼ���ӳ�䵽����ΪP��ɢ
    �б��С�������̽�ⷨ�����ͻ��
���룺��һ�����ȸ�������������N����1000����P����N����С���������ֱ�Ϊ������Ĺؼ����������Լ�ɢ�б�
    �ĳ��ȡ��ڶ��и���N�����͹ؼ��֡����ּ��Կո�ָ���
�������һ�������ÿ�����͹ؼ�����ɢ�б��е�λ�á����ּ��Կո�ָ�������ĩβ�����ж���ո�
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,P;
    cin>>N>>P;
    int key[1010];          //PΪ��N����С��������NΪ1000ʱ��P=1009���������Ҫ����1009
    for(int i=0;i<1010;i++){//�����Ե�3��
        key[i]=-1;          //��ʼ��key����
    }
    vector<int> v;          //�洢N�������±�
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        int index=a%P;
        if(key[index]==-1){
            key[index]=a;
            v.push_back(index);
            continue;
        }
        else if(key[index]==a){     //��ͬ�ؼ�ֵֻд��һ�飨���Ե�1��
            v.push_back(index);     //����Ҫ������飨���Ե�2��
            continue;
        }
        for(int j=index+1;;j++){    //��ֹ����Ϊ���ҵ�����λ�ã���Ȼ���ڣ��������޽�
            if(key[j%P]==-1){
                key[j%P]=a;
                v.push_back(j%P);
                break;
            }
            else if(key[j%P]==a){
                v.push_back(j%P);
                break;
            }
        }
    }
    cout<<v[0];
    for(int i=1;i<v.size();i++){
        cout<<" "<<v[i];
    }
    
    return 0;
}
