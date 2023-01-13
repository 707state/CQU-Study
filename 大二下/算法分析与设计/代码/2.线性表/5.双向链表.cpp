#include <iostream>
using namespace std;
#define NoExst 999999

struct Node{
    int elem;
    Node *pre;
    Node *next;
};

Node* head=NULL;
Node* tail=NULL;
void InitList(){
    int n;
    Node HeadNode={NoExst,NULL,NULL};       //HeadNode��ʾ��ͷ�������������Ϣ
    Node TailNode={NoExst,NULL,NULL};       //TailNode��ʾĩβ�������������Ϣ
    HeadNode.next=&TailNode;
    TailNode.pre=&HeadNode;
    head=&HeadNode;                         //headΪ��ͷָ�룬ָ���ͷ
    tail=&TailNode;                         //tailΪβ��ָ�룬ָ��ĩβ
    Node* current=head;                     //currentָ��ǰ�ڵ㣬��ֵΪhead
    while(cin>>n && n!=-1){
        Node* node=new Node{n,current,&TailNode};
        current->next=node;
        tail->pre=node;
        current=node;
    }
    return;
}

int main(){
    InitList();
    cout<<"Sequential output:";
    Node* tmp1=head->next;
    while(tmp1!=tail){                      //��Ϊ����TailNode�����Բ�����NULL�ж�
        cout<<tmp1->elem<<" ";
        tmp1=tmp1->next;
    }    
    cout<<endl<<"Reverse order output:";
    Node* tmp2=tail->pre;
    while(tmp2!=head){                      //�˴����������쳣����˵Ϊ��ɭ��bug��һʱ���Խ��
        cout<<tmp2->elem<<" ";
        tmp2=tmp2->pre;
    }
    

    return 0;
}