/*���������
��Ŀ������n�������������������ӳ�һ�ţ����һ�����Ķ�λ������
    ��:n=3ʱ��3������13,312,343���ɵ��������Ϊ34331213��
    ��:n=4ʱ��4������7,13,4,246���ӳɵ��������Ϊ7424613��
���룺�ж������������ÿ����������������У���һ��Ϊһ������N��N<=100�����ڶ��а���N����(ÿ��
    ��������1000���ո�ֿ�)��
�����ÿ���������һ����ʾ����������
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string s1,string s2){
    if(s1+s2>s2+s1){        //��ĿҪ������������˲��ǱȽ�s1��s2�Ĵ�С�����Ǵ�����
        return true;        //���磺742>74����74274<74742
    }
    else{
        return false;
    }
}

int main(){
    int N;
    while(cin>>N){
        vector<string> v;
        for(int i=0;i<N;i++){
            string s;
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(),v.end(),compare);
        for(int i=0;i<N;i++){
            cout<<v[i];
        }
        cout<<endl;
    }

    return 0;
}