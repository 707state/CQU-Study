/*��ʽջ������Ҫ��ͷ��㣩
ע������ʽջջ����Ϊ��һ��Ԫ�أ���Ϊջ��top����Ϊջ����ѹ��Ԫ��ͬʱtopҲ�ڱ䣬��˲���Ҫcurrentָ��
*/
#include <iostream>
using namespace std;

typedef int ElemType;
struct Node{
    ElemType elem;
    Node *next;
};
typedef struct Node* LinkStack;         //Node�ǽ�㣬��������õ���ʽջ

void InitStack(LinkStack &top){          //top��ʾջ���������ָ������ʽջ
    int n;
    while(cin>>n && n!=-1){
        Node* node=new Node{n,top};     //�½���nextָ��ָ��ջ��
        top=node;                       //����ջ��
    }
    return;
}
void push(LinkStack &top,ElemType it){
	//Node n={it,top};                  //��ջ�з����ڴ�ֻ�ں�������Ч��main��������ʱ�����
    Node* node=new Node{it,top};
	top=node;
}
ElemType pop(LinkStack &top){
	Node* node=top;
    top=top->next;
    ElemType tmp=node->elem;
    delete node;
    return tmp;
}
ElemType topValue(LinkStack &top){
	//ʹ��ǰ���жϷǿ�
	return top->elem;
}
int size(LinkStack &top){
    if(top==NULL){
        return 0;
    }
    int cnt=1;
    while(top->next!=NULL){
        cnt++;
        top=top->next;
    }
	return cnt;
}

int main(){
    LinkStack top=NULL;
    InitStack(top);
    push(top,100);
    push(top,98);
    cout<<pop(top)<<endl;
    cout<<topValue(top)<<endl;
    cout<<size(top)<<endl;

    return 0;
}