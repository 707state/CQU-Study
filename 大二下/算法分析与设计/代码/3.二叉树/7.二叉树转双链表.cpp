/*������ת˫����
��Ŀ����΢�������⣩��������ת��Ϊ˫������ֱ��ʹ�ö������ڵ���Ϊ˫������Ľڵ㣬ֻ��ı���ڵ���
    left��rightָ���ֵ��ʹ��ֱ�ָ�������е���ߣ�ǰ�򣩽ڵ���ұߣ���̣��ڵ㡣ת���󣬴�˫����
    ������ (��) �˵Ľڵ��������right (left) ָ���������ֵ������������������ (�ķ�ת) �����
    ��һ�¡�
�����ӿڶ��壺
    template <typename E>
    BinNode<E>* transformBinTreeToDLList(BinNode<E>* root);
    ��������ת��Ϊ˫������������������˽ڵ��λ�á���ʼʱ��ָ��rootָ��������ĸ��ڵ㡣
˼·�������������vector��Ȼ���ٹ���˫����
*/
#include <iostream>
#include<vector>

template <typename E>
class BinNode{
public:
    virtual ~BinNode() {}
    virtual BinNode* left() const = 0; //����leftָ��ֵ
    virtual BinNode* right() const = 0; //����rightָ��ֵ
    virtual void setLeft(BinNode* ) = 0; //����leftָ��
    virtual void setRight(BinNode* ) = 0; //����rightָ��
    virtual bool isLeaf() = 0;
};
template <typename E>
BinNode<E>* constructBinTree(const int N);
//��������������������������У����ظ��ڵ�λ�ã�����ʡ�ԣ�

template <typename E>
void visit(vector<BinNode<E>*> &data,BinNode<E>*root) {
    if(root==NULL){
        return;
    }
    visit(data,root->left());
    data.push_back(root);
    visit(data,root->right());
}

template <typename E>
BinNode<E>* transformBinTreeToDLList(BinNode<E>* root) {
    vector<BinNode<E>* > res;
    visit(res,root);
    
    for(int i=1;i<res.size()-1;i++){
        res[i]->setLeft(res[i-1]);
        res[i]->setRight(res[i+1]);
    }
    res[0]->setLeft(NULL);
    res[0]->setRight(res[1]);
    res[res.size()-1]->setLeft(res[res.size()-2]);
    res[res.size()-1]->setRight(NULL);
    
    return res[0];
}

int main(){
    int N;
    //...
    BinNode<int>* root = constructBinTree<int>(N);
    root = transformBinTreeToDLList<int>(root);
    //...
    /*����˫�������������������������бȽϣ����ƥ��ɹ���
    ���"correct", �������"wrong"��������ʡ�ԣ�
    ...
    */
  return 0;

}