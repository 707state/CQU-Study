/*���⣺
��Ŀ��int[] arr=new int[]{8,3,2,1,0};int[] index=new int[]{3,0,4,3,1,0,2,4,3,4,4};
    index�������arr������±꣬index[0]=2��Ӧarr[2]=1��index[1]=0��Ӧarr[0]=8��
    index[2]=3 ��Ӧ arr[3]=0���Դ����ơ��� �����׵õ��绰������18013820100��
    ����Ҫ�����дһ������Ϊ�κ�һ���绰����������δ��롣
���룺һ����11λ������ɵ��ֻ����롣
�����Ϊ����ĺ������ɴ����ǰ���У�����arr�е����ֱ��밴�ݼ�˳�������
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    string tel;
    getline(cin,tel);
    int num[10]={0};
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<tel.length();i++){
        num[tel[i]-'0']++;
        
    }
    for(int i=9;i>=0;i--){              //����ѹ���ʡ�˶�v1�Ľ�������
        if(num[i]!=0){
            v1.push_back(i);
        }
    }
    for(int i=0;i<tel.length();i++){
        for(int j=0;j<v1.size();j++){
            if(v1[j]==tel[i]-'0'){      //tel��λ��char������ֱ����v1[j]�Ƚ�
                v2.push_back(j);
            }
        }
    }
    cout<<"int[] arr = new int[]{";
    for(int i=0;i<v1.size()-1;i++){
        cout<<v1[i]<<",";
    }
    cout<<v1[v1.size()-1]<<"};"<<endl;

    cout<<"int[] index = new int[]{";
    for(int i=0;i<v2.size()-1;i++){
        cout<<v2[i]<<",";
    }
    cout<<v2[v2.size()-1]<<"};"<<endl;
    
    return 0;
}