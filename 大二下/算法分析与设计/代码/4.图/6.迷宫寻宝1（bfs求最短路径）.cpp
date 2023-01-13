/*�Թ�Ѱ����
��Ŀ�����������׼��ȥѰ������һ��n*n ��n��, n�У����Թ��У�������һ����ڡ�һЩǽ���Լ�һ�����ء�
    �����Թ�������ͨ�ģ������Թ��е�һ��λ�ã�ֻ���ߵ�����ֱ�����ڵ������ĸ�λ�ã��ϡ��¡����ң���
    �ֺ��������Թ�����ڴ�������������Ҫ�߼��������õ����أ�����Զ�޷��õ����أ������-1��
���룺��һ��Ϊ������n��n��1000������ʾ�Թ���С��������n�У�ÿ�а���n���ַ��������ַ���.����ʾ��λ��Ϊ
    �յأ��ַ���#����ʾ��λ��Ϊǽ�ڣ��ַ���S����ʾ��λ��Ϊ��ڣ��ַ���E����ʾ��λ��Ϊ���أ�����������ֻ
    ���������ַ������ҡ�S���͡�E��������һ�Ρ�
������õ�����������Ҫ�ߵĲ���������Զ�޷��õ����أ������-1��
˼·������ṹ��Pos����ʾλ��(x,y)��bfs��϶���ʵ�֡�
    bfs�����ڲ���������������·�����ݲ������ɣ��ٿ�һ����ά����洢ÿ��Ԫ�ؼ���
Sample Input1��
5
S.#..
#.#.#
#.#.#
#...E
#....
Sample Output1��
7
Sample Input2��
10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...E#
Sample Output2��
22
*/
#include <iostream>
#include <queue>
using namespace std;

struct Pos{                                 //λ��
    int x,y;
};
int n;
int mp[1001][1001]={{0}};       //�Թ�(-1��ʾǽ�ڣ�0��ʾͨ·��1��ʾ��㣬2��ʾ�յ㣬3��ʾ�߹�)
int path[1001][1001];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};  //����
queue<Pos> q;                               //·��
Pos cur{0,0};                               //��ǰλ��
int cnt;                                    //���·��
bool flag=0;                                //�ж��Ƿ���ͨ·

void bfs(){
    while(!q.empty()){
        cur=q.front();
        q.pop();
        int level=path[cur.x][cur.y];       //��ǰ�ڵ�Ĳ���
        for(int i=0;i<4;i++){
            int tmpx=cur.x+dir[i][0];
            int tmpy=cur.y+dir[i][1];
            if(tmpx>=0&&tmpx<n&&tmpy>=0&&tmpy<n){   //��֤û�����߽�
                //cout<<"mp["<<tmpx<<","<<tmpy<<"]"<<"="<<mp[tmpx][tmpy]<<",cnt="<<cnt<<endl;
                if(mp[tmpx][tmpy]==0){
                    mp[tmpx][tmpy]=3;               //����߹�
                    q.push(Pos{tmpx,tmpy});
                    path[tmpx][tmpy]=level+1;
                }
                else if(mp[tmpx][tmpy]==2){
                    flag=1;
                    path[tmpx][tmpy]=level+1;
                    cnt=level+1;
                    //break              //breakֻ������forѭ����Ҫ����ȫ������������return
                    return;              //�ﵽ�յ㣨û��Ҫ���������ˣ���Ϊ�����·����Ȼ������
                }
            }
        }
    }
}

int main(){
    cin>>n;
    char c;
    for(int i=0;i<n;i++){                   //�����Թ���·��
        for(int j=0;j<n;j++){
            cin>>c;
            path[i][j]=-1;                  //·����ֵΪ-1����ʾ��������
            if(c=='#'){
                mp[i][j]=-1;
            }
            else if(c=='.'){
                mp[i][j]=0;
            }
            else if(c=='S'){
                mp[i][j]=1;
                q.push(Pos{i,j});
                path[i][j]=0;               //��㸳Ϊ��0��
            }
            else if(c=='E'){
                mp[i][j]=2;
            }
        }
        getchar();
    }
    bfs();
    if(flag){
        cout<<cnt<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<path[i][j];
    //     }
    //     cout<<endl;
    // }

    return 0;
}