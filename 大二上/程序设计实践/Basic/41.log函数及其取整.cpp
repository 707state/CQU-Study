//ʵ��log(N)ȡ����ʽ��ֵ�������cmathͷ�ļ��µ�log��eΪ��
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    //cout<<log(exp(n+1));
    float p=log(n)/log(2);
    int q=log(n)/log(2);
    if(p!=q){
        q++;
    }
    // if(log(n) % log(2)!=0){      //ȡģ����ֻ�������
    //     p++;
    // }
    cout<<q;
    
    return 0;
}
