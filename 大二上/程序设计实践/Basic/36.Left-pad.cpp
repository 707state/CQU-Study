/*Left-pad��
��Ŀ����������΢���ϵ���Ϣ����һλ�����߲���NPM��Node Package Manager�����������ջ����Լ��Ŀ�Դ���룬���а���һ����left-pad��ģ�飬�������ģ���javascript�����React/Babel��̱���ˡ����Ǹ�ʲô����ģ�飿�������ַ���ǰ���һЩ������һ���ĳ��ȡ�������*ȥ����ַ���GPLT��ʹ֮����Ϊ10������left-pad�Ľ����Ӧ����******GPLT��Node����������left-pad����������һ��������������²ۡ������������ʵ��һ�����ģ�顣
���룺�ڵ�һ�и���һ��������N����1000����һ���ַ����ֱ���������ַ����ĳ��Ⱥ����������ַ����м���1���ո�ֿ����ڶ��и���ԭʼ�ķǿ��ַ������Իس�������
�������һ�����������ַ�����
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int N;
    char c;
    cin>>N>>c;
    getchar();                          //һ��Ҫgetchar�Ե��ո񣡣���
    string s;
    getline(cin,s);
    if(s.length()<=N){
        cout<<setw(N)<<setfill(c)<<s;   //����setw(N)<<setfill(c)���
    }
    else{
        for(int i=s.length()-N;i<s.length();i++){
            cout<<s[i];
        }
    }

        
    return 0;
}