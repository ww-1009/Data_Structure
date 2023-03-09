// #include "include/include.h"
#include<iostream>
using namespace std;

#define Elemtype int
// #define Maxsize 50
#define initSize 100

typedef struct{
    Elemtype *data;
    int Maxsize=20,length;
}SqList;

/* 
初始化顺序表
 */
SqList InitList(Elemtype arr[],int length){
    // int length=sizeof(arr)/sizeof(arr[0]);
    SqList s;
    s.data=(int*)malloc(sizeof(Elemtype)*initSize);
    for (int i = 0; i < length; i++)
        s.data[i]=arr[i];
    s.length=length;
    return s;
}
/* 
顺序表插入操作
 */
bool ListInsert(SqList &L,int i,Elemtype e){
    if(i<1 || i>L.length+1) //判断i范围是否有效
        return false;
    if(L.length>=L.Maxsize) //判断存储空间是否已满
        return false;
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
    for (int i = 0; i < L.length; i++)
        cout<<L.data[i]<<',';
    cout<<']'<<endl;
}