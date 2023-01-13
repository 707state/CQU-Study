/*���ַ������������в���ָ��Ԫ�� O(logn)
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
            //high=middle       //���ڽ���ǰ������ѭ��
            high=middle-1;
        }
        else{
            //low=middle
            low=middle+1;
        }
    }
    return -1;
}

int main(){
    int a[100];
    for(int i=0;i<100;i++){
        a[i]=rand()%150;
    }
    sort(a,a+100);
    int res=find(a,100,2);
    for(int i=0;i<100;i++){
        cout<<a[i]<<" ";
        if(i!=0 && i%20==0){
            cout<<endl;
        } 
    }
    cout<<endl;
    if(res>=0){
        cout<<"target index:"<<res<<endl;
    }
    else{
        cout<<"not found!"<<endl;
    }
    
    return 0;
}
