/*������������Ȼ�죬��ɾ�����̫����������ɾ���ִ��Ӱ��Ч�ʣ���˲���ջ�洢Ԫ�ز������жϲ�ɾ����
    �ȿ��Ա�֤�ϸߵĲ����ɾ��Ч�ʣ�����Ϊ���⽵���ص㣬�нϸߵ�����Ч�ʣ�����������Ҫ��ͷ������ֻ
    ��whileѭ���ж�ջ��Ԫ�ؼ��ɣ�
*/
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int N;
    cin>>N;
    int Pay=0;
    int Income=0;
    stack<int> s;
    for(int i=0;i<N-1;i++){             //���һ�첻���Ʊ
        int n;
        cin>>n;
        Pay+=n;
        while(!s.empty() && s.top()<n){
            Income+=n;
            s.pop();
        }
        s.push(n);
    }
    int priceN;
    cin>>priceN;
    Income+=priceN*s.size();
    cout<<Income-Pay<<endl;
    
    return 0;
}
