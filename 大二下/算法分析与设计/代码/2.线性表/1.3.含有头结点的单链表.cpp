#include <iostream>
using namespace std;
#define NoExst 999999

struct Node{
    int elem;
    Node *next;
};

Node* head=NULL;
void InitList(){
    int n;
    Node HeadNode={NoExst,NULL};        //HeadNode��ʾ��ͷ�������������Ϣ��ֻ��Ϊ��ͷʹ��
    head=&HeadNode;                     //headΪ��ͷָ�룬ָ���ͷ
    Node* current=head;
    while(cin>>n && n!=-1){
        Node* node=new Node{n,NULL};
        current->next=node;             //����һ����nextָ��ָ���µĽڵ�
        current=node;                   //currentָ���½��
    }
    return;
}
int OddNumber(){
    int sum=0;
    Node* current=head;
    while(current->next!=NULL){
        if(current->next->elem%2!=0){
            sum++;
        }
        current=current->next;
    }
    return sum;
}

int main(){
    InitList();
    printf("The number of odd numbers is %d.\n", OddNumber());
    return 0;
}