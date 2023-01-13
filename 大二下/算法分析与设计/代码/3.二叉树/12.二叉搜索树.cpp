/*��������������ɶ���������
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
class BST{
private:
    BSTNode<Key,E>* root;
    int nodecount;

    //��������
    void clearhelp(BSTNode<Key,E>*);
    BSTNode<Key,E>* inserthelp(BSTNode<Key,E>*,const Key&,const E&);
    BSTNode<Key,E>* deletemin(BSTNode<Key,E>*);
    BSTNode<Key,E>* getmin(BSTNode<Key,E>*);
    BSTNode<Key,E>* removehelp(BSTNode<Key,E>*,const Key&);
    E findhelp(BSTNode<Key,E>*,const Key&) const;
    void printhelp(BSTNode<Key,E>*,int) const;

public:
    BST(){
        root=NULL;
        nodecount=0;
    }
    ~BST(){
        clearhelp(root);
    }
    void insert(const Key& k,const E& e){
    //������Ҫ�õݹ飬��nodedcount++ִֻ��һ�Σ���˵��ø����������ݹ��ɸ�������ʵ��
        root=inserthelp(root,k,e);
        nodecount++;
    }
    E remove(const Key& k){                 //ɾ��ָ����㣨��Ϊk�Ľ�㣩
        E tmp=findhelp(root,k);
        if(tmp!=NULL){
            root=removehelp(root,k);
            nodecount--;
        }
        return tmp;
    }
    E removeAny(){                          //ɾ�����øú����Ľ�㣨�����ڵ㣩
        if(root!=NULL){
            E tmp=root->element();
            root=removehelp(root,root->key());
            nodecount--;
            return tmp;
        }
        else return NULL;
    }
    E find(const Key& k) const{
        return findhelp(root,k);
    }
    int size(){
        return nodecount;
    }
    void print() const{
        if(root==NULL){
            cout<<"The BST is empty."<<endl;
        }
        else{
            printhelp(root,0);
        }
    }
};
//��������
template<typename Key,typename E>
E BST<Key,E>::findhelp(BSTNode<Key,E>* root,const Key& k) const{
    if(root==NULL){
        return NULL;
    }
    if(k<root->key()){
        return findhelp(root->left(),k);
    }
    else if(k>root->key()){
        return findhelp(root->right(),k);
    }
    else return root->element();
}
template<typename Key,typename E>
BSTNode<Key,E>* BST<Key,E>::inserthelp(BSTNode<Key,E>* root,const Key& k,const E& it){
    if(root==NULL){
        return new BSTNode<Key,E>(k,it,NULL,NULL);
    }
    if(k<root->key()){
        root->setLeft(inserthelp(root->left(),k,it));
    }
    else{
        root->setRight(inserthelp(root->right(),k,it));
    }
    return root;
}
//�˴���deleteminֱ�ӽ�ָ����С�ڵ��ָ��ָ�������ӽڵ�
template<typename Key,typename E>
BSTNode<Key,E>* BST<Key,E>::deletemin(BSTNode<Key,E>* rt){
    if(rt->left()==NULL){
        return rt->right();
    }
    else{
        rt->setLeft(deletemin(rt->left()));
        return rt;
    }
}
template<typename Key,typename E>
BSTNode<Key,E>* BST<Key,E>::getmin(BSTNode<Key,E>* rt){
    if(rt->left()==NULL){
        return rt;
    }
    else{
        return getmin(rt->left);
    }
}
template<typename Key,typename E>
BSTNode<Key,E>* BST<Key,E>::removehelp(BSTNode<Key,E>* rt,const Key &k){
    if(rt==NULL){
        return NULL;
    }
    else if(k<rt->key()){
        rt->setLeft(removehelp(rt->left(),k));
    }
    else if(k>rt->key()){
        rt->setRight(removehelp(rt->right(),k));
    }
    else{
        BSTNode<Key,E>* tmp=rt;
        if(rt->left()==NULL){
            rt=rt->right();
            delete tmp;
        }
        else if(rt->right()==NULL){
            rt=rt->left();
            delete tmp;
        }
        else{
            tmp=getmin(rt->right());
            rt->setElement(tmp->element());
            rt->setKey(tmp->key());
            rt->setRight(deletemin(rt->right()));
            delete tmp;
        }
    }
    return rt;
}
template<typename Key,typename E>
void BST<Key,E>::clearhelp(BSTNode<Key,E>* rt){
    if(rt->left()==NULL){
        return NULL;
    }
    clearhelp(rt->left());
    clearhelp(rt->right());
    delete rt;
}

int main(){
    

    return 0;

} 