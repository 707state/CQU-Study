/*N�ʺ����⣺
��Ŀ��N�ʺ�������ָ��N*N�������Ϸ���N���ʺ�ʹ��N���ʺ��޷��Ե��Է���
    ����������һ�У�����һ�У�Ҳ���ڶԽ����ϣ�����Խ��ߣ����������ζԽ��ߣ���
˼·�����н��б�������ȷ��һ�е��Ǹ��ʺ�Ӧ�ð�����һ��ʱ�����жϸõ��Ƿ�Ϸ���
    ���Ϸ�����ݹ飬�����Ϸ��������Ѱ�ҿ��԰ڷŵ�λ�á��޴��ڷ�ʱֹͣ��
    �жϺϷ��ķ�����
    (1)��ͬ��
    (2)����ͬһ��45��б���ϣ�i+jΪ��ֵ��
    (3)����ͬһ��135��б���ϣ�i-jΪ��ֵ��
    �洢��ʽ��
    vector<int> v={2,4,6,1,3,5}
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool judge(int row,int col,vector<int> &tmp,int n){ //�ж�(row,col)�ܷ�Żʺ�
//�����ж��У���Ϊtmp�±��ʾ�������������غ�
    for(int i=0;i<tmp.size();i++){
        if(col==tmp[i]){
            return 0;
        }
        if((row+col)==i+1+tmp[i]){
            return 0;
        }
        if((row-col)==i+1-tmp[i]){
            return 0;
        }
    }
    return 1;
}

void place(vector<int> &tmp,vector<vector<int>> &ans,int n){
    if(tmp.size()==n){
        ans.push_back(tmp);
        return;
    }
    else if(tmp.size()<n){          //tmp.size()+1��ʾ�еı���
        for(int i=0;i<n;i++){       //i+1��ʾ�еı���
            if(judge(tmp.size()+1,i+1,tmp,n)){
                tmp.push_back(i+1);
                place(tmp,ans,n);
                tmp.pop_back();
            }
        }
    }
    return;
}

void PrintNQueen(vector<int> v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i]-1;j++){
            cout<<0;
        }
        cout<<1;
        for(int j=v[i];j<v.size();j++){
            cout<<0;
        }
        cout<<endl;
    }
    cout<<"------------------"<<endl;
    return;
}

int main(){
    int N;
    cin>>N;
    vector<int> tmp;                //�洢��ǰ����
    vector<vector<int>> ans;        //�洢���
    place(tmp,ans,N);

    cout<<ans.size()<<endl;;
    for(int i=0;i<ans.size();i++){
        PrintNQueen(ans[i]);
    }

    return 0;
}