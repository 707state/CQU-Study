/*ջ��������ǰ�к�׺���ʽ����ֵ
ǰ׺���ʽ��ֵ���� ������ ɨ����ʽ,��������ʱ,������ѹ��ջ,���������ʱ,����ջ����������,��
    ���������������Ӧ�ļ���,���������ջ,�ظ���������ֱ�����ʽ�����,�������õ���ֵ��Ϊ��
    ��ʽ�Ľ��
��׺���ʽ��ֵ����׺���ʽ���������������㣬���������Ż���ֶ����ԣ����������ֲ�����������
    ����˼����������׺���ʽһ�㴦���ǰ/��׺���ʽ����������
��׺���ʽ��ֵ���� ������ ɨ����ʽ,��������ʱ,������ѹ��ջ��,���������ʱ,����ջ����������,
    �����������������Ӧ�ļ���,���������ջ,�ظ���������ֱ�����ʽ���Ҷ�,�������ó���ֵ��Ϊ
    ���ʽ�Ľ��
���룺ǰ׺���ʽ�����ֻ�������Կո�ָ���
�����������
ע����Ŀû�й涨�������־�Ϊһλ���������ֱ��ʹ���ַ�������ȷ�����ֵ�λ�����ʲ���vector������
    ��Ԫ�ض�ת����string
*/
#include <iostream>
#include <stack>            //stack����ִ������
#include <vector>           //vector�������д洢
#include <sstream>
using namespace std;

bool isPunct(string c){
    if(c=="+"||c=="-"||c=="*"||c=="/"){
        return 1;
    }
    return 0;
}
double Operation(int a,int b,string c){
    if(c=="+"){
        return a+b;
    }
    else if(c=="-"){
        return a-b;
    }
    else if(c=="*"){
        return a*b;
    }
    else if(c=="/"){
        return a/b;
    }
}
double string_to_double(string s){
    double ans;
    stringstream ss;
    ss<<s;
    ss>>ans;
    return ans;
}

int main() {
    string s;
    getline(cin,s);                         //����ǰ׺���ʽ
    vector<string> v;
    stack<int> stk;
    while(s.find(' ')!=string::npos){       //s�д��ڿո�
        int pos=s.find(' ');
        string subs=s.substr(0,pos);        //�ո�ǰ���ַ���
        v.push_back(subs);
        string tmp(s,pos+1);                //�ո����ַ���
        s=tmp;
    }
    v.push_back(s);                         //�����������������ѹ��vector
    for(int i=v.size()-1;i>=0;i--){
        if(!isPunct(v[i])){                 //����������ţ���������
            stk.push(string_to_double(v[i]));
        }
        else{
            double a=stk.top();
            stk.pop();
            double b=stk.top();
            stk.pop();
            double num=Operation(a,b,v[i]);
            stk.push(num);
        }
    }
    cout<<stk.top()<<endl;

    return 0;
}
