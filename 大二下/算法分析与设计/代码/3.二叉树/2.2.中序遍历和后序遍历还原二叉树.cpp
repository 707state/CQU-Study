/*��������ͺ��������ԭ�����������ǰ�������
˼·��
    1.���ݺ��������������һ��Ԫ��Ϊ�������ĸ���㣻
    2.�۲�������������������Ҳ��Ϊ�����������������Ϊ�����������ҡ����������ظ�����1��
    ����������� ����������ǰ�������κ�Ԫ�أ�����������ң��󣩷�֧Ϊ�գ�
    3.����Ĺ����ǵݹ�ġ����ҵ���ǰ���ĸ���㣬Ȼ�󻮷�Ϊ�����������ٷֱ�����ҡ��������ظ�
    ����Ĺ��̣����ջ�ԭһ������
��������������ǰ�����Ϊ GDA##FE#MH##Z##)���������ΪAEFDHZMG���������ΪADEFGHMZ��������˼
·��⣺
    1.GΪ�������ADEFGHMZ�ĸ���㣬�������HMZΪ����������ADEFΪ����������
        1.1.MΪ�������HMZ�ĸ���㣬�������ZΪ����������HΪ����������
            1.1.1.ZΪ�������H�ĸ���㣬��ǰ�����κ�Ԫ�أ���Z�����ҷ�֧Ϊ�գ�
            1.1.2.HΪ�������Z�ĸ���㣬��ǰ�����κ�Ԫ�أ���H�����ҷ�֧Ϊ�գ�
        1.2.DΪ�������ADEF�ĸ���㣬�������EFΪ����������AΪ����������
            1.2.1.FΪ�������EF�ĸ���㣬F���ҷ�֧Ϊ�գ��������EΪ����������
                1.2.1.1.EΪ�������E�ĸ���㣬��ǰ�����κ�Ԫ�أ���E�����ҷ�֧Ϊ�գ�
            1.2.2.AΪ�������A�ĸ���㣬��ǰ�����κ�Ԫ�أ���A�����ҷ�֧Ϊ�գ�
    ������������ɣ�ǰ�����ΪGDAFEMHZ
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

void PrevOrder(BTNode* root){
	if(root==NULL){
		return;
	}
	printf("%c",root->node);
	PrevOrder(root->left);
	PrevOrder(root->right);
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
    (*index)--;
    root->right=CreateTree(str1,subs2,index);
    root->left=CreateTree(str1,subs1,index);
    return root;
}
int main(){
    string str1,str2;
    getline(cin,str1);                  //�������
    getline(cin,str2);                  //�������
    int index=str2.length()-1;
    BTNode* root=CreateTree(str1,str2,&index);
    PrevOrder(root);
    
    return 0;
}