#include<iostream>
#include<set>
using namespace std;

int main(){
    int N;
    cin>>N;
    set<int> s;
    for(int i=0;i<N;i++){
        int m;
        cin>>m;
        if(s.upper_bound(m)!=s.end()){		//���ڼ����п����ҵ���m���Ԫ��
            s.erase(s.upper_bound(m)); 		//�ѱ�m����������ΪΨһ������ֻ�ò���һ�Σ�
		}
        s.insert(m);
    }
    cout<<s.size()<<endl;
    return 0;
}
