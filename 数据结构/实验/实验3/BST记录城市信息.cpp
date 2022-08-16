/*BST��Ӧ�ã�
��Ŀ��1.����BSTʵ��һ���������ݿ⣺ÿ�����ݿ�������������ƺ�������x��y��ʾ�ĳ������ꡣ����
    ����������֯��BST��
    2.�ڸ����ݿ���ʵ�ְ��������ƽ��еĲ��롢ɾ���ͼ�����
    3.��ӡ����ָ����ĸ��ͷ�����г��м�¼��
    4.��ӡ����ָ����ľ����ڸ���ֵ֮�ڵ����г��м�¼��
    5.����ύ������ʵ�鱨���Դ����
���룺��1�У���1������m����ʾ������Ҫ�����m����¼��
    ��2�е���1+m�У�ÿ�б�ʾһ�������¼������һ���ַ���cityName����������x��y���ֱ��ʾ����
���ƺ����ꡣ
    ������n�У�Ϊ���������Ĳ����ɾ��������������Ϊ0����ɾ����������Ϊ1������룬������Ϊ2����
�������롢ɾ��������
    ������1�У�1���ַ�����ʾҪ���м�����ָ����ĸ��
    ���1�У�3��������x��y��d��x��y��ʾָ��������꣬d��ʾ���롣
�������ɲ����ɾ������֮���������BST����ӡ��ÿ����¼����һ�У���������������
    ����ָ����ĸ��ͷ�����г��м�¼��ÿ����¼����һ�У��������������֣�x��y����
    ��ӡ��ָ����ľ����ڸ���ֵ֮�ڵ����г��м�¼��ÿ����¼����һ�У��������������֣�x��y����
ע�⣺�Զ�������û���Զ�ת����NULL(long long int)�Ĺ��ܣ���������м���null()��������Ҫʱ����
    ����NULL��������Ҫ����ʵ��(�� E e)���ܵ���
����������
Input��
4
chongqing 1 1
chengdu 1 2
shenyang 2 2
changchun 2 3
1 shanghai 2 3
0 changchun
0 shenyang
1 beijing 2 2
2
c
0 0 3
Output��
beijing
chengdu
chongqing
shanghai
chengdu 1 2
chongqing 1 1
beijing 2 2
chengdu 1 2
chongqing 1 1
*/
#include <iostream>
#include <sstream>
using namespace std;

class city{
public:
    string cityName;
    int x;
    int y;
    city(string s=" ",int a=0,int b=0){
        cityName=s;
        x=a;
        y=b;
    }
    city null(){                     //������static���޷�ֱ�ӵ���E::null()
        city c("",0,0);
        return c;
    }
    string information(){
        stringstream ss;
        string s2;
        string s3;
        ss<<x;
        ss>>s2;
        ss.clear();
        ss<<y;
        ss>>s3;
        string s="";
        s+=cityName;
        s+=" ";
        s+=s2;
        s+=" ";
        s+=s3;
        return s;
    }
    char firstletter(){
        return cityName[0];
    }
    bool distance(int a,int b,int d){
        if(((a-x)*(a-x)+(b-y)*(b-y))<=d*d){     //�����ύ������ֹҵȺŲŶ�
            return 1;
        }
        else{
            return 0;
        }
    }
    // bool operator>(const city&c){       //����Ҫ���ز�����>/<
    //     return cityName>c.cityName;
    // }
    // bool operator<(const city&c){
    //     return cityName<c.cityName;
    // }
    bool operator!=(const city&c){          //��Ҫ���ز�������=
        if(cityName!=c.cityName)    return 1;
        else if(x!=c.x)     return 1;
        else if(y!=c.y)     return 1;
        else                return 0;
    }
};

// bool cmp1(city c1,city c2){          //��ʾc1<c2
//     return c1.cityName<c2.cityName;
// }
// bool cmp2(city c1,city c2){          //��ʾc1<c2
//     return c1.cityName>c2.cityName;
// }

template<typename Key,typename E>
class BSTNode{
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
    void setLeft(BSTNode<Key,E>* b){
        lc=b;
    }
    void setRight(BSTNode<Key,E>* b){
        rc=b;
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
    E findhelp(BSTNode<Key,E>*,const Key&) const;;
    void printhelp(BSTNode<Key,E>*,int) const;
    void printhelp2(BSTNode<Key,E>*,char) const;       //��ӡ�Ը����ַ���ͷ�ĳ�����Ϣ
    void printhelp3(BSTNode<Key,E>*,int,int,int) const;//��ӡ�ھ��뷶Χ�ڵĳ�����Ϣ

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
        E e;
        E tmp=findhelp(root,k);
        if(tmp!=e.null()){
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
        else{                               //�����Զ�������û��ת����int�Ĺ���
            E e;
            return e.null();
        }              
    }
    E find(const Key& k) const{
        return findhelp(root,k);
    }
    int size(){
        return nodecount;
    }
    void print() const{             //���������ӡ������Ϣ
        if(root==NULL){
            cout<<"The BST is empty."<<endl;
        }
        else{
            printhelp(root,0);
        }
    }
    void printchar(char c) const{       //���������ӡ�Ը����ַ���ͷ�ĳ�����Ϣ
        if(root==NULL){
            cout<<"The BST is empty."<<endl;
        }
        else{
            printhelp2(root,c);
        }
    }
    void printdistance(int a,int b,int d) const{    //���������ӡ�����ڵĳ�����Ϣ
        if(root==NULL){
            cout<<"The BST is empty."<<endl;
        }
        else{
            printhelp3(root,a,b,d);
        }
    }
};
//��������
template<typename Key,typename E>
E BST<Key,E>::findhelp(BSTNode<Key,E>* root,const Key& k) const{
    E e;                        //�޶����޷����ú���
    if(root==NULL){
        return e.null();
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
        return getmin(rt->left());
    }
}
template<typename Key,typename E>
BSTNode<Key,E>* BST<Key,E>::removehelp(BSTNode<Key,E>* rt,const Key &k){
    if(rt==NULL){
        return NULL;
        //return E::null();         //ֻ�Է���ֵΪE�ĺ������˴�����ֵΪָ��
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
        return;
    }
    clearhelp(rt->left());
    clearhelp(rt->right());
    delete rt;
}
template<typename Key,typename E>
void BST<Key,E>::printhelp(BSTNode<Key,E>* rt,int level) const{
    if(rt==NULL)    return;
    printhelp(rt->left(),level+1);
    cout<<rt->key()<<endl;
    printhelp(rt->right(),level+1);
    delete rt;
}
template<typename Key,typename E>
void BST<Key,E>::printhelp2(BSTNode<Key,E>* rt,char c) const{
    if(rt==NULL)    return;
    printhelp2(rt->left(),c);
    //������ֱ��ʹ��(rt->key())[0]����д�������ױ���ʧ�ܡ�����E e����
    E e=rt->element();
    if(e.firstletter()==c){
        cout<<e.information()<<endl;
    }
    printhelp2(rt->right(),c);
    delete rt;
}
template<typename Key,typename E>
void BST<Key,E>::printhelp3(BSTNode<Key,E>* rt,int a,int b,int d) const{
    if(rt==NULL)    return;
    printhelp3(rt->left(),a,b,d);
    E e=rt->element();
    if(e.distance(a,b,d)){
        cout<<e.information()<<endl;
    }
    printhelp3(rt->right(),a,b,d);
    delete rt;
}

int main(){
    int m;
    cin>>m;
    BST<string,city> bst;
    for(int i=0;i<m;i++){
        int x,y;
        string s;
        cin>>s>>x>>y;
        city c{s,x,y};
        bst.insert(s,c);
    }
    //bst.remove("changchun");
    
    string line;
    while(getline(cin,line)){
        if(line=="2"){
            break;
        }
        else if(line[0]=='0'){
            string s="";
            for(int i=2;i<line.length();i++){
                s+=line[i];
            }
            bst.remove(s);
        }
        else if(line[0]=='1'){
            string s="";
            bool flag=0;
            int x;
            int y;
            s+=line[2];
            for(int i=3;i<line.length();i++){
                if(line[i-1]==' '){
                    if(!flag){
                        x=line[i]-'0';
                        flag=1;
                        continue;       //�ո��Ĳ��ǳ�������������s
                    }
                    else{
                        y=line[i]-'0';
                        continue;
                    }
                }
                if(!flag&&line[i]!=' '){
                    s+=line[i];
                }
            }
            city c{s,x,y};
            bst.insert(s,c);
        }
    }

    char letter;
    cin>>letter;

    int a,b,d;
    cin>>a>>b>>d;

    bst.print();
    bst.printchar(letter);
    bst.printdistance(a,b,d);

    return 0;
} 