/*�Թ�Ѱ��2��
��Ŀ�����ַ������ʾ�Թ��������ַ�'#'��ʾ���ɴ��ǽ�ڣ�'@'��ʾ�ɴ��λ�ã���λ�����������ҵĿɴ�λ
    ���໥��ͨ������б�����λ�ò���ͨ���ӿɴ�λ���ߵ�������ͨ��λ����Ҫ����һ���ӡ�'S����'G'�ֱ��
    ʾ�Թ������λ�ú��յ�λ�ã��ɴ��СдӢ����ĸ��ʾ��λ�ÿɴ��ҷ����б����䡣ÿ����������Ψһ
    �ı�ţ���1��������'a'��ʾ����2����'b'������������š�ð���ߵ������Ǵ���������Ѱ�������䣬��
    ��ȫ�����Ӳ�ȡ�߱�������ߵ��յ�'G'����k������ֻ����ǰ���k-1������ȫ���򿪺���ܴ򿪣�����
    ��λ��ֻ�ܾ����������Ӳ���Ҫʱ�䣬�����۴򲻴����ӣ�ÿ���ߵ������ӵ�λ��ʱ���������������
    һ����ʱ�䣬Ȼ����ܾ�����λ�á���ð�������������������ʱ�䡣
���룺��һ�и�����������N��K(2<N��100, 1��K��20)��������N�У�ÿ���г���ΪN���ַ������Ի��з���β��
    ��ʾN��N���Թ���K��ʾ�Թ��з��õı�������������Ӣ���ַ�'a','b',...,'a'+K-1��ʾ��
�����ð���ߴ����λ�ó���������ȡ�����б�����յ����յ������ʱ�䡣
˼·������̰���㷨����·������ΪS->a,a->b,b->c,...,x->G���ٷֶν���bfs���ɡ�
ע�⣺��ʱ����ʹ�ö��д洢�Ļ�������������ʱ����ɴ����������£�
@ @ @ @ @ @
a c d e @ b
bfsʱa->c->d->e->@->b���a->@->@->@->@->@->@->b�Ƚ�����У�bfs��������������ǰ�ߺ�ʱ����
    ��˲���!!!���ȶ���!!!��������е�˳���԰�����˳�򣬵������Զ������ܽ���ͬ�ڵ㰴����㵽��
�õ��ʱ�䳤����������bfs����˳������Ӱ��
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pos{
    int x,y;
};
int N,K;
int mp[101][101]={{0}};     //-2��ʾ��ͨ��-1��ʾͨ·��0��ʾ��㣬1~K��ʾ���K+1��ʾ�յ�
int path[101][101]={{0}};   //��¼·��
Pos node[21];               //�洢����λ��
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

struct cmp{                                 //�������ȶ��еıȽϷ�ʽ
    bool operator()(Pos a, Pos b) {
        return path[a.x][a.y]>path[b.x][b.y];
    }
};
priority_queue<Pos,vector<Pos>,cmp> q;      //���ȶ��д洢�ڵ�
Pos cur{-1,-1};
int time=0;                                 //��ʱ��

void bfs(Pos p){
    while(!q.empty()){
        cur=q.top();
        q.pop();
        int level=path[cur.x][cur.y];       //��ǰ�ڵ�Ĳ���
        if(cur.x==p.x && cur.y==p.y){       //���Ӳ��㵽��
            time+=path[cur.x][cur.y];
            return;
        }
        for(int i=0;i<4;i++){
            int tmpx=cur.x+dir[i][0];
            int tmpy=cur.y+dir[i][1];
            if(tmpx>=0&&tmpx<N && tmpy>=0&&tmpy<N && mp[tmpx][tmpy]!=-2){//��֤�߽��ڵ�ͨ· 
                //if(cur.x==p.x && cur.y==p.y)  //�������������������ֻ�����
                //��path����߹�������mp��������һ��bfs�޷��ָ�mp
                if(mp[tmpx][tmpy]==-1 && path[tmpx][tmpy]==-1){
                    path[tmpx][tmpy]=level+1;
                    q.push(Pos{tmpx,tmpy});
                }
                else if(mp[tmpx][tmpy]>=1 && mp[tmpx][tmpy]<=K && path[tmpx][tmpy]==-1){
                    path[tmpx][tmpy]=level+2;
                    q.push(Pos{tmpx,tmpy});
                }
                else if(mp[tmpx][tmpy]==K+1 && path[tmpx][tmpy]==-1){   //������G
                    path[tmpx][tmpy]=level+1;
                    q.push(Pos{tmpx,tmpy});
                }
            }
        }
    }
}

int main(){
    cin>>N>>K;
    char c;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>c;
            if(c=='#'){
                mp[i][j]=-2;
            }
            else if(c=='@'){
                mp[i][j]=-1;
            }
            else if(c=='S'){
                mp[i][j]=0;
                node[0]=Pos{i,j};
            }
            else if(c=='G'){
                mp[i][j]=K+1;
                node[K+1]=Pos{i,j};
            }
            else{           //������Ǳ�����
                mp[i][j]=c-'a'+1;
                node[c-'a'+1]=Pos{i,j};
            }
        }
        getchar();
    }
    for(int i=0;i<=K;i++){          //�ֶ�bfs
        q.push(node[i]);            //������
        for(int i=0;i<N;i++){       //bfsǰ��Ҫˢ��·��
            for(int j=0;j<N;j++){
                path[i][j]=-1;
            }
        }
        path[node[i].x][node[i].y]=0;
        bfs(node[i+1]);
        while(!q.empty()){          //��ն���
            q.pop();
        }
    }
    cout<<time<<endl;
    // for(int i=0;i<=K+1;i++){
    //     cout<<node[i].x<<" "<<node[i].y<<endl;
    // }
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout<<mp[i][j];
    //     }
    //     cout<<endl;
    // }
    
    return 0;
}