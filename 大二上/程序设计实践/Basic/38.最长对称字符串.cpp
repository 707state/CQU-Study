/*��Գ��Ӵ���
��Ŀ���Ը������ַ���������Ҫ���������Գ��Ӵ��ĳ��ȡ����磬����Is PAT&TAP symmetric?����Գ��Ӵ�Ϊs PAT&TAP s��������Ӧ�����11��
���룺��һ���и������Ȳ�����1000�ķǿ��ַ�����
�������һ���������Գ��Ӵ��ĳ��ȡ�
*/
#include <iostream>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int len=s.length();
    int max=0;                  //���ַ���maxΪ0
    if(len){                    //����Ϊ1���ַ���������������forѭ�������Ҫ�ı��ֵ
        max=1;                  //max��ֵ�����������裬��ΪֻҪ�ַ����ǿ�������Ϊ1������0
    }
    for(int i=1;i<len-1;i++){
        int tmp=1;
        bool flag=0;            //�жϻ����Ӵ�������ż��
        if(s[i]==s[i+1]){
            flag=1;
            tmp++;
        }
        if(!flag){              //�����Ӵ�����sdfds
            for(int j=1;i-j>=0,i+j<=len-1;j++){
                if(s[i-j]==s[i+j]){
                    tmp+=2;
                }
                else{
                    break;
                }
            }
            if(max<tmp){
                max=tmp;
            }
        }
        else{                   //�����Ӵ�����sdffds
            for(int j=1;i-j>=0,i+j+1<=len-1;j++){
                if(s[i-j]==s[i+j+1]){
                    tmp+=2;
                }
                else{
                    break;
                }
            }
            if(max<tmp){
                max=tmp;
            }
        }
        
    }
    cout<<max<<endl;
    
    return 0;
}