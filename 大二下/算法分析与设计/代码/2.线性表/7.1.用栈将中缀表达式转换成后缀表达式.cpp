/*��ջʵ����׺���ʽת���ɺ�׺���ʽ
���룺��һ���и��������ո����׺���ʽ���ɰ���+��-��*��/�Լ���������()�����ʽ������20���ַ���
�������һ�������ת����ĺ�׺���ʽ��Ҫ��ͬ������������������ţ�֮���Կո�ָ�������β����
    �ж���ո�
˼·����׺ת��׺��ʵ�ʾ���Ѱ����������ȼ�����������ŵ��ڶ�������������
    1.��ʼ������ջ,�����ջs1�ʹ洢�м�����ջs2
    2.������ɨ����׺���ʽ
    3.����������ʱ,����ѹs2
    4.���������ʱ,�Ƚ�����s1ջ������������ȼ�(���Ų��������)
        4.1���s1Ϊ��,��ջ�������Ϊ������"(",��ֱ�ӽ����������ջ
        4.2����,�����ȼ���ջ����������ĸ�,Ҳ�������ѹ��s1
        4.3����,��s1ջ���������������ѹ�뵽s2��,�ٴ�ת��4.1������s1���µ�ջ���������Ƚ�
    5.��������ʱ
        5.1�����������,ֱ��ѹ��s1
        5.2�����������,�����ε���s1ջ���������,��ѹ��s2,ֱ������������Ϊֹ,��ʱ����һ�����Ŷ���
    6.�ظ�����2��5,ֱ�����ʽ�����ұ�
    7.��s1��ʣ�����������ε�����ѹ��s2
    8.���ε���s2�е�Ԫ�ز����,�������������׺���ʽת��׺���ʽ�Ľ��
ע��Ϊ����洢����ʹ���ַ�����Ϊ�����������������������
�ӣ�1.����ΪС��Ϊ�������磺1314+25.5*12
    2.����Ƕ�ף��磺((2+3)*4-(8+2))/5
    3.�����ţ��磺-2*(+3)�����Ӧ����-2 3 *  (��������)
    4.������������磺123
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
    if((a=="*"||a=="/")&&(b=='+')||b=='-'){
        return 1;
    }
    return 0;
}

int main() {
    //�ָ�������������
    string s;
    getline(cin,s);
    vector<string> v;           //�����洢��׺���ʽ�Ĳ������������
    stack<char> s1;             //�����ջ
    queue<string> q2;           //����������Ϊ����ʱҪ������˲��ö���
    int index=-1;               //�洢��һ���������λ��
    for(int i=0;i<s.length();i++){
        if(s[i]=='-'&&(i==0||s[i-1]=='(')){     //+-��ʾ�������ֵ�λ�ã���ͷ����(����
            continue;
        }
        if(s[i]=='+'&&(i==0||s[i-1]=='(')){
            index++;                            //+�������ڱ��ʽ
            continue;
        }
        if(isPunct(s[i])){
            string subs1=s.substr(index+1,i-index-1);
            if(subs1!="")   v.push_back(subs1); //��֤�ǿ�
            string c(1,s[i]);   //�����һ���ǿգ���charתΪstring
            v.push_back(c);
            //string tmp(s,i);  //s���ɷָ����ѭ�����±귢������
            //s=tmp;
            index=i;
        }
    }
    string subs2=s.substr(index+1,s.length());
    if(subs2!="")   v.push_back(subs2);         //��֤�ǿ�
    //ת�����ʽ
    for(int i=0;i<v.size();i++){
        if(!isPunct(v[i])){
            q2.push(v[i]);
        }
        else{
            if(v[i]=="("){
                s1.push('(');
            }
            else if(v[i]==")"){
                while(s1.top()!='('){
                    string c(1,s1.top());
                    q2.push(c);
                    s1.pop();
                }
                s1.pop();
            }
            else{
                label:{         //labelʵ����ת
                    if(s1.empty()||s1.top()=='('){
                        s1.push(v[i][0]);   //stringתchar
                    }
                    else if(compare(v[i],s1.top())){
                        s1.push(v[i][0]);
                    }
                    else{
                        string c(1,s1.top());
                        q2.push(c);
                        s1.pop();
                        goto label;
                    }
                }
                
            }
        }
    }
    while(!s1.empty()){
        string c(1,s1.top());
        q2.push(c);
        s1.pop();
    }
    cout<<q2.front();
    q2.pop();
    while(!q2.empty()){
        cout<<" "<<q2.front();
        q2.pop();
    }
    

    return 0;
}
