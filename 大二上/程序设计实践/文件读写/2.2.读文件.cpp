#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream ifs("test.txt");
    if(!ifs){
        cerr<<"�ļ���ʧ��"<<endl;
        return -1;
    }
    string buf;
    while(ifs>>buf){
        cout<<buf<<endl;
    }
    ifs.close();
    cout<<"�ļ���ȡ����"<<endl;

    return 0;
}