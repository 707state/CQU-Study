/*�������ݣ�
    ��Ŀ������a,n����a��n�η�
    ˼·�����ֵݹ飬a**n=a**(n%2) * a**(n/2) * a**(n/2)
*/
#include <iostream>
#include <algorithm>
using namespace std; 

int power(int a,int n){
    if(n==1)    return a;
    int remainder=(n%2==1)?a:1;
    return remainder*power(a,n/2)*power(a,n/2);
}

int main(){
    int a,n;
    cin>>a>>n;
    cout<<power(a,n);
    
    return 0;
}
