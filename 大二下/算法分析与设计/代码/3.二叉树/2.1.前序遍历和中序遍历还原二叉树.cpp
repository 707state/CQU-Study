/*ǰ����������������ԭ��������������������
˼·��
    1.����ǰ������������һ��Ԫ��Ϊ�������ĸ���㣻
    2.�۲����������������������Ϊ��������������Ҳ��Ϊ���������������������ظ�����1��
    ����������� ���������ǰ���������κ�Ԫ�أ�������������ң���֧Ϊ�գ�
    3.����Ĺ����ǵݹ�ġ����ҵ���ǰ���ĸ���㣬Ȼ�󻮷�Ϊ�����������ٷֱ�������������ظ�
    ����Ĺ��̣����ջ�ԭһ������
��������������ǰ�����Ϊ GDA##FE#MH##Z##)��ǰ�����ΪGDAFEMHZ���������ΪADEFGHMZ��������˼
·��⣺
    1.GΪ�������ADEFGHMZ�ĸ���㣬�������ADEFΪ����������HMZΪ����������
        1.1.DΪ�������ADEF�ĸ���㣬�������AΪ����������EFΪ����������
            1.1.1.AΪ�������A�ĸ���㣬��ǰ�����κ�Ԫ�أ���A�����ҷ�֧Ϊ�գ�
            1.1.2.FΪ�������EF�ĸ���㣬�������EΪ����������F���ҷ�֧Ϊ�գ�
                1.1.2.1.EΪ�������E�ĸ���㣬��ǰ�����κ�Ԫ�أ���E�����ҷ�֧Ϊ�գ�
        1.2.MΪ�������HMZ�ĸ���㣬�������HΪ����������ZΪ����������
            1.2.1.HΪ�������H�ĸ���㣬��ǰ�����κ�Ԫ�أ���H�����ҷ�֧Ϊ�գ�
            1.2.2.ZΪ�������Z�ĸ���㣬��ǰ�����κ�Ԫ�أ���Z�����ҷ�֧Ϊ�գ�
    ������������ɣ��������ΪAEFDHZMG��
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef char BTDataType;
struct BTNode{
	BTDataType node;
	BTNode* left;
	BTNode* right;
};

void PostOrder(BTNode* root){
	if(root==NULL){
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c",root->node);
}

BTNode* CreateTree(string str1,string str2,int* index){
    if(str2.empty()){
        return NULL;
    }
    int tmp=str2.find(str1[*index]);    //���������str2���ҵ������
    string subs1=str2.substr(0,tmp);    //��ȡstr2������������
    string subs2(str2,tmp+1);           //��ȡstr2������������
    BTNode* root=new BTNode[sizeof(BTNode)];
	root->node=str1[*index];            //��ʼ��
    root->left=NULL;
    root->right=NULL;
    (*index)++;
    root->left=CreateTree(str1,subs1,index);
    root->right=CreateTree(str1,subs2,index);
    return root;
}
int main(){
    string str1,str2;
    getline(cin,str1);                  //ǰ�����
    getline(cin,str2);                  //�������
    int index=0;
    BTNode* root=CreateTree(str1,str2,&index);
    PostOrder(root);
    
    return 0;
}