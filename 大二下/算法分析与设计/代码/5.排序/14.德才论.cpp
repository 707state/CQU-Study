/*�²��ۣ�
��Ŀ���δ�ʷѧ��˾����ڡ�����ͨ��������һ�������ġ��²��ۡ������ǹʲŵ�ȫ��ν֮ʥ�ˣ��ŵ¼���ν֮
    ���ˣ���ʤ��ν֮���ӣ���ʤ��ν֮С�ˡ���ȡ��֮����������ʥ�ˣ����Ӷ���֮�������С�ˣ�����
    �����ˡ��� �ָ���һ�������ĵ²ŷ����������˾�������۸���¼ȡ������
���룺��һ�и��� 3 �����������ֱ�Ϊ����������N����100000����¼ȡ��ͷ�����L����60�������·ֺͲ�
    �־�������L�Ŀ��������ʸ񱻿���¼ȡ������¼ȡ��H��<100�������·ֺͲŷ־������ڴ��ߵı�����
    Ϊ���ŵ�ȫ���������࿼�����²��ִܷӸߵ������򣻲ŷֲ������·ֵ��ߵ�һ�࿼�����ڡ���ʤ�š���Ҳ
    ���ܷ����򣬵����ڵ�һ�࿼��֮�󣻵²ŷ־����� H�����ǵ·ֲ����ڲŷֵĿ������ڡ��ŵ¼�������
    ���С���ʤ�š��ߣ����ܷ����򣬵����ڵڶ��࿼��֮�������ﵽ�����L�Ŀ���Ҳ���ܷ����򣬵���
    �ڵ����࿼��֮��
    ���N�У�ÿ�и���һλ��������Ϣ��������׼��֤�š��·֡��ŷ֣�����׼��֤��Ϊ8λ�������²ŷ�
    Ϊ���� [0, 100] �ڵ����������ּ��Կո�ָ���
�������һ�����ȸ����ﵽ��ͷ����ߵĿ�������M�����M�У�ÿ�а��������ʽ���һλ��������Ϣ����
    ����������˵���Ĺ���Ӹߵ������򡣵�ĳ�࿼�����ж����ܷ���ͬʱ������·ֽ������У����·�Ҳ
    ���У���׼��֤�ŵ����������
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L,H;

class student{
private:
    string NO;
    int morality;
    int talent;
public:
    student(string no,int m,int t){
        NO=no;
        morality=m;
        talent=t;
    }
    int rank(){
        if(morality<L || talent<L){
            return 0;
        }
        else if(morality>=H && talent>=H){
            return 1;
        }
        else if(morality>=H && talent<H){
            return 2;
        }
        //else if(morality<H && talent<H && morality>talent){   //©�Ⱥŵ���3�����Ե����
        else if(morality<H && talent<H && morality>=talent){
            return 3;
        }
        else{
            return 4;
        }
    }
    int scores(){
        return morality+talent;
    }
    int getmorality(){
        return morality;
    }
    string getNO(){
        return NO;
    }
    void print(){
        cout<<NO<<" "<<morality<<" "<<talent<<endl;
    }
};
bool cmp(student s1,student s2){
    if(s1.scores()!=s2.scores()){
        return s1.scores()>s2.scores();
    }
    else if(s1.getmorality()!=s2.getmorality()){
        return s1.getmorality()>s2.getmorality();
    }
    else{
        return s1.getNO()<s2.getNO();
    }
}

int main(){
    int N;
    cin>>N>>L>>H;
    int M=N;
    vector<student> v1;
    vector<student> v2;
    vector<student> v3;
    vector<student> v4;
    for(int i=0;i<N;i++){
        string no;
        int mor;
        int tal;
        cin>>no>>mor>>tal;
        student s(no,mor,tal);
        if(s.rank()==0){
            M--;
        }
        else if(s.rank()==1){
            v1.push_back(s);
        }
        else if(s.rank()==2){
            v2.push_back(s);
        }
        else if(s.rank()==3){
            v3.push_back(s);
        }
        else if(s.rank()==4){
            v4.push_back(s);
        }
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);
    sort(v3.begin(),v3.end(),cmp);
    sort(v4.begin(),v4.end(),cmp);

    cout<<M<<endl;
    for(int i=0;i<v1.size();i++){
        v1[i].print();
    }
    for(int i=0;i<v2.size();i++){
        v2[i].print();
    }
    for(int i=0;i<v3.size();i++){
        v3[i].print();
    }
    for(int i=0;i<v4.size();i++){
        v4[i].print();
    }

    return 0;

} 