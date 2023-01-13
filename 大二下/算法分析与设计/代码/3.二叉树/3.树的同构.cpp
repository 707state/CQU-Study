/*����ͬ��
��Ŀ������������T1��T2�����T1����ͨ�����ɴ����Һ��ӻ����ͱ��T2�������ǳ��������ǡ�ͬ�����ġ�
�ָ����������������ж������Ƿ���ͬ���ġ�
���룺����2�ö�����������Ϣ������ÿ������������һ���и���һ���Ǹ�����N(��10)���������Ľ��������ʱ
    �������0��N?1��ţ������N�У���i�ж�Ӧ��ŵ�i����㣬�����ý���д洢��1��Ӣ�Ĵ�д��ĸ��
    �����ӽ��ı�š��Һ��ӽ��ı�š�������ӽ��Ϊ�գ�������Ӧλ���ϸ�����-�������������ݼ���
    һ���ո�ָ���ע�⣺��Ŀ��֤ÿ������д洢����ĸ�ǲ�ͬ�ġ�
����������������ͬ���ģ������Yes�������������No����
��������1��
8
A 1 2
B 3 4
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
8
G - 4
B 7 6
F - -
A 5 1
H - -
C 0 -
D - -
E 2 -
�������1:
Yes
��������2��
8
B 5 7
F - -
A 0 3
C 6 -
H - -
D - -
G 4 -
E 1 -
8
D 6 -
B 5 -
E - -
H - -
C 0 2
G - 3
F - -
A 1 4
�������2:
No
˼·�����⿴��Ϊ���νṹ����int�洢�ӽڵ�Ľṹ�������Դ洢�����������β�����ֱ�ӿ������ڵ㣬���
    ��ҪFindRoot
*/
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    char value;
    int left;
    int right;
};
int FindRoot(vector<Node> &tree){
    bool flag[tree.size()]={0};
    for(int i=0;i<tree.size();i++){
        if(tree[i].left!=-1){
            flag[tree[i].left]=1;
        }
        if(tree[i].right!=-1){
            flag[tree[i].right]=1;
        }
    }
    for(int i=0;i<tree.size();i++){
        if(flag[i]==0)  return i;
    }
    return -1;
}
bool compare(vector<Node> &tree1,vector<Node> &tree2,int root1,int root2){
    //cout<<tree1[root1].value<<" "<<tree2[root2].value<<endl;
    if(tree1[root1].value!=tree2[root2].value){
        //cout<<tree1[root1].value<<"!="<<tree2[root2].value<<endl;
        return false;
    }
    int left1=tree1[root1].left;
    int right1=tree1[root1].right;
    int left2=tree2[root2].left;
    int right2=tree2[root2].right;
    //cout<<tree1[left1].value<<tree1[right1].value<<tree2[left2].value<<tree2[right2].value<<endl;
    //��ͬ�ǿ��ӽڵ������Ӧ��ͬ�ݹ麯��
    //4����Ϊ��
    //if(left1==left2==right1==right2==-1){if(left1==left2==right1==right2==-1){     //�������ȣ�����left1==left2����0/1�ͺ���Ƚϻ���0
    if(left1==-1&&left2==-1&&right1==-1&&right2==-1){
        //cout<<1<<endl;
        return true;
    }
    //2��Ϊ��
    //else if(tree1[left1].value==-1 && tree2[left2].value==-1 && tree1[right1].value==tree2[right2].value){
    //�յ��ӽڵ㲻����value�ж�
    else if(left1==-1 && left2==-1 && tree1[right1].value==tree2[right2].value){
        //cout<<2<<endl;
        return compare(tree1,tree2,right1,right2);
    }
    else if(tree1[left1].value==tree2[left2].value && right1==-1 && right2==-1){
        //cout<<3<<endl;
        return compare(tree1,tree2,left1,left2);
    }
    else if(left1==-1 && right2==-1 && tree1[right1].value==tree2[left2].value){
        //cout<<4<<endl;
        return compare(tree1,tree2,right1,left2);
    }
    else if(tree1[left1].value==tree2[right2].value && right1==-1 && left2==-1){
        //cout<<5<<endl;
        return compare(tree1,tree2,left1,right2);
    }
    //����Ϊ��
    if(tree1[left1].value==tree2[left2].value && tree1[right1].value==tree2[right2].value){
        //cout<<6<<endl;
        return compare(tree1,tree2,left1,left2)&&compare(tree1,tree2,right1,right2);
    }
    else if(tree1[left1].value==tree2[right2].value && tree1[right1].value==tree2[left2].value){
        //cout<<7<<endl;
        return compare(tree1,tree2,left1,right2)&&compare(tree1,tree2,right1,left2);
    }
    //cout<<8<<endl;
    return false;
}

int main(){
    int N1,N2;
    cin>>N1;
    vector<Node> tree1(N1);
    for(int i=0;i<N1;i++){
        char c,l,r;
        cin>>c>>l>>r;
        getchar();
        tree1[i].value=c;
        if(l=='-'){
            tree1[i].left=-1;
        }
        else{
            tree1[i].left=l-'0';
        }
        if(r=='-'){
            tree1[i].right=-1;
        }
        else{
            tree1[i].right=r-'0';
        }
    }
    cin>>N2;
    vector<Node> tree2(N2);
    for(int i=0;i<N2;i++){
        char c,l,r;
        cin>>c>>l>>r;
        getchar();
        tree2[i].value=c;
        if(l=='-'){
            tree2[i].left=-1;
        }
        else{
            tree2[i].left=l-'0';
        }
        if(r=='-'){
            tree2[i].right=-1;
        }
        else{
            tree2[i].right=r-'0';
        }
    }
    int root1=FindRoot(tree1);
    int root2=FindRoot(tree2);
    if(N1!=N2){
        cout<<"No"<<endl;
    }
    else if(N1==0){             //����
        cout<<"Yes"<<endl;
    }
    else{
        if(compare(tree1,tree2,root1,root2)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }

    return 0;
} 