/*�Թ�Ѱ��1��Ҫ�����·������Ȼbfs�������ơ���ֻ�ж�ͨ·����bfs/dfs���ɡ�bfsͬ6.1������dfs�ж�
�Ƿ���ͨ·
˼·��dfs+ջ
Sample Input1��
5
S.#..
#.#.#
#.#.#
#...E
#....
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
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Pos{                                 //λ��
    int x,y;
};
int n;
int mp[1001][1001]={{0}};       //�Թ�(-1��ʾǽ�ڣ�0��ʾͨ·��1��ʾ��㣬2��ʾ�յ㣬3��ʾ�߹�)
int path[1001][1001];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};  //����
stack<Pos> st;                              //·��
bool flag=0;                                //�ж��Ƿ���ͨ·

void printPath(stack<Pos> s){
    vector<Pos> v;
    while(!s.empty()){
        Pos tmp=s.top();
        s.pop();
        v.push_back(tmp);
    }
    for(int i=v.size()-1;i>=0;i--){
        cout<<"("<<v[i].x<<","<<v[i].y<<")";
    }
}

void dfs(Pos p){
    Pos cur=p;
    for(int i=0;i<4;i++){
        int tmpx=cur.x+dir[i][0];
        int tmpy=cur.y+dir[i][1];
        Pos tmpp{tmpx,tmpy};
        if(tmpx>=0&&tmpx<n && tmpy>=0&&tmpy<n && mp[tmpx][tmpy]!=-1){
            if(mp[tmpx][tmpy]==3){
                continue;           //���ҹ��ˣ�������һ�β���
            }
            else if(mp[tmpx][tmpy]==2){
                st.push(tmpp);
                flag=1;
                return;
            }
            mp[tmpx][tmpy]=3;
            st.push(tmpp);
            dfs(tmpp);
            if(flag){               //���������ݹ�
                return;
            }
            st.pop();
        }
        
    }

}

int main(){
    cin>>n;
    char c;
    Pos start;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>c;
            path[i][j]=-1;
            if(c=='#'){
                mp[i][j]=-1;
            }
            else if(c=='.'){
                mp[i][j]=0;
            }
            else if(c=='S'){
                mp[i][j]=1;
                start=Pos{i,j};
                st.push(start);
                path[i][j]=0;
            }
            else if(c=='E'){
                mp[i][j]=2;
            }
        }
        getchar();
    }
    dfs(start);
    if(flag){
        cout<<"Accessible!\nOne of the path:\n";
        printPath(st);
    }
    else{
        cout<<"No solution!"<<endl;
    }

    return 0;
}