/* ˼·���ַ���������λ��ʵ����ǰ��xλ��)���������ˣ����ֻ��Ը�������������ֵΪ0��������)����һ��
    ������(����һ��Ѱ�Ҽ����������ĵ㣬��Ϊ������
    ԭ��������洢��λ��������������1000000������̫ռ�ռ��ұ���������������ѭ�����
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int> v;
    int cnt1=0;
    int max=0;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]==')'){
            cnt1++;
        }
        else{
            cnt1--;
        }
        if(max<cnt1){
            max=cnt1;
        }
    }
    int cnt2=0;
    if(max==0){                         //�ڶ���ѭ��ѹ��Ԫ�ش�1��ʼ����˵����ж�0
        v.push_back(0);
    }
    for(int i=0;i<s.length()-1;i++){    //0��s.length()-1������һ����������Է���ֻ���0
        if(s[i]==')'){
            cnt2++;
        }
        else{
            cnt2--;
        }
        if(max==cnt2){
            v.push_back(i+1);           //ѹ�����ǰ׺���ȣ������Ҫ��һ
        }
    }
    cout<<v[0];
    for(int i=1;i<v.size();i++){
        cout<<" "<<v[i];
    }

    return 0;
} 