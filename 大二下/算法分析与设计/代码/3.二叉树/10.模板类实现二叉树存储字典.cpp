/*ģ����ʵ�ֶ��������Դ洢��ֵ�����ܸ�ǿ��
*/
#include <iostream>
using namespace std;

template<typename E> class BinNode{         //������
public:
    virtual ~BinNode(){}
    virtual E& element()=0;
    virtual void setElement(const E&)=0;
    virtual BinNode* left() const=0;
    virtual BinNode* right() const=0;
    virtual setLeft(BinNode*)=0;
    virtual setLeft(BinNode*)=0;
    virtual bool isLeaf()=0;
};

template<typename E>
void preorder(BinNode<E>* root){            //ǰ�����
    if(root==NULL){
        return;
    }
    //��Ҫ�����
    preorder(root->left());
    preorder(root->right());
}
template<typename E>
void inorder(BinNode<E>* root){            //�������
    if(root==NULL){
        return;
    }
    inorder(root->left());
    //��Ҫ�����
    inorder(root->right());
}
template<typename E>
void postorder(BinNode<E>* root){          //�������
    if(root==NULL){
        return;
    }
    postorder(root->left());
    postorder(root->right());
    //��Ҫ�����
}

template<typename E>
int count(BinNode<E>* root){                //����ڵ����
    if(root==NULL){
        return 0;
    }
    return 1+count(root->left())+count(root->right());
}

template<typename Key,typename E>
class BSTNode:public BinNode<E>{            //���������
private:
    Key k;
    E it;
    BSTNode* lc;
    BSTNode* rc;
public:
    BSTNode(){lc=rc=NULL;}
    BSTNode(Key K,E e,BSTNode* l=NULL,BSTNode* r=NULL){
        k=K;
        it=e;
        lc=l;
        rc=r;
    }
    ~BSTNode(){}

    E& element(){
        return it;
    }
    Key& key(){
        return k;
    }
    void setElement(const E& e){
        it=e;
    }
    void setKey(const Key& K){
        k=K;
    }

    inline BSTNode* left() const{
        return lc;
    }
    inline BSTNode* right() const{
        return rc;
    }
    void setLeft(BinNode<E>* b){
        lc=(BSTNode*)b;
    }
    void setRight(BinNode<E>* b){
        rc=(BSTNode*)b;
    }
    bool isLeaf(){
        return (lc==NULL)&&(rc==NULL);
    }
};

template<typename Key,typename E>
bool checkBST(BSTNode<Key,E>* root,Key low,Key high){   //�ж��Ƿ��Ƕ���������
    if(root==NULL){
        return true;
    }
    Key rootkey=root->key();
    if((rootkey<low)||(rootkey>high)){
        return false;
    }
    if(!checkBST<Key,E>(root->left(),low,rootkey)){
        return false;
    }
    return checkBST<Key,E>(root->right(),rootkey,high);
}


int main(){
    

    return 0;

} 