/*��ջʵ����׺���ʽת����ǰ׺���ʽ
˼·��
    1.��ʼ������ջ,�����ջs1�ʹ洢�м�����ջs2
    2.�� �ҵ��� ɨ����׺���ʽ
    3.����������ʱ,����ѹs2
    4.���������ʱ,�Ƚ�����s1ջ������������ȼ�(���Ų��������)
        4.1���s1Ϊ��,��ջ�������Ϊ �� ����")",��ֱ�ӽ����������ջ
        4.2����,�����ȼ���ջ����������ĸ� ����� ,Ҳ�������ѹ��s1
        4.3����,��s1ջ���������������ѹ�뵽s2��,�ٴ�ת��4.1������s1���µ�ջ���������Ƚ�
    5.��������ʱ
        5.1����� �� ����,ֱ��ѹ��s1
        5.2����� �� ����,�����ε���s1ջ���������,��ѹ��s2,ֱ������������Ϊֹ,��ʱ����һ�����Ŷ���
    6.�ظ�����2��5,ֱ�����ʽ�����ұ�
    7.��s1��ʣ�����������ε�����ѹ��s2
    8.���ε���s2�е�Ԫ�ز����,��� ������׺���ʽת ǰ ׺���ʽ�Ľ��
*/
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

bool isPunct(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'){
        return 1;
    }
    return 0;
}
bool isPunct(string c){
    if(c=="+"||c=="-"||c=="*"||c=="/"||c=="("||c==")"){
        return 1;
    }
    return 0;
}
bool compare(string a,char b){
    if((a=="+"||a=="-")&&(b=='*')||b=='/'){
        return 0;
    }
    return 1;
}

int main() {
    string s;
    getline(cin,s);
    vector<string> v;
    stack<char> s1;
    stack<string> s2;
    int index=-1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='-'&&(i==0||s[i-1]=='(')){
            continue;
        }
        if(s[i]=='+'&&(i==0||s[i-1]=='(')){
            index++;
            continue;
        }
        if(isPunct(s[i])){
            string subs1=s.substr(index+1,i-index-1);
            if(subs1!="")   v.push_back(subs1);
            string c(1,s[i]);
            v.push_back(c);
            index=i;
        }
    }
    string subs2=s.substr(index+1,s.length());
    if(subs2!="")   v.push_back(subs2);
    //ת�����ʽ
    for(int i=v.size()-1;i>=0;i--){
        if(!isPunct(v[i])){
            s2.push(v[i]);
        }
        else{
            if(v[i]==")"){
                s1.push(')');
            }
            else if(v[i]=="("){
                while(s1.top()!=')'){
                    string c(1,s1.top());
                    s2.push(c);
                    s1.pop();
                }
                s1.pop();
            }
            else{
                label:{         //labelʵ����ת
                    if(s1.empty()||s1.top()==')'){
                        s1.push(v[i][0]);   //stringתchar
                    }
                    else if(compare(v[i],s1.top())){
                        s1.push(v[i][0]);
                    }
                    else{
                        string c(1,s1.top());
                        s2.push(c);
                        s1.pop();
                        goto label;
                    }
                }
                
            }
        }
    }
    while(!s1.empty()){
        string c(1,s1.top());
        s2.push(c);
        s1.pop();
    }
    cout<<s2.top();
    s2.pop();
    while(!s2.empty()){
        cout<<" "<<s2.top();
        s2.pop();
    }

    return 0;
}
