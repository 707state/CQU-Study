/*�ŷ��Ű棺
��Ŀ���й��Ĺ���д���֣��Ǵ������������Ű�ġ�����������д���򣬰�һ�����ְ��ŷ��Ű档
���룺�ڵ�һ�и���һ��������N��<100������ÿһ�е��ַ������ڶ��и���һ�����Ȳ�����1000�ķǿ��ַ������Իس�������
��������ŷ��ʽ�Ű�������ַ�����ÿ��N���ַ����������һ�п��ܲ���N������
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    cin>>N;
    getchar();                      //�Ե��ո񣡣���
    string s;
    getline(cin,s);
    int l=s.length();
    if(l%N){
        l/=N;
        s.resize(N*l+N,' ');        //��resize������ĩ�ո�
    }

    for(int j=0;j<N;j++){
        for(int i=s.length()-N+j;i>=0;i-=N){
            cout<<s[i];
        }
        cout<<endl;
    }
    

    return 0;
}