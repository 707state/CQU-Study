#include <iostream>
#include <algorithm>
using namespace std;

//����Ϊȫ�ֱ������ں�����ʹ�ã����⺯���в�������
//ȫ��������ݣ�����һ�δε���vector���ȽϿ�
int tot=0;
int N;
int col[20]={0};    //col[]��ʾ�е�ֵ

void dfs(int r)     //���еݹ�
{
    if (r==N)
        tot++;      //�ﵽ�ݹ�߽磬��������һ
    else
        for (int i=0;i<N;i++)           //�����ж�
        {
            int flag=1;
            col[r]=i;                   //���԰ѵ�r�лʺ���ڵ�i��
            for (int j=0;j<r;j++)       //����Ƿ��ǰ��Ļʺ��ͻ
                if (col[r]==col[j] || r-col[r]==j-col[j] || r+col[r]==j+col[j]){
                    flag=0;
                    break;
                }
            if (flag)
                dfs(r+1);
        }
}

int main(){
    cin>>N;
    dfs(0);
    cout<<tot<<endl;

    return 0;
}