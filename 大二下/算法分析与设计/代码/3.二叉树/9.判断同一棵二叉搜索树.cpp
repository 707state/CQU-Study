/*�Ƿ�ͬһ�ö�����������
��Ŀ������һ���������оͿ���Ψһȷ��һ�ö�����������Ȼ����һ�ø����Ķ���������ȴ�����ɶ��ֲ�ͬ�Ĳ�
    �����еõ�������ֱ�������{2, 1, 3}��{2, 3, 1}�����ʼΪ�յĶ��������������õ�һ���Ľ����
    ���Ƕ�������ĸ��ֲ������У�����Ҫ�ж������Ƿ�������һ���Ķ�����������
���룺����������������ݡ�ÿ�����ݵĵ�1�и�������������N (��10)��L���ֱ���ÿ�����в���Ԫ�صĸ�����
    ��Ҫ�������и�������2�и���N���Կո�ָ�������������Ϊ��ʼ�������С����L�У�ÿ�и���N������
    ��Ԫ�أ�����L����Ҫ�������С�
    ����������Ǳ�֤ÿ���������ж���1��N��һ�����С�������NΪ0ʱ����־����������������ݲ�Ҫ����
�������ÿһ����Ҫ�������У���������ɵĶ�������������Ӧ�ĳ�ʼ�������ɵ�һ���������Yes����������
    ����No����
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
bool CompareTree(BTNode* root1,BTNode* root2){
    if(root1==NULL && root2==NULL){     //���ǿս��
        return 1;
    }
    if(root1==NULL && root2!=NULL){     //ֻ��һ��Ϊ��
        return 0;
    }
    if(root1!=NULL && root2==NULL){
        return 0;
    }
    if(root1->node!=root2->node){       //�����ǿս��
        return 0;
    }
    if(!CompareTree(root1->left,root2->left)){
        return 0;
    }
    return CompareTree(root1->right,root2->right);
}

int main(){
    int N,L;
    while(cin>>N && N!=0){          //��д��cin>>N>>L && N!=0������ʱֻ��N=0�����޷���ֹ
        BTNode* root0=NULL;
        cin>>L;
        for(int i=0;i<N;i++){       //�������յĶ�����
            int n;
            cin>>n;
            root0=CreateTree(n,root0);
        }
        for(int j=0;j<L;j++){       //����ն������ȽϵĶ�����
            BTNode* root=NULL;
            for(int i=0;i<N;i++){
                int n;
                cin>>n;
                root=CreateTree(n,root);
            }
            if(CompareTree(root0,root)){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }

    return 0;

}