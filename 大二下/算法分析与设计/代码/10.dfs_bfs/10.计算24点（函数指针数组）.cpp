/*24����Ϸ��
������������˳��̶�
˼·������˳��̶����ڲ��������ŵ����������ʽ����ʽΪ:a#b#c#d������ʾ�Ӽ��˳����������
	���������������ţ����������ȷ��ʱ����������5�������
	1.((a#b)#c)#d
	2.(a#(b#c))#d
	3.a#((b#c)#d)
	4.(a#b)#(c#d)
	5.a#(b#(c#d))
	�����Ѷ����ڽ�ѭ�����±�ת��Ϊ�Ӽ��˳��ĺ�����Ӧ���ú���ָ������
*/
#include <iostream>
using namespace std;

int Add(int a, int b){
    return a+b;
}
int Sub(int a, int b){
    return a-b;
}
int Mul(int a, int b){
	return a*b;
}
int Div(int a, int b){
    if(b == 0||a%b!=0)						//a%b!=0��֤���������򲻳���
        return -10000;						//����һ���㹻С������ʹ���㲻����
    return a/b;
}
 
int(*op[4])(int,int)={Add,Sub,Mul,Div};		//����ָ�루C++ǿ��֮����

char print(int i){							//��ӡ��24��ķ���
	switch (i)
	{
	case 0:
		return '+';
		break;
	case 1:
		return '-';
		break;
	case 2:
		return '*';
		break;
	case 3:
		return '/';
		break;
	
	default:
		break;
	}
	return '0';
}

bool Game24Points(int a,int b,int c,int d){
	int num;								//��ʾ����Ľ��
    for(int i=0;i<4;i++){					//a,b֮�������
        for(int j=0; j<4; j++){				//b,c֮�������
            for(int k=0; k<4; k++){			//c,d֮�������
                //((a#b)#c)#d
                num=op[k](op[j](op[i](a, b),c),d);
                if(num==24){
					cout<<"(("<<a<<print(i)<<b<<")"<<print(j)<<c<<")"<<print(k)<<d<<"=24"<<endl;
                    return true;
				}
                //(a#(b#c))#d
                num=op[k](op[j](a,op[i](b,c)),d);
                if(num==24){
					cout<<"("<<a<<print(j)<<"("<<b<<print(i)<<c<<"))"<<print(k)<<d<<"=24"<<endl;
                    return true;
				}
                //a#((b#c)#d)
                num=op[k](a,op[j](op[i](b,c),d));
                if(num==24){
					cout<<a<<print(k)<<"(("<<b<<print(i)<<c<<")"<<print(j)<<d<<")=24"<<endl;
                    return true;
				}
                //(a#b)#(c#d)
                num=op[k](op[i](a,b),op[j](c,d));
                if(num==24){
					cout<<"("<<a<<print(i)<<b<<")"<<print(k)<<"("<<c<<print(j)<<d<<")=24"<<endl;
                    return true;
				}
                //a#(b#(c#d))
                num=op[k](a,op[j](b,op[i](c,d)));
                if(num==24){
					cout<<a<<print(i)<<"("<<b<<print(k)<<"("<<c<<print(i)<<d<<"))=24"<<endl;
                    return true;
				}
            }
        }
    }
    return false;
}


int main(){
    int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(Game24Points(a,b,c,d)){
		cout<<"Solvable!"<<endl;
	}
	else{
		cout<<"No Solutions!"<<endl;
	}
    
    return 0;
}