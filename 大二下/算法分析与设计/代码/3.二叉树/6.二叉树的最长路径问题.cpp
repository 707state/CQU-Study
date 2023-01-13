/*���������·�����⣺
��Ŀ������Ѷ�������������ͼ������������������ڵ���·�����ȣ���·���о����ı�������ȡ������·
    ��ָ���Ǽ�·������ͬһ���ڵ㲻����·���ϳ����������ϡ�������������нڵ�֮���·�����ȵ����
    ֵ��
�����ӿڶ��壺
template <typename E>
int LongestPathInBinaryTree(BinNode<E>* root, int& max_dist);
    ����rootָ��������ĸ�����ʼֵ����max_dist������¼���������·�����ȡ�
˼·��Ҫ�������Զ�������ڵ㣬�����������һ���Ǿ������ڵ㣬�����������и�һ���֣���һ���ǲ�������
    �ڵ㣬����/�������С�ʵ������������Թ�һ�����ö��������·������ ĳһ��� �����������+����
    ����ȡ����õݹ飬�����������������ϴ����ȣ�ͬʱ�����ڲ�ͨ���Ƚ�max_dist�������������Ե����
    ֮�ͣ����ϸ���max_dist���ݹ������max_dist��Ϊ���нڵ�֮���·�����ȵ����ֵ
*/
#include <iostream>
using namespace std;

template <typename E>
class BinNode{                              //�������ڵ�
    public:
        virtual ~BinNode() {}
        virtual BinNode* left() const = 0;  //�����������ĸ�λ��
        virtual BinNode* right() const = 0; //�����������ĸ�λ��
        virtual bool isLeaf() = 0;
}; 

template <typename E>
BinNode<E>* constructBinTree(const int N);
//����N���ڵ�Ķ����������ظ�λ�ã�����ʡ�ԣ�

template <typename E>
int LongestPathInBinaryTree(BinNode<E>* root, int& max_dist){
    //��д��root->isLeaf(),���п����Ǹýڵ������������ӣ��������root->right()ʱ����ֶδ���
    if(root==NULL){
        return -1;                  //�����˿ս�㣬��root�ĸ��ڵ�û������ӽڵ㣬��˷���-1
    }
    int LeftDepth=LongestPathInBinaryTree(root->left(),max_dist)+1;
    int RightDepth=LongestPathInBinaryTree(root->right(),max_dist)+1;
    int distance=LeftDepth+RightDepth;                  //��ǰ�ڵ���·��
    max_dist=max_dist>distance ? max_dist:distance;     //�����·��
    return LeftDepth>RightDepth ? LeftDepth:RightDepth;
}

int main(){
    int N; //�ڵ�����
    //...
    BinNode<int> root = constructBinTree<int>(N);

    int max_dist = 0;    //�·�����ȵĳ�ʼֵ
    LongestPathInBinaryTree<int>(root, max_dist);  //Ѱ���·��
    cout << max_dist << endl;      //����·���ĳ���
    //...
    return 0;
}
