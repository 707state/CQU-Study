/*���ݼ�֦��
��Ŀ������ܺ�II������һ�����ظ�Ԫ�ص�����candidates��һ��Ŀ���� target��
    �ҳ�candidates�����п���ʹ���ֺ�Ϊtarget����ϡ�
    candidates�е�ÿ��������ÿ�������ֻ��ʹ��һ�Ρ�
˼·����Ψһ��ͬ���ǵݹ�ʱstartֵ���޶�����+1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool equal(vector<int> v1,vector<int> v2){
    if(v1.size()!=v2.size()){
        return 0;
    }
    else{
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]){
                return 0;
            }
        }
        return 1;
    }
}

void dfs(vector<int> &c,vector<int> &tmp,vector<vector<int>> &ans,int t,int s,int start){
    if(s>t){
        return;
    }
    if(s==t){
        bool flag=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==tmp){
                flag=1;
            }
        }
        if(!flag){                              //��֤ans��tmp���ظ�
            ans.push_back(tmp);
        }
        return;
    }
    if(s<t){
        for(int i=start;i<c.size();i++){
            tmp.push_back(c[i]);
            dfs(c,tmp,ans,t,s+c[i],i+1);        //start��Ϊi+1��֤��ȡԪ�ز��ظ�
            tmp.pop_back();
        }
    }
    return;
}

void print(vector<int> &v){
    cout<<"[";
    for(int i=0;i<v.size()-1;i++){
        cout<<v[i]<<",";
    }
    cout<<v[v.size()-1]<<"]"<<endl;
}

int main(){
    vector<int> candidates{10,1,2,7,6,1,5};
    int targets=8;
    sort(candidates.begin(),candidates.end());
    vector<int> tmp;
    vector<vector<int>> ans;
    dfs(candidates,tmp,ans,targets,0,0);
    
    cout<<"["<<endl;
    for(int i=0;i<ans.size();i++){
        print(ans[i]);
    }
    cout<<"]"<<endl;

    return 0;
}