#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream ofs;
    ofs.open("test1.txt",ios::out);
    ofs<<"д�ļ�"<<endl;
	ofs<<"����"<<endl;
    ofs.close();
    cout<<"д�ļ�����"<<endl;
    
    return 0;
}