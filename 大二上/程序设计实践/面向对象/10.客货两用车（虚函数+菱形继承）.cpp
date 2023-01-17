#include <iostream>
using namespace std;

class CAR{
public:
    CAR(double speed):Speed(speed){
        cout<<"��������("<<Speed<<"����/Сʱ)"<<endl;
    };
    virtual ~CAR(){                     //���Ա����Ҫ������������
        cout<<"��������("<<this->Speed<<"����/Сʱ)"<<endl;
    }
    virtual void Show() const{          //���Ժ�������const����
        cout<<"����: "<<this->Speed<<"����/Сʱ"<<endl;
    }
protected:
    double Speed;
};

class BUS:virtual public CAR {          //��̳н�����μ̳�����
public:
    BUS(double speed,int seat):CAR(speed),Seat(seat){   //�̳��µĹ��캯��
        cout<<"�����ͳ�("<<this->Seat<<"��)"<<endl;
    };
    virtual ~BUS(){
        cout<<"���ٿͳ�("<<this->Seat<<"��)"<<endl;
    }
    virtual void Show() const{          //�麯��ʵ�ֶ�̬
        cout<<"�ͳ�: "<<this->Speed<<"����/Сʱ, "<<this->Seat<<"��"<<endl;
    }
protected:
    int Seat;
};
class TRUCK:virtual public CAR {
public:
    TRUCK(double speed,double load):CAR(speed),Load(load){
        cout<<"��������("<<this->Load<<"��)"<<endl;
    };
    virtual ~TRUCK(){
        cout<<"���ٻ���("<<this->Load<<"��)"<<endl;
    }
    virtual void Show() const{
        cout<<"����: "<<this->Speed<<"����/Сʱ, "<<this->Load<<"��"<<endl;
    }
protected:
    double Load;
};

class VAN:public BUS,public TRUCK {
//VAN�̳���BUS��TRUCK����˲���дCAR�������캯���޷�ʶ���û����CAR����BUS��TRUCK�̳е�CAR
public:
    VAN(double speed,int seat,double load):CAR(speed),BUS(speed,seat),TRUCK(speed,load){
        cout<<"�����ͻ����ó�"<<endl;        //���캯������ҪдCAR
    }
    virtual ~VAN(){
        cout<<"���ٿͻ����ó�"<<endl;
    }
    virtual void Show() const{
        cout<<"�ͻ����ó�: "<<this->TRUCK::Speed<<"����/Сʱ, ";
        cout<<this->Seat<<"��, "<<this->Load<<"��"<<endl;
    }
};

void Test(const CAR &x)             //����Ϊ�������ĺ���Ҳ���Դ������������
{
    x.Show();
}

int main(){
    CAR a(108.5);
    Test(a);
    BUS b(58.5, 45);
    Test(b);
    TRUCK c(208.5, 350.8);
    Test(c);
    VAN d(125.6, 5, 2.5);
    Test(d);
    CAR *p;
    double s,t,w;
    cin>>s>>t>>w;
    p = new VAN(s, t, w);
    p->Show();
    delete p;
    
    return 0;
}