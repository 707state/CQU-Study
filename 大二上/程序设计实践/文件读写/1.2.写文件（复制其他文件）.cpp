#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream ifs("test1.txt");      //��Ҫ"test1.txt"�ļ����ڲ��ܶ�ȡ
    ofstream ofs("test2.txt");
    if(!ofs){
        cerr<<"����ļ��޷���"<<endl;
        return -1;
    }
    string word;
    while(ifs>>word){               //��"test1.txt"�ļ����ַ�����ȡ��word
        ofs<<word<<" ";             //����ȡ������д��"test2.txt"
    }
    ofs.close();
    ifs.close();
    cout<<"д�ļ�����"<<endl;
    
    return 0;
}