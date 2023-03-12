#include<iostream>
using namespace std;

#define Element int

typedef struct LNode
{
    Element data;   //数据域
    struct LNode* next; //指针域
}LNode,*LinkList;


/* 
    初始化单链表（不带头结点）
 */
// bool InitLinkList(LinkList &L){
//     L=NULL;
//     return true;
// }


/* 
    初始化单链表（带头结点）
 */
LinkList InitLinkList(){
    LinkList L=(LNode*)malloc(sizeof(LNode));
    if (L=NULL) //空间不足
        return NULL;
    L->next=NULL;
    return L;
}

LinkList InitLinkList(Element a[],int len){
    LinkList L=(LNode*)malloc(sizeof(LNode));
    if (L==NULL) //空间不足
        return NULL;
    L->next=NULL;
    LNode *r=L;
    LNode *s=NULL;
    for (int i = 0; i < len; i++)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
    return L;
}

/* 
    头插法建立单链表
 */
LinkList List_HeadInsert(LinkList &L){
    Element x;
    LNode *s;
    L=(LNode*)malloc(sizeof(LNode));    //创建头结点
    L->next=NULL;
    cout<<"输入一整整数,输入9999表示退出"<<endl;
    scanf("%d",&x);
    while (x!=9999)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}


/* 
    尾插法建立单链表
 */
LinkList List_TailInsert(LinkList &L){
    Element x;
    L=(LNode*)malloc(sizeof(LNode));    //创建头结点
    LNode *s,*r=L; 
    L->next=NULL;
    cout<<"输入一整整数,输入9999表示退出"<<endl;
    scanf("%d",&x);
    while (x!=9999)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}

/*  
    按序号查找节点
*/
LNode *GetElem(LinkList L,int i){
    if (i<1)
        return NULL;
    int j=0;
    LNode *p=L; //p指向头结点
    // int j=1;
    // LNode *p=L->next; //p指向第一个节点
    while (p!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;   
}

/* 
    按值查找节点
 */
LNode *LocteElem(LinkList L,Element e){
    LNode *p=L->next;
    while (p!=NULL&&p->data!=e)
        p=p->next;
    return p;
}

/* 
    在第i个位置插入新节点(对i-1位节点进行后插)
 */
bool ListInsert(LinkList &L,int i,Element e){
    LNode *p=GetElem(L,i-1);
    if(p==NULL)
        return false;
    LNode *s=(LNode*)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

/* 
    对i位节点进行前插
 */
bool InsertPriorNode(LinkList &L,int i,Element e){
    LNode *p=GetElem(L,i);
    if(p==NULL)
        return false;
    LNode *s=(LNode*)malloc(sizeof(LNode));
    // Element temp=p->data;
    s->data=p->data;
    s->next=p->next;
    p->next=s;
    p->data=e;
    return true;
}

/* 
    删除第i个节点
 */
bool DeletNode(LinkList &L,int i){
    LNode *p=GetElem(L,i-1); //找到第i-1位节点
    if(p==NULL)
        return false;
    LNode *q=p->next;
    p->next=q->next;
    free(q);
    return true;
}

bool DeletNode2(LinkList &L,int i){
    LNode *p=GetElem(L,i); //找到第i位节点
    if(p==NULL)
        return false;
    LNode *q=p->next;
    if(q==NULL){ //处理尾指针
        p=NULL;
        return true;
    }
    p->data=q->data;
    p->next=q->next;
    free(q);
    return true;
}

/* 
    求表长
 */
int GetLength(LinkList L){
    int num=0;
    while (L->next!=NULL)
    {
        num++;
        L=L->next;
    }
    return num;
}

/* 
    打印链表(带头结点)
 */
void Print_List(LinkList L){
    while (L->next!=NULL)
    {
        cout<<L->next->data<<"-";
        L=L->next;
    }
    cout<<endl;
    return;
}

int main()
{
    LinkList L;
    Element a[]={1,6,3,4,5};
    // L=List_HeadInsert(L);
    // L=List_TailInsert(L);
    L=InitLinkList(a,5);
    DeletNode2(L,3);
    ListInsert(L,3,7);
    InsertPriorNode(L,3,8);
    Print_List(L);
    cout<<"链表长度为:"<<GetLength(L)<<endl;
    return 0;
}
