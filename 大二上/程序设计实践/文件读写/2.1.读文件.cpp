#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream ifs;
    ifs.open("test.txt",ios::in);
    if(!ifs.is_open()){
        cerr<<"�ļ���ʧ��"<<endl;
        return -1;
    }
    string buf;
    while(getline(ifs,buf)){
        cout<<buf<<endl;
    }
    ifs.close();
    cout<<"�ļ���ȡ����"<<endl;
    
    return 0;
}