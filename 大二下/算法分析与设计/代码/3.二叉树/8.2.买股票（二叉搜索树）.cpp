/*���Ʊ����ʱ���Ż���
    ����Incomeʱ����ѭ����Ȼ���������ʱ�临�Ӷȣ����ö���������������������
    �������Ĺ�Ʊ����ڵ�ֵ���Ϊ0��ɾ�������������Ч�ʣ���ɾ������ȽϺ�ʱ��
*/
#include <iostream>
using namespace std;

struct BTNode{
	int node;
	BTNode* left;
	BTNode* right;
};
BTNode* CreateTree(int n,BTNode* root){
    if(root==NULL){
        return new BTNode{n,NULL,NULL};
    }
    if(n<root->node){
        root->left=CreateTree(n,root->left);
    }
    else{
        root->right=CreateTree(n,root->right);
    }
    return root;
}
int Income=0;
int price0;                             //���һ���Ʊ�۸�
void search(BTNode* root,int n){        //��������n�ڵ�ǰ��<n�Ľڵ�
    if(root==NULL){
        return;
    }
    if(root->node!=0 && root->node<n){  //������Ʊ
        Income+=n;
        root->node=0;
    }
    search(root->left,n);
    if(root->node<n){                   //������
        search(root->right,n);
    }
}
void search(BTNode* root){              //���غ���������û�����Ĺ�Ʊ
    if(root==NULL){
        return;
    }
    if(root->node!=0){                  //û�����Ĺ�Ʊ
        Income+=price0;
    }
    search(root->left);
    search(root->right);
}
int main(){
    int N;
    cin>>N;
    BTNode* root=NULL;
    int Pay=0;
    for(int i=0;i<N-1;i++){             //���һ�첻��
        int n;
        cin>>n;       
        Pay+=n;
        root=CreateTree(n,root);
        /*�������������������У���ʱ���ϵĽڵ������n��Ϊ֮ǰ�ļ۸���˴�ʱ����ԱȽ�ǰ�漸��
        �ڵ��Ƿ���������������Ľڵ�ֵ���Ϊ0��
        */
        search(root,n);
    }
    cin>>price0;
    search(root); 
    cout<<Income-Pay<<endl;

    return 0;

}