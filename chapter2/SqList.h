// #include "include/include.h"
#include<iostream>
using namespace std;

#define Elemtype int
#define initSize 10

typedef struct{
    Elemtype *data;
    int Maxsize,length;
}SqList;

/* 
    初始化顺序表
 */
SqList InitList(Elemtype arr[],int length){
    // int length=sizeof(arr)/sizeof(arr[0]);
    SqList s;
    s.data=(int*)malloc(sizeof(Elemtype)*initSize);
    s.Maxsize=initSize;
    for (int i = 0; i < length; i++)
        s.data[i]=arr[i];
    s.length=length;
    return s;
}

/* 
    增加动态数组的长度
 */
void IncreaseSize(SqList &L,int len){
    Elemtype *p=L.data;
    L.data=(Elemtype *)malloc(sizeof(Elemtype)*(L.Maxsize+len));
    for (int i = 0; i < L.length; i++)
        L.data[i]=p[i];  //将原数据复制到新区域
    L.Maxsize+=len;
    free(p);
}

/* 
    顺序表插入操作
 */
bool ListInsert(SqList &L,int i,Elemtype e){
    if(i<1 || i>L.length+1) //判断i范围是否有效
        return false;
    //判断存储空间是否已满
    if(L.length>=L.Maxsize){
        cout<<"存储空间已满"<<endl;
        return false;
    } 
        
    for (int j = L.length; j >= i; j--) //将第i个个元素以及之后的元素后移
        L.data[j]=L.data[j-1];
    L.data[i-1]=e;
    L.length++;
    return true;
}

/* 
    删除操作
 */
bool ListDelete(SqList &L,int i,Elemtype &e){
    if(i<1 || i>L.length+1) //判断i范围是否有效
        return false;
    e=L.data[i-1];
    for (int j = i; j < L.length; j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}

/*
    按值查找 
*/
Elemtype locateElem(SqList L,Elemtype e){
    for (int i = 0; i < L.length; i++)
        if(L.data[i]==e)
            return i+1;
    return 0;
}

/* 
    打印数组
 */
void printarr(SqList &L){
    cout<<'[';
    for (int i = 0; i < L.length-1; i++)
        cout<<L.data[i]<<',';
    cout<<L.data[L.length-1];
    cout<<']'<<endl;
}
void printarr(Elemtype *L,int length){
    cout<<'[';
    for (int i = 0; i < length-1; i++)
        cout<<L[i]<<',';
    cout<<L[length-1];
    cout<<']'<<endl;
}
