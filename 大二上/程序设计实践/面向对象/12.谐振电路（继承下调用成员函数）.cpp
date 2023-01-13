#include<iostream>
using namespace std;

class RESISTOR{
public:
    RESISTOR(double resistor):Resistor(resistor){
        cout<<"��������"<<Resistor<<"ŷ"<<endl;
    }
    ~RESISTOR(){
        cout<<"���ٵ���"<<Resistor<<"ŷ"<<endl;
    }
    void Show() const {
        cout<<"����: "<<Resistor<<"ŷ"<<endl;
    }
private:
    double Resistor;
};
class INDUCTOR{
public:
    INDUCTOR(double inductor):Inductor(inductor){
        cout<<"�������"<<Inductor<<"��"<<endl;
    }
    ~INDUCTOR(){
        cout<<"���ٵ��"<<Inductor<<"��"<<endl;
    }
    void Show() const {
        cout<<"���: "<<Inductor<<"��"<<endl;
    }
private:
    double Inductor;
};
class CAPACITOR{
public:
    CAPACITOR(double capacitor):Capacitor(capacitor){
        cout<<"��������"<<Capacitor<<"��"<<endl;
    }
    ~CAPACITOR(){
        cout<<"���ٵ���"<<Capacitor<<"��"<<endl;
    }
    void Show() const {
        cout<<"����: "<<Capacitor<<"��"<<endl;
    }
private:
    double Capacitor;
};
class CIRCUIT:public RESISTOR,public INDUCTOR,public CAPACITOR{
    public:                     //class CIRCUIT�̳���ǰ�����࣬���������μ̳�
    CIRCUIT(double resistor,double inductor,double capacitor):
        RESISTOR(resistor),INDUCTOR(inductor),CAPACITOR(capacitor){
        cout<<"������·"<<endl;
    }
    ~CIRCUIT(){
        cout<<"���ٵ�·"<<endl;
    }
    void Show() const {         //CIRCUIT��Show������չʾ�̳е������࣬��˲����ö�̬
        RESISTOR::Show();       //ֱ����Ϊ��Ա�������ֱ����ǰ�������Show����
        INDUCTOR::Show();
        CAPACITOR::Show();
    }
};


int main()
{
    double r, i, c;
    cin >> r >> i >> c;
    CIRCUIT a(r, i, c);
    a.Show();

    return 0;
}
