/*�μ��˲�ѡ�Σ�
��Ŀ�����������ˡ�����Ʒѧ���š������²ż汸���ȶ���Ʒ����з���ѧʶ���ǵ�ǰ�棬������ʱ���μ��˲ŵ�����
    Ŀ�ꡣ��ˣ�Z��Ǿ����ı��ȥֻ������ķ����������ȿ�Ʒ���ٿ��ɼ��Ļ���ѡ�μƿ�רҵ�μ�ѧ����
    �ӡ����巽ʽ���£����ɸ���Ա��ÿ��ѧ���ľ���״̬������̬�ȡ�ƽʱ���ֵȴ�֣����÷ִӸߵ�������
    Ȼ���ٸ���ѧ����ѧϰ�ɼ�ѡ���������һ��ѧ����
    ��ô�����������ѧ��������������أ�������Nλѧ��������Ʒ�����ִӸߵ����������ǵ�ѧϰ�ɼ���
    ��Ϊs1,s2,...,sN������ѡ������ѧ��I=<si1,si2,...,siK>��J=<sj1,sj2,...,sjK>������1��i1<i2<
    ...<iK<...��N��1��j1<j2<...<jK��N�������������������I��ѧ����J��ѧ�����㣬��I>J��
        1.si1>sj1, ����
        2.����p��[2,K] ����q��[1,p?1]: siq=sjq��sip>sjp��
    �����۱�׼���Ƚ����齵�����е����е�һ����ͬ���ֵĴ�С��
    ע����Ȼ������ѡ�η���ǿ��С����Ʒ�кõ�ѧ��������ʾ�����á�
���룺�������ݡ���һ�и�������������N��K���ÿո��������ʾѧ����������Ҫ����ѡ�ε��˲�����(1<K��N��1000000)��
    �ڶ�����N����������i��[1,N]����ֵ��ʾ��iλѧ�����ܳɼ���������i��ʾ������Ʒ���������ɼ�������
    ������[0,2**31)���ڡ�
�������һ�������K�����ݣ��ÿո�ֿ�����ʾѡ����������ѧ����ĳɼ�����Ʒ�дӸߵ������С�������ֵ
    ����û�пո�
˼·�������������п��ܵ�ѧ�������һһ�Ƚϡ���ʼ˼·Ϊ���������ѹ��vector<vector<int> >������N��
    ��ʱ�ڴ��ʱ������нϴ�ѹ�������������һ��ѧ������뵱ǰ������ϱȽϲ������������
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,K;
int score[5000];
//vector<vector<int> >group;
vector<int> stu;
vector<int> best;

bool compare(vector<int> stu1,vector<int> stu2){
    for(int i=0;i<stu1.size();i++){
        if(stu1[i]>stu2[i]){
            return 1;
        }
        else if(stu1[i]<stu2[i]){
            return 0;
        }
    }
    return 0;
}
void dfs(int tmp){                  //����ö������ѧ�����
    if(stu.size()==K){
        if(compare(stu,best)){      //stu>best
            best.assign(stu.begin(),stu.end());
        }
        //group.push_back(stu);
        return;
    }
    for(int i=tmp;i<N;i++){
        stu.push_back(score[i]);
        dfs(i+1);
        stu.pop_back();
    }
    
    return;
}
void VecPrint(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>score[i];
    }
    for(int i=0;i<K;i++){           //best��ֵȫ��Ϊ0�����Գ��αȽ�
        best.push_back(0);
    }
    int tmp=0;
    dfs(tmp);
    // sort(group.begin(),group.end(),compare);
    // for(int i=0;i<group.size();i++){
    //     VecPrint(group[i]);
    // }
    VecPrint(best);

    return 0;
}