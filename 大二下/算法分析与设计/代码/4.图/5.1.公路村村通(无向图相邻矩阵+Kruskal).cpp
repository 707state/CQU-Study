/*��·���ͨ��
��Ŀ�����д�����·��ͳ�����ݱ��У��г����п��ܽ���ɱ�׼��·����������·�ĳɱ�����ʹÿ�����䶼��
    ��·��ͨ����Ҫ����ͳɱ���
���룺���ݰ���������Ŀ������N����1000���ͺ�ѡ��·��ĿM����3N��������M�ж�ӦM����·��ÿ�и���3����
    �������ֱ��Ǹ�����·ֱ����ͨ����������ı���Լ��õ�·�Ľ���Ԥ��ɱ���Ϊ������������1��N��
    �š�
��������ͨ��Ҫ����ͳɱ�������������ݲ����Ա�֤��ͨ�������?1����ʾ��Ҫ������๫·��
ע�⣺�˴���1��������˹��캯��������Ҫ����n+1������ʼ��ʱ��Ҫ��ʼ������������
    ����Ϊ����ͼ��Ϊ���������ֻʹ�������Ǿ���
˼·���˴�����Kruskal�㷨����ΪKruskal�㷨���ڱ�Ȩ������ͼ�в���������̫����ʱ����˶���KruskElem
    ��洢��Ȩ�Լ��ߵĽڵ㡣�Ա�Ȩ�������򣬼����Ƿ���ͬһ���ȼ��ࡣ����u,v��������������ͬ�ȼ���
    �п�����mark[u]==0||mark[v]==0��ʾ����
*/
#include <iostream>
#include <algorithm>
using namespace std;
class Graph{
private:
    int numVertex,numEdge;
    int **matrix;
    int *mark;
public:
    Graph(int num){
        Init(num);
    }
    ~Graph(){
        delete [] mark;
        for(int i=0;i<=numVertex;i++){
            delete [] matrix[i];
        }
        delete [] matrix;
    }
    void Init(int n){
        numVertex=n;
        numEdge=0;
        mark=new int[n+1];                  //��1����
        for(int i=0;i<=numVertex;i++){
            mark[i]=0;
        }
        matrix=(int**)new int*[numVertex+1];
        for(int i=0;i<=numVertex;i++){      //�ò�����ҲҪ��ʼ��
            matrix[i]=new int[numVertex+1];
        }
        for(int i=0;i<=numVertex;i++){
            for(int j=0;j<=numVertex;j++){
                matrix[i][j]=0;
            }
        }
    }
    int n(){
        return numVertex;
    }
    int e(){
        return numEdge;
    }
    int first(int v){
        for(int i=1;i<=numVertex;i++){
            if(matrix[v][i]!=0){
                return i;
            }
        }
        return numVertex+1;
    }
    int next(int v,int w){
        for(int i=w+1;i<=numVertex;i++){
            if(matrix[v][i]!=0){
                return i;
            }
        }
        return numVertex+1;
    }
    void setEdge(int v1,int v2,int w){
        if(matrix[v1][v2]==0){
            numEdge++;
        }
        matrix[v1][v2]=w;
    }
    void delEdge(int v1,int v2){
        if(matrix[v1][v2]!=0){
            numEdge--;
        }
        matrix[v1][v2]=0;
    }
    bool isEdge(int i,int j){
        return matrix[i][j]!=0;
    }
    int weight(int v1,int v2){
        return matrix[v1][v2];
    }
    int getMark(int v){
        return mark[v];
    }
    void setMark(int v,int value){
        mark[v]=value;
    }
    bool isConnected(){
        bool flag=1;
        for(int i=1;i<=numVertex;i++){
            if(mark[i]==0){
                flag=0;
            }
        }
        return flag;
    }
};
void DFS(Graph* G,int v){
    G->setMark(v,1);
    for(int w=G->first(v);w<=G->n();w=G->next(v,w)){
        if(G->getMark(w)==0){
            DFS(G,w);
        }
    }
}
void graphTraverse(Graph* G){       //��1��ʼ�������ж��Ƿ���ͨ
    for(int v=1;v<=G->n();v++){
        G->setMark(v,0);
    }
    DFS(G,1);
}

class KruskElem{                //Kruskal�㷨���ڱߣ���ÿ�ζ�ͨ��ͼ�ı���ʵ��̫��ʱ
public:
    int from,to,distance;       //�����������裬Ĭ��from<to
    KruskElem():from(-1),to(-1),distance(-1){}
    KruskElem(int f,int t,int d):from(f),to(t),distance(d){}
};
bool compare(KruskElem k1,KruskElem k2){    //�Ƚ�����KruskElem�бߵĴ�С
    return k1.distance<k2.distance;
}

int main(){
    int N,M;
    cin>>N>>M;
    Graph gph(N);
    KruskElem E[3001];
    for(int i=0;i<M;i++){
        int a,b,w;
        cin>>a>>b>>w;
        gph.setEdge(a,b,w);
        //gph.setEdge(b,a,w);       //Ϊ���������ֻд��һ����
        E[i]=KruskElem(a,b,w);
    }
    graphTraverse(&gph);            //����ͼ�ж��Ƿ���ͨ
    if(!gph.isConnected()){
        cout<<-1<<endl;
        return 0;
    }
    sort(E,E+M,compare);            //�Ա�Ȩ��������
    for(int v=1;v<=gph.n();v++){    //����mark����
        gph.setMark(v,0);
    }
    int price=0;                    //��·�ɱ�������Ȩ֮��
    int cnt=0;                      //��¼ѡ�б���֮��
    for(int i=0;i<M;i++){           //����Ȩ���������
        if(cnt>=N-1){
            break;
        }
        if(gph.getMark(E[i].from)==0||gph.getMark(E[i].to)==0){ //�����ӵĵ�����һ��δ������
            gph.setMark(E[i].from,1);
            gph.setMark(E[i].to,1);
            cnt++;
            price+=E[i].distance;
        }
    }
    cout<<price<<endl;

    return 0;
}
