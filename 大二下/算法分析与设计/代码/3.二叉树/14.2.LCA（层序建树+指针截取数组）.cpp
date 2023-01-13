/*��������������ʱ��ÿ����һ���ڵ㶼��Ҫ�Ӹ��ڵ���������ڵ����϶�ʱ���׳�ʱ��14.1�����н����ຯ��
    ��ע�͵���ֻ����inserthelp���������������Ե����г�ʱ���������������������ȡ��
�����Ż������ò��������Դ�󽵵�ʱ�临�Ӷȡ��ɶ���������ǰ��pre������in�ɵö������������������
    ǰ�������Ϊ���룬���������Ϊ�������������
    ͬʱΪ�˼�С���Ҹ��Ӷȣ�isintree�Ĺ�����map��ʵ�֣�map[node]!=0����ڵ�������
*/
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class BSTNode{
public:
    int value;
    BSTNode* lc;
    BSTNode* rc;

    BSTNode(){lc=rc=NULL;}
    BSTNode(int v,BSTNode* l=NULL,BSTNode* r=NULL){
        value=v;
        lc=l;
        rc=r;
    }
    ~BSTNode(){}
};
/*��ǰ������������������������������������������ҵ�ǰ������ĵ�һ��Ԫ�أ���������и�Ԫ�����Ϊ
���������ұ�Ϊ���������ֱ�������ٵݹ飬�ɴ�ʵ�ֲ�����
*/
BSTNode* BuildTree(int cnt,int* pre,int* in){   //��һ������Լ���������λ�ã�int*+iֻ������������ʼλ�ã�
    if(cnt<1){
        return NULL;                            //����
    }
    BSTNode* root=new BSTNode();
    root->value=pre[0];
    int i=0;
    for(;i<cnt;i++){
        if(pre[0]==in[i]){
            break;
        }
    }
    //��ָ�봫��������ʵ������Ľ�ȡ
    root->lc=BuildTree(i,pre+1,in);             //0~iΪǰ�����������
    root->rc=BuildTree(cnt-i-1,pre+i+1,in+i+1); //cnt-i-1~cntΪ������
    return root;
}

int LCA(BSTNode* root,int U,int V){
    if(root==NULL){
        return NULL;
    }
    // if(root->value==U){
    //     return U;
    // }
    // if(root->value==V){
    //     return V;
    // }
    // if((isintree(root->lc,U)&&isintree(root->rc,V))||(isintree(root->lc,V)&&isintree(root->rc,U))){
    //     return root->value;
    // }
    //�����������������һ���������
    // if(isintree(root->lc,U)&&isintree(root->lc,V)){
    //     return LCA(root->lc,U,V);
    // }
    // else{
    //     return LCA(root->rc,U,V);
    // }
    //isintree(root->lc,U)�ȼ���U<root->value������Сʱ�临�Ӷ�
    if(U>root->value&&V>root->value){
        return LCA(root->rc,U,V);
    }
    if(U<root->value&&V<root->value){
        return LCA(root->lc,U,V);
    }
    else{
        return root->value;
    }
}


int main(){
    int M,N;
    cin>>M>>N;
    int n;                      //�ڵ�ֵ
    int* pre=new int[N];        //ǰ�����
    int* in=new int[N];         //�������
    map<int,int> mp;            //�жϽڵ��Ƿ�������
    BSTNode* rt=NULL;
    for(int i=0;i<N;i++){
        cin>>n;
        mp[n]=1;
        pre[i]=n;
        in[i]=n;
    }
    sort(in,in+N);
    rt=BuildTree(n,pre,in);
    for(int i=0;i<M;i++){
        int U,V;
        cin>>U>>V;
        if(!mp[U]&&!mp[V]){
            cout<<"ERROR: "<<U<<" and "<<V<<" are not found."<<endl;
        }
        else if(!mp[U]){
            cout<<"ERROR: "<<U<<" is not found."<<endl;
        }
        else if(!mp[V]){
            cout<<"ERROR: "<<V<<" is not found."<<endl;
        }
        else{
            int lca=LCA(rt,U,V);                //��εݹ�����ʱ��
            if(lca==U){
                cout<<U<<" is an ancestor of "<<V<<"."<<endl;
            }
            else if(lca==V){
                cout<<V<<" is an ancestor of "<<U<<"."<<endl;
            }
            else{
                cout<<"LCA of "<<U<<" and "<<V<<" is "<<lca<<"."<<endl;
            }
        }
    }
    

    return 0;
} 