/*���ݼ�֦��
��Ŀ������ܺ�I������һ�����ظ�Ԫ�ص�����candidates��һ��Ŀ���� target��
    �ҳ�candidates�����п���ʹ���ֺ�Ϊtarget����ϡ�
    candidates �е����ֿ����������ظ���ѡȡ��
˼·��ʹ���������������ͼ��Ϊһ�����νṹ����0��Ϊ���ڵ㣬�����ӷ���
    ���ڵ��ߵ�7���ߴ���7��ʱ����ݡ�
    ����ڵ�ֵΪ7����Ϊ�ҵ�һ���������������������������7�����ȥ��
    ��Ϊ����candidates��������������������Ϊ���򣨴˴���Ϊ��֦����
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
//t��ʾĿ���,s��ʾ��ǰ�ڵ��,c��ʾcandidates,tmp��ʾ��ǰ����,ans��ʾ���մ�,start��ʾ������ʼֵ
    if(s>t){
        //s-=tmp.back();
        //tmp.pop_back();     //������Ҫ��ԭ����Ϊs<t���л�ԭ
        return;
    }
    if(s==t){
        bool flag=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==tmp){
                flag=1;
            }
        }
        if(!flag){          //��֤ans��tmp���ظ�
            ans.push_back(tmp);
        }
        //s-=tmp.back();
        //tmp.pop_back();
        return;
    }
    //s>t��s=t����Դ��s<t
    if(s<t){
        for(int i=start;i<c.size();i++){
            tmp.push_back(c[i]);
            //s+=c[i];      
//s�Ǹ��Ʋ�������������Ķ�����Ϊ����Ķ������ݹ�s>t��ִ��s-=tmp.back()������ı䵱ǰ��s
            dfs(c,tmp,ans,t,s+c[i],i);      //start��Ϊiʵ�ּ�֦
            tmp.pop_back();                 //�˴���Ҫ��ԭ
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
    sort(candidates.begin(),candidates.end());  //���ݼ�֦ǰ������
    vector<int> tmp;                            //��ǰ���г�ʼֵΪ��
    vector<vector<int>> ans;                    //ans�����洢��������
    dfs(candidates,tmp,ans,targets,0,0);        //��ʼ״̬�½ڵ��Ϊ0����ʼֵΪ0
    
    cout<<"["<<endl;
    for(int i=0;i<ans.size();i++){
        print(ans[i]);
    }
    cout<<"]"<<endl;

    return 0;
}