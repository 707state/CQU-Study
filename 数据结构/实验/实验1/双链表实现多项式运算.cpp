/*˫�����ʵ��Ӧ��
1.��дʹ��freelist �Ĵ�ͷ��β����˫��������Ķ��壬ʵ��˫������Ļ���������
2.����˫������ʵ��2��һԪ����ʽ�ļӷ��ͳ˷����㣬�������õ�������Ҫ����ָ���������еĶ���ʽ��
*/
#include <iostream>
using namespace std;

template<typename E> class DLLNode{     //˫����ڵ�
private:
    static DLLNode<E>* freelist;
public:
    E ratio;                            //ϵ��
    E index;                            //ָ��
    DLLNode* prev;
    DLLNode* next;
    DLLNode(E r,E i,DLLNode* prevp,DLLNode* nextp){
        ratio=r;
        index=i;
        prev=prevp;
        next=nextp;
    }
    DLLNode(DLLNode* prevp=NULL,DLLNode* nextp=NULL){
        prev=prevp;
        next=nextp;
    }
    void* operator new(size_t){
        if(freelist==NULL){
            return ::new DLLNode;
        }
        DLLNode<E>* tmp=freelist;
        freelist=freelist->next;
        return tmp;
    }
    void operator delete(void* ptr){
        ((DLLNode<E>*)ptr)->next=freelist;
        freelist=(DLLNode<E>*)ptr;
    }
};

template <typename E>
DLLNode<E>* DLLNode<E>::freelist = NULL;

template <typename E> class DLList{     //˫����
public:
    DLLNode<E>* head;                   //���Ǽ̳У����ǵ���
    DLLNode<E>* tail;
    DLLNode<E>* current;
    int cnt;
    //��������
    void InitList(){
        head=new DLLNode<E>();
        tail=new DLLNode<E>();
        current=head;
        head->next=tail;
        tail->prev=head;
        cnt=0;
    }
    void RemoveAll(){
        while(head!=NULL){
            current=head;
            head=head->next;
            delete current;
        }
    }

    DLList(){
        InitList();
    }
    ~DLList(){                          //��������һ��һ��д�ã�������������޷�����
        RemoveAll();
    }
    void clear(){
        RemoveAll();
        InitList();
    }
    void prev(){
        if(current!=head){
            current=current->prev;
        } 
    }
    void next(){
        if(current!=tail){
            current=current->next;
        }
    }
    E getRatio(){
        return current->ratio;
    }
    E getIndex(){
        return current->index;
    }
    void insert(E r,E i){                   //��currentָ����ָλ�ú����Ԫ��
        DLLNode<E>* node=new DLLNode<E>(r,i,current,current->next);
        current->next->prev=node;            //ע�⸳ֵ�Ⱥ�˳��
        current->next=node;
        cnt++;
    }
    void append(E r,E i){                   //�����ĩβ
        DLLNode<E>* node=new DLLNode<E>(r,i,tail->prev,tail);
        tail->prev->next=node;
        tail->prev=node;
        cnt++; 
    }
    void remove(){                          //ɾ��current��ָԪ��
        if(current->next!=tail){
            return;
        }
        DLLNode<E>* tmp=current->next;
        current->next->next->prev=current;
        current->next=current->next->next;
        delete tmp;
        cnt--;
    }
    void MoveToStart(){                     //ָ��ͷ���
        current=head;
    }
    void MoveToEnd(){                       //ָ��β���
        current=tail;
    }
    void moveToPos(int pos){
        current=head;
        for(int i=0;i<pos;i++){
            current=current->next;
        }
    }
    void getBegin(){                        //ָ���һ��Ԫ��
        current=head->next;
    }
    int length(){
        return cnt;
    }
    int currPos(){
        DLLNode<E>* tmp=head;
        int i;                      //����ѭ������Է���
        for(i=0;tmp!=current;i++){
            tmp=tmp->next;
        }      
        return i;
    }
    void addRatio(E r){
        current->ratio+=r;
    }
};

DLList<int> add(DLList<int> &A,DLList<int> &B){
    DLList<int> List;
    A.getBegin();
    B.getBegin();
    while(1){
        if(A.getIndex()==B.getIndex()){
            if(A.getRatio()+B.getRatio()!=0)
                List.append(A.getRatio()+B.getRatio(),A.getIndex());
            A.next();
            B.next(); 
        }
        else if(A.getIndex()>B.getIndex()){
            List.append(A.getRatio(),A.getIndex());
            A.next();
        }
        else{
            List.append(B.getRatio(),B.getIndex());
            B.next();
        }
        if(A.currPos()>A.length() || B.currPos()>B.length()){     //����һ��˫��������꣬����ѭ��
            break;
        }
    }
    //������һ��û�б������˫����ʣ������ӵ�L3��β��
    if(A.currPos()>A.length()){         //Bû����
        while(1){
            List.append(B.getRatio(),B.getIndex());
            B.next();
            if(B.currPos()>B.length()){
                break;
            }
        }
    }
    else{                               //Aû����
        while(1){
            List.append(A.getRatio(),A.getIndex());
            A.next();
            if(A.currPos()>A.length()){
                break;
            }
        }
    }
    return List;
}

DLList<int> mult(DLList<int> &C,DLList<int> &D){
    DLList<int> List;
    bool flag=0;
    C.getBegin();
    while(C.currPos()<=C.length()){
        D.getBegin();                               //D��λ
        while(D.currPos()<=D.length()){
            List.getBegin();
            int r=C.getRatio()*D.getRatio();      //ϵ�����
            int i=C.getIndex()+D.getIndex();      //ָ�����
            if(flag){
                for(int j=0;j<List.length();j++){
                    if(i<List.getIndex()&&j!=List.length()-1)       //ָ��С�ڵ�ǰ���ָ����û�����һ����㣬��ָ����һ�����
                        List.next();
                    else if(i<List.getIndex()&&j==List.length()-1){ //ָ��С�ڵ�ǰ���ָ���ҵ������һ����㣬��Ѹý��ӵ�ĩβ
                        List.append(r,i);
                        break;
                    }
                    else if(i==List.getIndex()){           //ָ����ͬ����ϵ����ӣ��õ��µĽ��ͬʱɾ��ԭ���Ľ��
                        if(r+List.getRatio()!=0)
                            List.addRatio(r);
                        else
                            List.remove();
                        break;
                    }
                    else{                                   //ָ�����ڵ�ǰ�ڵ�ָ���������ý��
                        List.insert(r,i);
                        break;
                    }       
                }
            }
            else{                           //��һ������ֱ�ӽ����н���ӵ�L�У�����Ƚ�
                List.append(r,i);
            }
            flag=1;
            D.next();
        }
        C.next();
    }
    return List;
}

void print(DLList<int> E){
    E.getBegin();
    cout<<E.length()<<endl;
    for(int i=0;i<E.length();i++){
        cout<<E.getRatio()<<" "<<E.getIndex()<<endl;
        E.next();
    }
}


int main(){
    int N,M;
    cin>>N>>M;
    DLList<int> List1,List2;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        List1.append(a,b);
    }
    for(int j=0;j<M;j++){
        int c,d;
        cin>>c>>d;
        List2.append(c,d);
    }
    print(add(List1,List2));
    print(mult(List1,List2));
    
    // List1.next();
    // List1.next();
    // List1.prev();
    // List1.getBegin();
    // List1.next();
    // while(List1.current!=List1.tail){
    //     cout<<List1.getRatio()<<" ";
    //     List1.next();
    // }
    // cout<<List1.currPos();
    return 0;
}
/*3 2
5 4
-3 2
1 0
6 2
-3 1 */