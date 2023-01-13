/*β��ѭ���ĵ�����
��Ŀ���г���ΪN�ĵ�����Node* head, ��β���ڵ��nextָ�벻ΪNULL������ָ�������ĳ���ڵ㣬
    ����ѭ���ṹ������Ҫ�����β���ڵ���ָ��ѭ���ڵ㣬�����λ�á�
    �����ӿڶ��壺int find_cycling_position ( Node* head );����head��Ϊ�գ�ָ�������ͷ��㡣
    ��������N (1��N��2000000)����������ѭ���ڵ�λ��K (1��K��N)������K=1����ʾͷ���Ϊѭ���ڵ㡣
˼·��Floyd��Ȧ�㷨
    Floyd�����㷨��һ��ָ���㷨�����㷨��ʹ���ƶ��ٶȲ�ͬ������ָ����ܼ����Ƿ��л���Floyd����
    �㷨����������⣺1.����Ƿ��л� 2.�������ڵ� 3.���ĳ��ȡ�
    1.����Ƿ��л���
        ������һ�������ܵ����ܲ���������ͬʱ�����������Ժ��ٶȿ�����վ�����ĳһ����ٶ���������
        ����һ�����ʱ���������ٶȿ���˱��ٶ����������ٶ���һȦ�����Ǽ�������Ŀ�ʼ�ڵ���S����
        �ϵ���ʼ�ڵ���P����һ�������Ľڵ���M��S��P�ľ�����p����P��M�ľ�����m,��M��p�ľ�����n��
        ָ��t��h��ʼ״̬�¶�ָ��S������tÿ��ֻ��1����hÿ����2����ֻҪ����û����������һֱ������
        ���ٶ�����ȥ����h�޷�ǰ�����������ĩβ����ʱ�򣬿����ж�û�л������t��h��ĳ���ٴ�������
        ��ȷ���л���
    2 ���㻷����
        ��t��h������M�㡣��Ϊ�����ĵ�һ���ڻ��ϡ���ʱ�򱣴�h������t��֮ǰ���ٶȼ���ǰ����ֱ����
        h�ٴ�����������������ƶ��Ĳ������ǻ��ĳ��ȡ�
    3 ������ʼ�ڵ�ȷ��
        ��ȷ���Ƿ��л��Ĺ����У�h�ߵľ�����t�ߵľ����2������cΪ������t�ߵľ���s1=p+m+a*c��
        h�ߵľ�����2*s1=p+m+b*c,��ʽ������õ���s1=(b-a)*c����s1=p+m+a*c,����p+m=������������
        Ϊ���ҵ�������㣬t�ص���㣬h�ڵ�ǰλ�á�����ͬ�ٶ�ͬʱ��ǰ�������ٴ�����һ����P�㡣
        Ϊʲô�أ���Ϊ��S��P�ľ�����p����P��M�ľ�����m����Ϊm+p�ǻ���������������p+m=kc������
        p=c-m+(k-1)c�����Ե�h�߹�����p����P��ʱ��t�߹���(k-1)Ȧ+c-m��Ҳһ���ﵽ��P�㡣
*/
#include <iostream>
#include <string.h>
using namespace std;

class Node{
public:
    Node* next;    
    Node(Node* p=NULL){
        next = p;
    }
};

int find_cycling_position(Node* head){
    Node*rabbit,*turtle;
    int cnt=1;                          //��¼���λ��
    rabbit=turtle=head;                 //��������
    while(true) {
        rabbit=(rabbit->next)->next;    //���������� 
        turtle=turtle->next;            //�ڹ���һ�� 
        if(rabbit==turtle){
            break;                      //��ʱ����
        }
    }
    /*//ִ�д˴���ɵû��ĳ���
    rabbit=rabbit->next;
    int circle=1;
    while(rabbit!=turtle){
        rabbit=rabbit->next;
        circle+=1;
    }
    return circle;
    */
    rabbit=head;                        //���ӻص���� 
    while(rabbit!=turtle){
        rabbit=rabbit->next;            //����ٶ���ͬ 
        turtle=turtle->next;
        cnt++; 
    }
    return cnt; 
}

int main(int argc, const char * argv[]) {
    int N, K;
    cin >> N >> K;    
    Node* head = new Node();
    Node* tail = head;

    for(int n=1; n<N; n++){
        head = new Node(head);          //head���治�ϼ����½�㣬headʱ�̴�������ͷ
    }
    Node* curr = head;
    for(int k=1; k<K; k++){
        curr = curr->next;              //curr���ϴ�head����ƶ������մﵽ����β��
    }
    tail->next = curr;

    cout << find_cycling_position(head) << endl;

    return 0;
}
