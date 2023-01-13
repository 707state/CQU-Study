/*ͼ��m��ɫ���⣺
��Ŀ������������ͨͼ��m�ֲ�ͬ����ɫ������Щ��ɫΪ��ͼ��������ɫ�����ڶ�����ɫ��ͬ��m������С
    ���룺��һ���Ƕ������n(2<=n<=10),��ɫ��m(1<=m<=n),������Ϊ�����ϵ(a,bΪ0ʱ�������)
    �����������ɫ�����ͷ�������
˼·���ö�ά����洢��Ĺ�ϵ��һά����洢�����ɫ���(1,2,3...)�������±��Ӧ�������
    ���û��������𰸣��ù���ʵ��Ϊö���������������������ͼ�۵���ɫ����
    ���޽������0������ɫ��С��mҲ���
*/
#include <iostream>
#include <vector>
using namespace std;

int graph[20][20]={0};
int color[20]={0};
int n,m;                        //����ȫ�ּ��ٺ����в�������
int cnt=0;

bool judge(int p){              //�ж���p����ͨ�ĵ����ɫ���
    for(int i=1;i<=n;i++){      //��1��������0����Ĭ��ֵ
        if(graph[i][p]&&color[i]==color[p]){
            return 0;
        }
    }
    return 1;
}

void dfs(int NO){               //NO��ʾ��ɫ��ı��
    if(NO>n){                   //����������ֱ�Ӵ�ӡ
        for(int i=1;i<=n;i++){
            cout<<color[i]<<" ";
        }
        cout<<endl;
        cnt++;
    }
    else{
        for(int i=1;i<=m;i++){
            color[NO]=i;
            if(judge(NO)){
                dfs(NO+1);
            }
            color[NO]=0;
        }
    }

}

int main(){
    cin>>n>>m;
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF&&a!=0&&b!=0){
        graph[a][b]=1;
        graph[b][a]=1;          //������ͨͼ
    }
    dfs(1);
    cout<<cnt;

    return 0;
}