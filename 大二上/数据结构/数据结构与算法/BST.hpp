#include<iostream>
#include<type_traits>
#ifndef BST
#define __BST__
namespace BST{
//二叉搜索树包括插入一个数值，查询是否包含某个数值，删除某个数值\
这三个操作
    struct node
    {
        int val;
        node *left_ch,*right_ch;
        /* data */
    };
    node *insert(node *p,int x){
        if(p==NULL){
            node *q=new node;
            q->val=x;
            q->left_ch=q->right_ch=NULL;
            return q;
        }else{
            if(x<p->val)p->left_ch=insert(p->left_ch,x);
            else p->right_ch=insert(p->right_ch,x);
            return p;
        }
    }
    bool find(node *p,int x){
        if(p==NULL) return false;
        else if(x==p->val) return true;
        else if(x<p->val) return find(p->left_ch,x);
        else if(x>p->val) return find(p->right_ch,x);
    }
    node *remove(node *p,int x){
        if(p==NULL) return NULL;
        else if(x<p->val) p->left_ch=remove(p->left_ch,x);
        else if(x>p->val) p->right_ch=remove(p->right_ch,x);
        else if(p->left_ch==NULL){
            node *q=p->left_ch;
            q->right_ch=p->right_ch;
            delete p;
            return q;
        }else{
            //删除树叶
            node *q;
            for(q=p->left_ch;q->right_ch!=NULL;q=q->right_ch);
            node *r=q->right_ch;
            q->right_ch=r->left_ch;
            r->left_ch=p->left_ch;
            r->right_ch=p->right_ch;
            delete p;
            return r;

        }
        return p;
    }
}
#endif // !BST
