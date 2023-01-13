#include <iostream>
using namespace std;

template <class T>
class MyArray{
private:
    T *data;
    int size;
public:
    MyArray(int size){                  //���캯��
        this->size = size;
        data = new T[size];

        for(int i=0;i<size;i++)
            cin>>*(data+i);             //�ඨ��Ҫ���ʼ��ʱ����Ԫ��
    };
    void sort(){
        T temp;
        for(int i=0;i<size-1;i++)       //ð��
            for(int j=0;j<size-1;j++){
                if(*(data+j)>*(data+j+1)){
                    temp=*(data+j);
                    *(data+j)=*(data+j+1);
                    *(data+j+1)=temp;
                }
            }
    };
    void display()                      //�������
    {
        for(int i(0); i < size - 1; i++)
            cout << *(data + i) << " ";

        cout << *(data + size - 1) << endl;
    };
    ~MyArray();
    bool check();
};
template<class T>
MyArray<T>::~MyArray(){ delete[] data;}

template<class T>
bool MyArray<T>::check(){
    int i;
    for(i=0;i<size-1;i++){
        if(data[i]>data[i+1]){
            cout<<"ERROR!"<<endl;
            return false;
        }
    }
    return true;
}
int main( )
{
/*ÿ������ĵ�һ������Ϊ0��1��2��3:
Ϊ0ʱ��ʾ���������Ϊ1ʱ��ʾ����������;Ϊ2ʱ��ʾ��������һλС���ĸ�����;Ϊ3ʱ��ʾ�����ַ���
�����һ�����ַ�0���������������һ������������ʾ������������ݵ�������
��ÿ�е��������뿪ʼ����������ָ�����͵����ݡ�
*/
    MyArray<int> *pI;
    MyArray<float> *pF;
    MyArray<char> *pC;
    int ty, size;
    cin>>ty;
    while(ty>0){
        cin>>size;
        switch(ty){
            case 1: pI = new MyArray<int>(size);   pI->sort(); pI->check(); pI->display(); delete pI; break;
            case 2: pF = new MyArray<float>(size); pF->sort(); pF->check(); pF->display(); delete pF; break;
            case 3: pC = new MyArray<char>(size);  pC->sort(); pC->check(); pC->display(); delete pC; break;
        }
        cin>>ty;
    }
    return 0;
}
