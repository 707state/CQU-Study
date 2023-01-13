/*��������ͷ��㣩ͳ������������
*/
#include <iostream>
using namespace std;

struct Node{
    int elem;
    Node *next;
};

Node* head=NULL;                //Node�ǽ�㣬��������õ�����head�ڴ˴��䵱��ͷָ��
void InitList(){
    int n;
    Node* current=head;         //currentָ��ǰ�ڵ㣬��ֵΪhead
    bool flag=0;
    while(cin>>n && n!=-1){
        //Node node={n,NULL};     //��ջ�д������ᵼ����һ��ѭ���оɽ�㱻�ջأ�����ڶ��ж�̬�����ڴ�
        Node* node=new Node{n,NULL};    //�ڶ��ж�̬�����ָ���µĽڵ��ָ��
        if(!flag){              //��ʼ��head
            head=node;
            current=head;
            flag=1;
        }
        current->next=node;     //����һ�ڵ�ָ��ָ���µĽڵ㣨��Ϊ��ָ�봫�ݣ����Կ���ֱ���޸ģ�
        current=node;           //currentָ���½��
        //�˴�node���½���ָ�룬����䱾��Ϳ�����Ϊ��ַ����currentָ��
    }
    return;
}
int OddNumber(){
    int sum=0;
    Node* current=head;
    while(current!=NULL){
        if(current->elem%2!=0){
            sum++;
            cout<<current->elem<<endl;
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