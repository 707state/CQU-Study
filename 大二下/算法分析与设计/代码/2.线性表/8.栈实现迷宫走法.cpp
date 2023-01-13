/*ջʵ���Թ��߷���
��Ŀ��һ��a*b�ľ��󣨱�Ե��Χǽ����-1��ʾǽ��0��ʾͨ·�������������㡢�յ㣬�ж��Ƿ���ͨ·
˼·����ջ�洢�߹��ĵ㣬��ʱ�̱������£�-2��ʾ���߹���-3��ʾ��·��ͨ
    1.���������ʼ����ǰ��p
    2.�ж�p�Ƿ�Ϊ����
        2.1.��pΪ���ڣ�p��ջ�����ڵ�ͼ��Ӧλ�ø�-2����ʾ�Ѿ�����Ȼ�������
        2.2.��p��Ϊ���ڣ��ж�p�Ƿ��пհ��ڽӵ�
            2.2.1.���У�p��ջ���ڵ�ͼ��Ӧλ�ø�-2��ͬʱp����Ϊ��һ���հ��ڽӵ�
            2.2.2.���ޣ���p��Ӧ�ĵ�ͼλ���ϸ�-3��ͬʱ����ջ����Ϊp
    3.ջ�ǿգ��ظ�����2
��������1��
3
1 1
3 3
-1 -1 -1 -1 -1
-1 0 0 0 -1
-1 -1 0 0 -1
-1 -1 -1 0 -1
-1 -1 -1 -1 -1
��������2:
10
1 4
1 8
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1 0 0 -1 0 0 0 -1 0 -1
-1 0 0 -1 0 0 0 -1 0 -1
-1 0 0 0 0 -1 -1 0 0 -1
-1 0 -1 -1 -1 0 0 0 0 -1
-1 0 0 0 -1 0 0 0 0 -1
-1 0 -1 0 0 0 -1 0 0 -1
-1 0 -1 -1 -1 0 -1 -1 0 -1
-1 -1 0 0 0 0 0 0 0 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/
#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

#define N 20

struct Pos{
	int x,y;
};
struct Maze{                        //�ṹ��Maze���������Թ�ͼ���������Թ�ͼ��С����㡢�յ�
	int n;                          //�Թ���С
	Pos start,end;                  //��ֹ���� 
	int maze[N][N]={0};             //�Թ��ֲ�ͼ:-1-->ǽ��0-->ͨ· 
	//maze�ǵø���ֵ������Ĭ��ֵ������ײ�������
}; 
//�������봴���Թ� 
void CreateMaze(Maze &m){
    cin>>m.n;
	cin>>m.start.x>>m.start.y;
	cin>>m.end.x>>m.end.y;
	
	for(int i=0;i<=m.n+1;i++){
		for(int j=0;j<=m.n+1;j++){
			cin>>m.maze[i][j];
		}
	}
}
//�жϵ�ǰ���Ƿ����ͨ·��ͨ�����ص�һ����ͨ�����ꣻ��ͨ�����أ�-1��-1�� 
Pos Pass(Maze m,Pos curpos){
	Pos nextpos={-1,-1};            //��ʼ����ʾ��ͨ· 
	int x=curpos.x;
	int y=curpos.y;
	//ÿ�ζ���˳����ң��߹���·�����Ϊ-2�����Բ������� 
	//�˴����ն����ϱ�˳����ң���ά����x���£�y���ң�����Ӧע�ⷽ�� 
	if(m.maze[x][y+1]==0){          //�� 
		nextpos.x=x;
		nextpos.y=y+1;
	}
	else if(m.maze[x+1][y]==0){     //�� 
		nextpos.x=x+1;
		nextpos.y=y;
	}
	else if(m.maze[x][y-1]==0){     //�� 
		nextpos.x=x;
		nextpos.y=y-1;
	}else if(m.maze[x-1][y]==0){    //�� 
		nextpos.x=x-1;
		nextpos.y=y;
	}
	return nextpos; 
}
//���Թ�
void MazePath(Maze m){
	Pos curpos=m.start;
    Pos nextpos=Pass(m,curpos);
	stack<Pos> path_stack;          //·��ջ�洢��ͨ�Թ���·��
	path_stack.push(m.start);
    while(!path_stack.empty()){
		nextpos=Pass(m,curpos);
        if(curpos.x==m.end.x && curpos.y==m.end.y){ //��ǰ��Ϊ�յ�
			path_stack.push(curpos);                //��ǰ����·��ջ
			m.maze[curpos.x][curpos.y]=-2;          //�߹����Ϊ-2
			break;
		}
        else{
            if(nextpos.x!=-1){                      //��·��ͨ 
			    path_stack.push(curpos);            //��ǰ����·��ջ
			    m.maze[curpos.x][curpos.y]=-2;      //�õ��Ѿ��߹�
			    curpos = nextpos;                   //��ǰ�����Ϊ��һ���� 
		    }
		    else{
			    m.maze[curpos.x][curpos.y]=-3;      //��ʾ��ǰ�㲻ͨ
			    curpos=path_stack.top();            //��ǰ�����Ϊջ��Ԫ�� 
			    path_stack.pop();                   //ɾ��ջ�� 
		    } 
        }
    }
	//չʾ���
	if(path_stack.empty()){
        cout<<"��·һ����"<<endl;
    }
 	else{
        cout<<"�ɹ��߳��Թ���"<<endl;
 		stack<Pos> tmp_stack;       //����path_stack������Ԫ�������������tmp_stack�洢
		int ord=0; 
 		//�����Ϊ1�Ĳ�ȫ��·���ϵĵ㣬����ջ��һ����·���ϵĵ� 
 		while(!path_stack.empty()){
 			curpos=path_stack.top();
 			path_stack.pop();
 			tmp_stack.push(curpos);	
		}
		while(!tmp_stack.empty()){
 			curpos=tmp_stack.top();
 			tmp_stack.pop();
 			m.maze[curpos.x][curpos.y]=ord;
            ord++;
		}
 		cout<<endl;
		for(int i=0;i<=m.n+1;i++){
			for(int j=0;j<=m.n+1;j++){
				if(m.maze[i][j]>0){
					cout<<setw(2)<<m.maze[i][j]<<" ";
				}
				else{
                    cout<<setw(2)<<" # ";
                }
			}
			cout<<endl;
		}
	}
} 
int main(){
	Maze m;
	CreateMaze(m);
    MazePath(m);

	return 0;
} 