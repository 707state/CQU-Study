/*���ٽ�������I��
��Ŀ������һ�����У����и���Ϊn��ֻ��������������ʹ�������������У�������ٽ���������
˼·���Ȱ����������������Ϊ���������ֽ�����������Ҫ�����Ĵ���Ϊ�����������ָ�����
    �����������Ľ����󣬿��Խ�������������л�ȥ�����ˣ�����ʱ���и���Ϊn-1�ˡ�
    ����ʣ��n-1��Ԫ�ص��������ҵ�һ���������������ͬ�������γɻ��ݡ�
    ����ʹ������������Ľ�������Ϊ,������е����������������
*/
#include <iostream>
#include <vector>
using namespace std;

int num=0;              //ȫ�ֱ������ں������޸�
vector<int> v;

//�������������ظ�Ԫ�أ���ÿ��ֻȥ��һ�����Ԫ�أ���Ӱ��������
void swap(int n){       //nΪ���г���
    if(n==1){
        return;
    }
    int max=0;
    int j;              //jΪ��������±�
    for(int i=0;i<n;i++){
        if(max<v[i]){
            max=v[i];
            j=i;
        }
    }
    num+=(n-j-1);       //����������
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        if(*it==max){
            v.erase(it);
            break;      //ֻɾ����һ�������
        }
    }
    swap(n-1);
    return;
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int m;
        cin>>m;
        v.push_back(m);
    }
    swap(N);
    cout<<num;

    return 0;
}