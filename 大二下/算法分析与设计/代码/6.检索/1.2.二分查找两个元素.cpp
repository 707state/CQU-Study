/*���ֲ��ң�
    ��Ŀ���ź������������A������Ϊn����������X����A���Ƿ������������ΪX
    ˼·�����ֲ���X-A[i] O(nlogn)
*/
#include <iostream>
#include <algorithm>
using namespace std; 

int find(int A[],int n,int target){
    int low=0,high=n-1;
    int middle=(low+high)/2;
    while(low<=high){
        middle=(low+high)/2;
        if(target==A[middle]){
            return middle;
        }
        else if(target<A[middle]){
            high=middle-1;
        }
        else{
            low=middle+1;
        }
    }
    return -1;
}

int main(){
    int X;
    cin>>X;
    int a[100];
    for(int i=0;i<100;i++){
        a[i]=rand()%150;
    }
    sort(a,a+100);
    for(int i=0;i<100;i++){
        int res=find(a,100,X-a[i]);
        if(res>=0){
            cout<<i<<" "<<res<<endl;
            return 0;
        }
    }
    cout<<"not found!"<<endl;
    
    return 0;
}
