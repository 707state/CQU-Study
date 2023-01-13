/*˳��ջ
*/
#include <iostream>
#include <stack>
using namespace std;

typedef int ElemType;
struct SqStack{
    ElemType *elem;             //����
    int maxSize;
	int top;					//ջ��Ԫ���±�
};

//ȫ�ֺ�����Ҫ�Ķ�SqStack����˲�������Ϊ��������
void InitStack(SqStack &sq){
	cin>>sq.maxSize;
	sq.top=-1;					//top��ʾջ��Ԫ�أ���˳�ֵ����Ϊ0
	sq.elem=new ElemType[sq.maxSize];
	int n;
	while(cin>>n && n!=-1){
		if(sq.top<sq.maxSize){
			sq.elem[sq.top+1]=n;
			sq.top++;
		}
		else{
			cout<<"SqStack is full!"<<endl;
			break;
		}
	}
}
void push(SqStack &sq,ElemType it){
	if(sq.top<sq.maxSize){
		sq.elem[sq.top+1]=it;
		sq.top++;
	}
	else{
		cout<<"SqStack is full!"<<endl;
	}
}
void pop(SqStack &sq){
	if(sq.top>=0){
		sq.top--;
	}
	else{
		cout<<"SqStack is empty!"<<endl;
	}
}
ElemType topValue(SqStack sq){
	//ʹ��ǰ���жϷǿ�
	return sq.elem[sq.top];
}
int size(SqStack sq){
	return sq.top+1;
}

int main(){
	SqStack sq1;
	InitStack(sq1);
	cout<<sq1.top<<endl;
	push(sq1,98);
	cout<<topValue(sq1)<<endl;
	pop(sq1);
	cout<<topValue(sq1)<<endl;

	return 0;
}