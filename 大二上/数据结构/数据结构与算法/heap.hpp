#include<iostream>
#include<bits/stdc++.h>
#ifndef heap
#define __HEAP__
 // !heap
namespace isContaner{
    template<typename T>
    struct is_container{
        static const bool value=false;
    };
    template<typename T,typename Alloc>
    struct is_container<std::vector<T,Alloc>>
    {
        /* data */static const bool value=true;
    };
    template<typename T,typename Alloc>
    struct is_container<std::list<T,Alloc>>
    {
        /* data */static const bool value=true;
    };
    template<typename T,typename Alloc>
    struct is_container<std::map<T,Alloc>>
    {
        /* data */static const bool value=true;
    };
    template<typename T,typename Alloc>
    struct is_container<std::queue<T,Alloc>>
    {
        /* data */static const bool value=true;
    };
}
//对应的标准库实现是std::priority_queue
// using namespace std;
//堆是一种插入一个数值，同时能够取出最小数值并删除的数据结构
//堆是一种二叉树，性质是儿子的值一定不小于父亲的值
//本例里面采用数组储存二叉树而不是双指针
//左儿子编号是自己的编号*2+1，右儿子是*2+2
template<class T>
class HEAP
{
private:
int size=0;
T *hp=new T[size];
    /* data */
public:
    HEAP(T &a);
    T pop();
    void push(T x);
    ~HEAP();
};
template<class T>
HEAP<T>::HEAP(T &a){
    auto if_container=isContaner::is_container<T>::value;
    if(!if_container){
        if(sizeof(a)/sizeof(T)==sz)
            hp=a;
        else
            hp=NULL;
    }else{
        hp=a;
    }
}
template<class T>
void HEAP<T>::push(T x){
    int i=size++;
    while(i>0){
        int p=(i-1)/2;//父节点的编号
        if(hp[p]<=x) break;
        hp[i]=hp[p];
        i=p;
        //把父节点的数值放下来，把自己的放上去
    }
    hp[i]=x;
}
template<class T>
T HEAP<T>::pop(){
    int ret=hp[0];
    int x=hp[--size];
    //要提到根的数值
    whle(i*2+z<size){
        int a=i*2+1,b=i*2+2;
        if(b<size&&hp[b]<hp[a]) a=b;
        if(hp[a]>=x) break;
        hp[i]=hp[a];i=a;
    }
    hp[i]=x;
    return ret;
}
template<class T>
HEAP<T>::~HEAP()
{
}





#endif