/* �����ַ�������λ������
��Ŀ������ͬ������������'('��������')'���ɵ��ַ�����ֻ��Ҫ��һ�����ȣ�����Ϊ0����ǰ׺�ƶ����ַ�����
    ĩβ���Ϳ���ʹ���е���������ƥ��ɹ�������Ϊ������䡣��������ǲ�����ѧ����ȥ֤�����������
    ȷ�ԣ����Ǳ��������п��е�ǰ׺���ȡ�
���룺��һ���и�����'('��')'���ɵ��ַ��������Ȳ�����1000000����Ŀ��֤�ַ������������ŵ�������ͬ��
�������һ����������п��е�ǰ׺���ȣ����������С���ֵ���ÿո�ֿ���ĩβ��ֵ����û�пո�
˼·����ֱ�۵ľ��Ǳ����ַ���ƴ��n�Σ�ÿ����ջ�ж��Ƿ���У�����n~1000000ʱ�����׳�ʱ
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool ismatch(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(!st.empty()&&st.top()=='('){
                st.pop();
            }
        }
    }
    return st.empty();
}

int main(){
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0;i<s.length();i++){
        string subs1(s,0,i);
        string subs2(s,i);
        string s2=subs2+subs1;
        if(ismatch(s2)){
            v.push_back(i);
        }
    }
    cout<<v[0];
    for(int i=1;i<v.size();i++){
        cout<<" "<<v[i];
    }

    return 0;

} 