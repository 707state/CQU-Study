/*���ı�����
��Ŀ������һ�ö������ĺ�������������������������������������С���������ֵ���ǻ������
	����������
���룺��һ�и���һ��������N����30�����Ƕ������н��ĸ������ڶ��и��������������С������и�
	��������������С����ּ��Կո�ָ���
�������һ������������Ĳ�����������С����ּ���1���ո�ָ�������β�����ж���ո�
˼·����֮ǰ�ַ���ͬ���������ֿ���Ϊ��λ���ַ����������ã���˸�Ϊvector<int>
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

BTNode* CreateTree(vector<int> Postv,vector<int> Inv,int* index){
    if(Inv.empty()){
        return NULL;
    }
    int tmp=find(Inv,Postv[*index]);    //���������Inv���ҵ������
	vector<int> subv1;					//��ȡInv������������
	vector<int> subv2;					//��ȡInv������������
    subv1.assign(Inv.begin(),Inv.begin()+tmp);
    subv2.assign(Inv.begin()+tmp+1,Inv.end());
    BTNode* root=new BTNode[sizeof(BTNode)];
	root->node=Postv[*index];            //��ʼ��
    root->right=NULL;
    root->left=NULL;
    (*index)--;
    root->right=CreateTree(Postv,subv2,index);
    root->left=CreateTree(Postv,subv1,index);
    return root;
}
int main(){
	int N;
	cin>>N;
	vector<int> Postv;
	vector<int> Inv;
	for(int i=0;i<N;i++){
		int m;
		cin>>m;
		Postv.push_back(m);
	}
	for(int i=0;i<N;i++){
		int m;
		cin>>m;
		Inv.push_back(m);
	}
    int index=Inv.size()-1;
    BTNode* root=CreateTree(Postv,Inv,&index);
    LevelOrder(root);
	for(int i=0;i<N-1;i++){
		cout<<Levelv[i]<<" ";
	}
	cout<<Levelv[N-1];
    
    return 0;
}