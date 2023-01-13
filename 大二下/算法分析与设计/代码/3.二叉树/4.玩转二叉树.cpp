/*��ת��������
��Ŀ������һ�ö����������������ǰ������������Ƚ����������淴ת���������ת��Ĳ�����������С�
    ��ν���淴ת����ָ�����з�Ҷ�������Һ��ӶԻ�����������ֵ���ǻ�����ȵ���������
���룺��һ�и���һ��������N����30�����Ƕ������н��ĸ������ڶ��и���������������С������и���
    ��ǰ��������С����ּ��Կո�ָ���
�������һ�������������ת��Ĳ�����������С����ּ���1���ո�ָ�������β�����ж���ո�
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

//�洢���ֿ��ܳ�����λ���ַ����������ã���˸���vector<int>
typedef int BTDataType;
struct BTNode{
	BTDataType node;
	BTNode* left;
	BTNode* right;
};

vector<int> Levelv;
void LevelOrder(BTNode* root){
	queue<BTNode*> q;
	if (root!=NULL)
		q.push(root);
	while(!q.empty()){
		BTNode* front=q.front();
		q.pop();
		Levelv.push_back(front->node);
		if (front->left){
			q.push(front->left);
		}
		if (front->right){
			q.push(front->right);
		}
	}
}

int find(vector<int> v,int n){
	for(int i=0;i<v.size();i++){
		if(v[i]==n){
			return i;
		}
	}
	return -1;
} 

BTNode* invertTree(BTNode* root){
	if(root==NULL){
		return NULL;
    }
	BTNode* left=invertTree(root->left);
	BTNode* right=invertTree(root->right);
	root->left=right;
	root->right=left;
	return root;
}

BTNode* CreateTree(vector<int> Prev,vector<int> Inv,int* index){
    if(Inv.empty()){
        return NULL;
    }
    int tmp=find(Inv,Prev[*index]);     //���������Inv���ҵ������
	vector<int> subv1;					//��ȡInv������������
	vector<int> subv2;					//��ȡInv������������
    subv1.assign(Inv.begin(),Inv.begin()+tmp);
    subv2.assign(Inv.begin()+tmp+1,Inv.end());
    BTNode* root=new BTNode[sizeof(BTNode)];
	root->node=Prev[*index];            //��ʼ��
    root->left=NULL;
    root->right=NULL;
    (*index)++;
    root->left=CreateTree(Prev,subv1,index);
    root->right=CreateTree(Prev,subv2,index);
    return root;
}
int main(){
	int N;
	cin>>N;
	vector<int> Prev;
	vector<int> Inv;
	for(int i=0;i<N;i++){               //���������������������ǰ�������ע��˳��
		int m;
		cin>>m;
		Inv.push_back(m);
	}
	for(int i=0;i<N;i++){
		int m;
		cin>>m;
		Prev.push_back(m);
	}
    int index=0;
    BTNode* root=CreateTree(Prev,Inv,&index);
    invertTree(root);
    LevelOrder(root);
	for(int i=0;i<N-1;i++){
		cout<<Levelv[i]<<" ";
	}
	cout<<Levelv[N-1];
    
    return 0;
}