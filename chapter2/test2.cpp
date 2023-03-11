// #include<stdio.h>
#include<iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*Linklist;

Linklist List_headin(Linklist &L){
    Linklist s;int x;
    L=(Linklist)malloc(sizeof(LNode));
    L->next=NULL;
    cout<<"请依次输入单链表的值，输入9999终止"<<endl;
    scanf("%d",&x);
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}

int main(){
    Linklist L;
    List_headin(L);
    LNode*p=L->next;  
    while(p!=NULL){
    cout<<p->data<<' ';
        p=p->next;
    }
}