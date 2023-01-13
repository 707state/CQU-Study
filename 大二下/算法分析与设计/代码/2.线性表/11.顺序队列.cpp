/*˳����У��ٶ�������ѭ���ģ��������ж�ָ̬��front��rear����������ƶ����С�����
�˴�Ϊ����front��rear�غ�ʱ�޷��б�����Ϊ�ջ�����������n+1������洢n��Ԫ�صķ���
*/
#include <iostream>
#include <stack>
using namespace std;

typedef int ElemType;
struct SqQueue{
    ElemType *array;            //����
    int maxSize;				//˳���������ݻ�
	int front;					//����Ԫ���±�
	int rear;					//��βԪ�ص���һ���±�
};

void InitQueue(SqQueue &sq){
	int size;
	cin>>size;
	sq.maxSize=size+1;
	cin>>sq.front;
	cin>>sq.rear;
	sq.array=new ElemType[sq.maxSize];
	for(int i=sq.front;;i++){
		if((i%sq.maxSize)==sq.rear){
			break;				//�����β
		}
		int n;
		cin>>sq.array[i];
	}
}
void push(SqQueue &sq,ElemType it){
	if(sq.front==sq.rear){		//��������
		cout<<"SqStack is full!"<<endl;
	}
	else{
		sq.array[sq.rear]=it;
		sq.rear=(sq.rear+1)%sq.maxSize;
	}
}
void pop(SqQueue &sq){
	if(sq.front==sq.rear){
		cout<<"SqStack is empty!"<<endl;
	}
	else{
		sq.front=(sq.front+1)%sq.maxSize;
	}
}
ElemType frontValue(SqQueue sq){
	//ʹ��ǰ���жϷǿ�
	return sq.array[sq.front];
}
ElemType rearValue(SqQueue sq){
	//ʹ��ǰ���жϷǿ�
	return sq.array[(sq.front-1+sq.maxSize)%sq.maxSize];
}
int size(SqQueue sq){
	int len;
	if(sq.front<sq.rear){
		len=sq.rear-sq.front;
	}
	else{
		len=sq.rear-sq.front+sq.maxSize;
	}
	return len;
}

int main(){
	SqQueue sq;
	InitQueue(sq);
	push(sq,527);
	pop(sq);
	cout<<frontValue(sq)<<endl;
	cout<<rearValue(sq)<<endl;
	cout<<size(sq)<<endl;
	for(int i=sq.front;;i++){
		if((i%sq.maxSize)==sq.rear){
			break;
		}
		cout<<sq.array[i]<<" ";
	}


	return 0;
}