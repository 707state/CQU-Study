#include <iostream>
using namespace std;

class TIME{
public:
    TIME(int hour=0,int minute=0,int second=0):     //����Ĭ��ֵ
        Hour(hour),Minute(minute),Second(second){};
    bool operator>(const TIME&b){                   //�������ж�ʱ���С
        int s1=this->Hour*60*60+this->Minute*60+this->Second;
        int s2=b.Hour*60*60+b.Minute*60+b.Second;
        if(s1>s2)
            return true;
        else
            return false;
    }
    friend bool operator>(int h,const TIME&b);      //��Ԫ����
    friend ostream&operator<<(ostream&os,const TIME&t);
    friend istream&operator>>(istream&is,TIME&t);
private:
    int Hour;
    int Minute;
    int Second;
};
bool operator>(int h,const TIME&t)
{
    return TIME(h)>t;
}
ostream&operator<<(ostream&os,const TIME&t)         //�������������ֻ�������ⶨ��
{
    if(t.Hour<10)           //����
        os<<"0"<<t.Hour<<":";
    else
        os<<t.Hour<<":";
    if(t.Minute<10)
        os<<"0"<<t.Minute<<":";
    else
        os<<t.Minute<<":";
    if(t.Second<10)
        os<<"0"<<t.Second;
    else
        os<<t.Second;
    return os;
}
istream&operator>>(istream&is, TIME&t)
{
    is>>t.Hour;
    is.ignore(1,':');       //�������롰8:3:5���е�ð��
    is>>t.Minute;
    is.ignore(1,':');
    is>>t.Second;
    return is;
}


int main(){
/*  TIME a;
    cout << a << endl;
    TIME b(8);
    cout<<a<<endl;
    TIME c(8,30);
    cout<<c<<endl;
    TIME d(8, 30, 45);
    cout<<d<<endl;
    TIME e(9, 15);
    cout<<e<<endl;
    TIME f(8,50), g(9,15,47);
    cout<<f<<' '<<g<< endl;
    TIME h;
    cin>>h;
    cout<<h<<endl;
    TIME i,j;
    cin>>i>>j;
    cout<<i<<' '<<j<<endl;
    TIME k(9,0,1),l(8,59,58);
    if (k>l){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
���Դ���*/

    TIME a,b;
    cin>>a>>b;
    if(a>b){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    
    return 0;
}