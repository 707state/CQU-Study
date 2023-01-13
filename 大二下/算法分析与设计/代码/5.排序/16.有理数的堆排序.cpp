/*�������Ķ�����:
��Ŀ���Զ����������ಢ����С�ѽ�������
���룺��һ�а���һ������T(1<=T<=100000)����������T�У�ÿһ������������n, d (|n|<103, 0<d<1000)��
    �ÿո��������ʾ������������ķ��Ӻͷ�ĸ��
�������һ���������������С�����У��ڶ��������С�������������С�
    ���������ÿ�������������Լ����n/d����ʽ���������d>0��gcd(n,d)=0�����d=1��n=0��ֱ�����n
����������  
5        //����������
3 2      //��1��������  3/2
1 3      //��2��������  1/3
4 2      //��3��������  4/2
12 10    //��4��������  12/10
4 6      //��5��������  4/6
���������
1/3  2/3  2  6/5  3/2    //��һ�� ��С��
1/3  2/3  6/5  3/2  2    //�ڶ��� ������
*/
#include <iostream>
#include <algorithm>
using namespace std; 

class Rational{
friend bool operator<(const Rational& r1, const Rational& r2);
friend bool operator<=(const Rational& r1, const Rational& r2);
friend bool operator>(const Rational& r1, const Rational& r2);
friend bool operator>=(const Rational& r1, const Rational& r2);
friend bool operator==(const Rational& r1, const Rational& r2);
friend bool operator!=(const Rational& r1, const Rational& r2);
friend ostream&operator<<(ostream&os,const Rational&r);
public:
    int N; //����
    int D; //��ĸ����0
   
    Rational() {                    //default constructor
        N=0;
        D=1;
    }
    Rational(int n){                //constructor for integer value
        N=n;
        D=1;
    }
    Rational(int n, int d) {        //normal constructor
        int gcd=abs(__gcd(n,d));    //Լ��
        N=n/gcd;
        D=d/gcd;
    }
    Rational(const Rational& r){    //copy constructor
        N=r.N;
        D=r.D;
    }
    Rational& operator=(const Rational& r){// assignment override
        N=r.N;
        D=r.D;
        //return this;
        return *this;
    }
};
bool operator<(const Rational& r1, const Rational& r2){
    return r1.N*r2.D<r1.D*r2.N;
}
bool operator<=(const Rational& r1, const Rational& r2){
    return r1.N*r2.D<=r1.D*r2.N;
}
bool operator>(const Rational& r1, const Rational& r2){
    return r1.N*r2.D>r1.D*r2.N;
}
bool operator>=(const Rational& r1, const Rational& r2){
    return r1.N*r2.D>=r1.D*r2.N;
}
bool operator==(const Rational& r1, const Rational& r2){
    return r1.N*r2.D==r1.D*r2.N;
}
bool operator!=(const Rational& r1, const Rational& r2){
    return r1.N*r2.D!=r1.D*r2.N;
}
ostream&operator<<(ostream&os,const Rational&r){
    if(r.D==1)
        os<<r.N;
    else
        os<<r.N<<"/"<<r.D;
    return os;
}

class heap{
private:
    Rational* Heap;
    int maxsize;
    int n;
    void siftdown(int pos){
        while(!isLeaf(pos)){
            int j=leftchild(pos);       //����j��ʾ����lc��rc�н�Сֵ���±�
            int rc=rightchild(pos);
            if((rc<n)&&(Heap[rc]<Heap[j])){
                j=rc;
            }
            if(Heap[pos]<Heap[j]){
                return;
            }
            Rational tmp=Heap[pos];
            Heap[pos]=Heap[j];
            Heap[j]=tmp;
            pos=j;
        }
    }
public:
    heap(Rational* h,int num,int max){
        Heap=h;
        n=num;
        maxsize=max;
        buildHeap();
    }
    int size(){
        return n;
    }
    bool isLeaf(int pos){
        return (pos>=n/2)&&(pos<n);
    }
    int leftchild(int pos){
        return 2*pos+1;
    }
    int rightchild(int pos){
        return 2*pos+2;
    }
    int parent(int pos){
        return (pos-1)/2;
    }
    void buildHeap(){
        for(int i=n/2-1;i>=0;i--){
            siftdown(i);
        }
    }
    void insert(const Rational& r){
        int curr=n++;
        Heap[curr]=r;
        while((curr!=0)&&(Heap[curr]<Heap[parent(curr)])){
            Rational tmp=Heap[curr];
            Heap[curr]=Heap[parent(curr)];
            Heap[parent(curr)]=tmp;
            curr=parent(curr);
        }
        // for(int i=0;i<n;i++){
        //     cout<<Heap[i]<<" ";
        // }
        // cout<<endl;
    }
    Rational removefirst(){
        n--;
        Rational tmp=Heap[0];
        Heap[0]=Heap[n];
        Heap[n]=tmp;
        if(n!=0){
            siftdown(0);
        }
        return Heap[n];
    }
    Rational remove(int pos){
        if(pos==(n-1)){
            n--;
        }
        else{
            n--;
            Rational tmp=Heap[pos];
            Heap[pos]=Heap[n];
            Heap[n]=tmp;
            while((pos!=0)&&(Heap[pos]<Heap[parent(pos)])){
                Rational tmp=Heap[pos];
                Heap[pos]=Heap[parent(pos)];
                Heap[parent(pos)]=tmp;
                pos=parent(pos);
            }
            if(n!=0){
                siftdown(pos);
            }
        }
        return Heap[n];
    }
};
void heapsort(Rational A[],int n){
    Rational minval;
    heap H(A,n,n);
    for(int i=0;i<n;i++){
        minval=H.removefirst();
    }
}

int main(){
    int n;
    cin>>n;
    Rational rt[100001];
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        Rational r(a,b);
        rt[i]=r;
    }                       //����������ٽ���
    heap hp(rt,n,100001);
    for(int i=0;i<n;i++){
        cout<<rt[i]<<" ";
    }
    cout<<endl;
    heapsort(rt,n);
    for(int i=n-1;i>=0;i--){
        cout<<rt[i]<<" ";
    }
    
    return 0;
}
