/*�ṹ�嶨��Ķ�����ֻ����ɼ򵥵Ĳ������ڵ�Ҳֻ�ܴ洢��ֵ���ô����޵��Ƚϼ�
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

//��ʽ�������Ľ������
typedef char BTDataType;        //����д洢��Ԫ�����ͣ���charΪ����

//��ʽ�������Ľṹ��Binary Tree Node��������㣩
/*�ṹ�����������3����Ա����㡢���ӡ����ӣ���������ָ�붨�����������Ѱ��������������������
	���Ը�Ϊ�գ���NULL
*/
struct BTNode{
	BTDataType node;            //���
	BTNode* left;               //��ָ�루ָ�����ӣ�
	BTNode* right;              //��ָ�루ָ���Һ��ӣ�
};

//��������غ�������
void PrevOrder(BTNode* root);				//ǰ�����
void InOrder(BTNode* root);					//�������
void PostOrder(BTNode* root);				//�������
void LevelOrder(BTNode* root);				//�������
int BTSize(BTNode* root);					//���ĸ���
int BTKLevelSize(BTNode* root,int k);		//��k����ĸ���
int BTMaxDepth(BTNode* root);				//����������
BTNode* invertTree(BTNode* root);			//��ת������
void BTDestroy(BTNode* root);				//������������
BTNode* CreateTree(string str,int* index);	//������

//��ӡ������
//ǰ�����������˳�򣺸�->������->������
void PrevOrder(BTNode* root){
	if(root==NULL){             //����Ϊ��
		cout<<"#";
		return;
	}
	//��->������->������
	printf("%c",root->node);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
//�������������˳��������->��->������
void InOrder(BTNode* root){
	if(root==NULL){
		cout<<"#";
		return;
	}
	//������->��->������
	InOrder(root->left);
	printf("%c",root->node);
	InOrder(root->right);
}
//�������������˳��������->������->��
void PostOrder(BTNode* root){
	if(root==NULL){
		cout<<"#";
		return;
	}
	//������->������->��
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c",root->node);
}
//�������������˳�����϶��£���������������
/*˼·��
	1.�ȰѸ�����У�Ȼ��ʼ�Ӷ�ͷ�����ݡ�
	2.����ͷ�����ݣ����������Ӻ��Һ������δӶ�β����У�NULL������У���
	3.�ظ����в���2��ֱ������Ϊ��Ϊֹ��
*/
void LevelOrder(BTNode* root){
	queue<BTNode*> q;			//��ʼ������
	if (root!=NULL)
		q.push(root);
	while(!q.empty()){			//�����в�Ϊ��ʱ��ѭ������
		BTNode* front=q.front();//��ȡ��ͷԪ��
		q.pop();				//ɾ����ͷԪ��
		printf("%c ",front->node);
		if (front->left){		//���ӷǿ�
			q.push(front->left);//����Ԫ�ص����������
		}
		if (front->right){
			q.push(front->right);//����Ԫ�ص����������
		}
	}
}

//���ĸ������ݹ飩
/*������Ľ������ʱ�����Խ��������������ݹ飺
	1.��Ϊ�գ��������Ϊ0��
	2.����Ϊ�գ��������=������������+������������+1���Լ���
*/
int BTSize(BTNode* root){	
	//������=�������Ľ�����+�������Ľ�����+�Լ�
	return root==NULL ? 0 : BTSize(root->left)+BTSize(root->right)+1;
}
//��k����ĸ������ݹ飩
/*����ڸ����ĵ�k����ĸ���=������Ը��������Ϊ���ĵ�k-1����ĸ���+������Ը��������
	Ϊ���ĵ�k-1����ĸ�����
*/
int BTKLevelSize(BTNode* root,int k){
	if(k<1 || root==NULL){      //����������kֵ���Ϸ�
		return 0;
    }
	if (k==1){                	//��һ�������
		return 1;
    }
	return BTKLevelSize(root->left,k-1)+BTKLevelSize(root->right,k-1);
}

//����������
/*�����⣺
	1.��Ϊ�գ������Ϊ0��
	2.����Ϊ�գ������������� = ������������Ƚϴ��ֵ + 1
*/
int BTMaxDepth(BTNode* root){
	if (root==NULL)				//���������Ϊ0
		return 0;
	//���������� = ������������Ƚϴ��ֵ + 1
	return max(BTMaxDepth(root->left), BTMaxDepth(root->right)) + 1;
}

//��ת������
/*���裺
    1.��ת��������
    2.��ת��������
    3.��������������λ�á�
*/
BTNode* invertTree(BTNode* root){
	if(root==NULL){             //��Ϊ�գ�ֱ�ӷ���
		return NULL;
    }
	BTNode* left=invertTree(root->left);
	BTNode* right=invertTree(root->right);
	//��������λ�ý���
	root->left=right;
	root->right=left;
	return root;
}

//������������
/*�����������٣����������ݽṹ���������ƣ�����һ�߱���һ�����١����Ƕ�������Ҫע�����ٽ���˳��
    ����ʱ����Ӧ��ѡ�ú��������Ҳ����˵������˳��Ӧ��Ϊ��������->������->�������Ǳ����Ƚ�������
    �����٣���������ٸ���㣬�������ٸ���㣬��ô�������������޷��ҵ���Ҳ���޷������ˡ�
*/
void BTDestroy(BTNode* root){
	if (root == NULL){
        return;
    }
	BTDestroy(root->left);      //����������
	BTDestroy(root->right);     //����������
	free(root);                 //�ͷŸ����
}

//�ӿڣ�������
/*��Ŀ����һ�����򣬶���һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢����
	�������µ���������ַ�����ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������
	������˶������Ժ��ٶԶ������������������������������
���룺����1���ַ��������Ȳ�����100��
������������ַ������������������������������У�ÿ���ַ����涼��һ���ո�ÿ��������ռһ�С�
˼·�����δ��ַ�����ȡ�ַ���
	1.�����ַ�����#���������ȹ�����ֵ�Ľ�㣬Ȼ��ݹ鹹��������������������
	2.�����ַ���#����˵����λ��֮�²����ٹ�������ˣ����ؼ��ɡ�
	����������ʹ�����������ӡ�����������ݼ��ɡ�
*/
BTNode* CreateTree(string str,int* index){
    if(str[*index]=='#'){
        (*index)++;
        return NULL;
    }
    //����NULL���������
	//����Ҫ��̬�����ڴ棬����ᱻ���գ��޷�ʵ��ȫ�ֱ������������
    BTNode* root=new BTNode[sizeof(BTNode)];
	root->node=str[*index];		//��ʼ��
    root->left=NULL;
    root->right=NULL;
    (*index)++;
    //�ݹ鹹��������
    root->left=CreateTree(str, index);
    //�ݹ鹹��������
    root->right=CreateTree(str, index);
    return root;
}

int main(){
    string str;					//����ǰ������ַ���
    getline(cin,str);
    int index=0;
    BTNode* root=CreateTree(str,&index);
    InOrder(root);				//�����������ַ���
    
    return 0;
}