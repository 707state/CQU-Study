/*������A+B:
��Ŀ��������������A��B�ĺͣ�����A��B��������[1,1000]����΢�е��鷳���ǣ����벢����֤��������������
���룺��һ�и���A��B������Կո�ֿ���������A��B��һ��������Ҫ�������������ʱ������ǳ�����Χ�����֡���������С�����ʵ����������һ�����롣
    ע�⣺���ǰ������г��ֵĵ�1���ո���Ϊ��A��B�ķָ�����Ŀ��֤���ٴ���һ���ո񣬲���B����һ�����ַ�����
�������������ȷ���������������򰴸�ʽ A + B = �� ��������ĳ�����벻��Ҫ��������Ӧλ�����?����Ȼ��ʱ��Ҳ��?��
*/
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

int main(){
    string A="",B="";
    int nA,nB;
    char AB[100];
    cin.get(AB,100);
    bool flagA=1,flagB=1;
    stringstream ss;
    int l=strlen(AB);
    int l0;                     //�����洢��һ���ո��λ��
    for(int i=0;i<l;i++){
        if(AB[i]==' '){         //��Ŀ��֤���ٴ���һ���ո�
            l0=i;
            break;
        }
    }
    for(int i=0;i<l0;i++){
        A+=AB[i];
        if(AB[i]<'0' || AB[i]>'9'){
            flagA=0;
        }
    }
    if(A.length()==0){
        flagA=0;                //��Ŀ��֤B����һ�����ַ�������A����Ϊ��
    }
    for(int i=l0+1;i<l;i++){
        B+=AB[i];
        if(AB[i]<'0' || AB[i]>'9'){
            flagB=0;
        }
    }

    if(flagA){                  //�˴�flagAֻ�ж��˶�������
        ss<<A;
        ss>>nA;
        ss.clear();
        if(nA>=1&&nA<=1000){
            cout<<nA;
        }
        else{
            cout<<"?";
            flagA=0;            //�����˸�flagA
        }
    }
    else{
        cout<<"?";
    }
    cout<<" + ";
    
    if(flagB){
        ss<<B;
        ss>>nB;
        if(nB>=1&&nB<=1000){
            cout<<nB;
        }
        else{
            cout<<"?";
            flagB=0;
        }
    }
    else{
        cout<<"?";
    }
    
    cout<<" = ";
    if(flagA&&flagB){
        cout<<nA+nB;
    }
    else{
        cout<<"?";
    }

    return 0;
}

/*�տ�ʼ���������˼·����string A,char B[100],����AΪ��ʱ�ᷢ������
ͬʱ��Ҫע��cin>>A,cin.get(B,100)����getchar()�Ե��ո�
*/