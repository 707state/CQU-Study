#include <iostream>
using namespace std;

class Vehicle{};
class Bicycle:public Vehicle{};
class Motorcar:public Vehicle{};
    
void run(Vehicle &veh){
    cout<<"Vehicle run"<<endl;
}
void run(Bicycle &bic){
    cout<<"Bicycle run"<<endl;
}
void run(Motorcar &mot){
    cout<<"Motorcar run"<<endl;
}

int main(){
    Vehicle veh;
    Bicycle bic;
    Motorcar mot;
    run(veh);       //��Ŀ�����ӿ���ʽֱ��д�ɺ�������������ʱ��Ҫ������
    run(bic);
    run(mot);

    return 0;
}