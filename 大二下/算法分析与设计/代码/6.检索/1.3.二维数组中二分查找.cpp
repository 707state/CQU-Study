/*�ھ����ж��ֲ��ң�
    ��Ŀ��ÿ�С��ж������źõ���������A����СΪn*n����A�в���ָ��Ԫ��
    ˼·�������Ͻǿ�ʼ������(i,j)=(0,n-1)
        1��target=A[i][j] �ҵ�
        2��target>A[i][j] i++
        3��target<A[i][j] j--
    ÿ�������൱��ɾ��һ��/��
*/
#include <iostream>
#include <utility>
using namespace std; 

pair<int,int> find(int A[][4],int n,int target){
    int i=0,j=n-1;
    pair<int,int> p(-1,-1);
    while(i<n && j>=0){
        if(target==A[i][j]){
            p.first=i,
            p.second=j;
            return p;
        }
        else if(target<A[i][j]){
            j--;
        }
        else{
            i++;
        }
    }
    return p;
}

int main(){
    int A[4][4]={{0,1,2,5},{2,3,4,7},{4,4,4,8},{5,7,7,9}};
    pair<int,int> p;
    pair<int,int> p0(-1,-1);
    p=find(A,4,7);
    if(p!=p0){
        cout<<p.first<<" "<<p.second<<endl;
        return 0;
    }
    cout<<"not found!"<<endl;
    
    return 0;
}