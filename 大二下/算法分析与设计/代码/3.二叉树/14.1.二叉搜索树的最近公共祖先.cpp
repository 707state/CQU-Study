/* ����������������������ȣ�
��Ŀ������һ�ö���������������������У�Ҫ�����ҳ���������������������Ƚ�㣨��� LCA����
���룺��һ�и�������������������ѯ�Ľ����� M���� 1 000���Ͷ����������н����� N���� 10 000����
    ���һ�и���N����ͬ��������Ϊ����������������������С����M�У�ÿ�и���һ��������ֵU��V������
    ��ֵ��������int��Χ�ڡ�
�������ÿһ�Ը�����U��V������ҵ�A�����ǵ�����������Ƚ��ļ�ֵ������һ���������LCA of U and V 
    is A.���������U��V�е�һ���������һ���������ȣ�����һ���������X is an ancestor of Y.����
    ����X���Ǹ����Ƚ��ļ�ֵ��Y����һ����ֵ������������������Ҳ�����U��VΪ��ֵ�Ľ�㣬�����
    ��ERROR: U is not found.�����ߡ�ERROR: V is not found.�������ߡ�ERROR: U and V are not found.����
˼·����U V�ֱ���ĳһ�������������ʱ���ýڵ㼴Ϊ��������
    ϸ�ڴ������ȵ�����жϸ��ڵ��ֵ
    ���˷�������������ʱ�㣩
*/
#include <iostream>
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
BSTNode* inserthelp(BSTNode* root,const int& it){
    if(root==NULL){
        return new BSTNode(it,NULL,NULL);
    }
    if(it<root->value){
        root->lc=(inserthelp(root->lc,it));
    }
    else{
        root->rc=(inserthelp(root->rc,it));
    }
    return root;
}
bool isintree(BSTNode* root,int a){
    if(root==NULL){
        return 0;
    }
    if(root->value==a){
        return 1;
    }
    else if(root->value>a){
        return isintree(root->lc,a);
    }
    else{
        return isintree(root->rc,a);
    }
}
int LCA(BSTNode* root,int U,int V){
    if(root==NULL){
        return NULL;
    }
    if(root->value==U){
        return U;
    }
    if(root->value==V){
        return V;
    }
    if((isintree(root->lc,U)&&isintree(root->rc,V))||(isintree(root->lc,V)&&isintree(root->rc,U))){
        return root->value;
    }
    if(isintree(root->lc,U)&&isintree(root->lc,V)){
        return LCA(root->lc,U,V);
    }
    else{
        return LCA(root->rc,U,V);
    }
}

int main(){
    int M,N;
    cin>>M>>N;
    int n;
    cin>>n;
    BSTNode root(n,NULL,NULL);          //��������ͷ��㣬��˸��ڵ���뵥������
    BSTNode* rt=&root;
    for(int i=1;i<N;i++){
        cin>>n;
        rt=inserthelp(rt,n);
    }
    for(int i=0;i<M;i++){
        int U,V;
        cin>>U>>V;
        if(!isintree(rt,U)&&!isintree(rt,V)){
            cout<<"ERROR: "<<U<<" and "<<V<<" are not found."<<endl;
        }
        else if(!isintree(rt,U)){
            cout<<"ERROR: "<<U<<" is not found."<<endl;
        }
        else if(!isintree(rt,V)){
            cout<<"ERROR: "<<V<<" is not found."<<endl;
        }
        else{
            if(LCA(rt,U,V)==U&&U==V){
                cout<<U<<" is an ancestor of "<<V<<"."<<endl;   //�����ﲻ�壬���ֲ��Ե�2�𰸴�����д
            }
            else if(LCA(rt,U,V)==U){
                cout<<U<<" is an ancestor of "<<V<<"."<<endl;
            }
            else if(LCA(rt,U,V)==V){
                cout<<V<<" is an ancestor of "<<U<<"."<<endl;
            }
            else{
                cout<<"LCA of "<<U<<" and "<<V<<" is "<<LCA(rt,U,V)<<"."<<endl;
            }
        }
    }
    

    return 0;

} 