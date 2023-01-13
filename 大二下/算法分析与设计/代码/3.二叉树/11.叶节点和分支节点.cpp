/*��������Ҷ�ڵ����֧�ڵ�ʹ�ò�ͬ����ʵ�ִ洢��ͬ���͵����ݡ�ʵ������ʽ������ʱҶ�ڵ㲻�ٴ洢
    �ӽڵ��ָ��
*/
#include <iostream>
using namespace std;

class VarBinNode{
public:
    virtual ~VarBinNode(){}
    virtual bool isLeaf()=0;
    virtual void traverse()=0;              //���������Ϣ
};
class LeafNode:public VarBinNode{
private:
    int Operand;                            //������
public:
    LeafNode(const int& val){
        Operand=val;
    }
    bool isLeaf(){
        return true;
    }
    int value(){
        return Operand;
    }
    void traverse(){
        cout<<"Leaf:"<<value()<<endl;
    }
};
class IntlNode:public VarBinNode{
private:
    VarBinNode* lc;
    VarBinNode* rc;
    char Operator;                          //������
public:
    IntlNode(const char& op,VarBinNode* l,VarBinNode* r){
        Operator=op;
        lc=l;
        rc=r;
    }
    bool isLeaf(){
        return false;
    }
    VarBinNode* left(){
        return lc;
    }
    VarBinNode* right(){
        return rc;
    }
    char value(){
        return Operator;
    }
    void traverse(){
        cout<<"Internal:"<<value()<<endl;
        if(left()!=NULL){
            left()->traverse();
        }
        if(right()!=NULL){
            right()->traverse();
        }
    }
};

int main(){
    

    return 0;

}