/*��ʽ���У�Ϊ�������������һ��ͷ���
*/
#include <iostream>
using namespace std;
#define NoExst 999999

struct Node{
    int elem;
    Node *next;
};

void InitLinkQueue(Node* head,Node* tail){
	Node HeadNode={NoExst,NULL};
	head=&HeadNode;						//headָ���ͷ�������Ƕ��еĵ�һ��Ԫ��
	Node* current=head;
	tail=current;
	int n;
    while(cin>>n && n!=-1){
        Node* node=new Node{n,NULL};
        current->next=node;
        current=node;
		tail=current;					//tail��ʱָ��current��ָλ��
    }
}
void push(Node* tail,int it){
	tail->next=new Node{it,NULL};
	tail=tail->next;
}
int pop(Node* head){
	Node* node=head->next;
	int tmp=node->elem;
	head->next=node->next;				//��ͷָ��ָ��ڶ���Ԫ��
	delete node;
	return tmp;
}
int frontValue(Node* head){
	return head->next->elem;
}
int rearValue(Node* tail){
	return tail->elem;
}

int main(){
	Node* head=NULL;
	Node* tail=NULL;
	InitLinkQueue(head,tail);
	push(tail,527);
	cout<<tail->elem<<endl;
	cout<<pop(head)<<endl;
	cout<<frontValue(head)<<endl;
	cout<<rearValue(tail)<<endl;

	return 0;
}