#include "SqList.h"
#include<iostream>
using namespace std;

#define Elemtype int

/* 
    test1 
*/
bool deletmin(SqList &s,Elemtype &value){
    if(s.length==0){
        printf("顺序表为空\n");
        return false;
    }
    Elemtype min=s.data[0];
    int index_min=0;
    for (int i = 1; i < s.length; i++)
        if (s.data[i]<min){
            min=s.data[i];
            index_min=i;
        }
            
    value=min;
    s.data[index_min]=s.data[s.length-1];
    s.length--;
    return true;
}

/* 
    test2
 */
void Reverse_e(SqList &s){
    for (int i = 0; i < s.length/2; i++)
    {
        /* 交换值
            a=a^b
            b=a^b
            a=a^b
         */
        s.data[i]=s.data[i]^s.data[s.length-i-1];
        s.data[s.length-i-1]=s.data[i]^s.data[s.length-i-1];
        s.data[i]=s.data[i]^s.data[s.length-i-1];
    }
    return;
}

/* 
    test3
 */
void Del_x_1(SqList &s,Elemtype e){
    int k=0; //不等于e的个数
    for (int i = 0; i < s.length; i++)
        if(s.data[i]!=e){
            s.data[k]=s.data[i];
            k++;
        }

    s.length=k;
    return ;
}

/* 
    test4
 */
bool Del_s_t2(SqList &L,int s,int t){
    int i,j;
    if(s>=t||L.length==0)
        return false;
    for ( i = 0; i<L.length && L.data[i] < s; i++);
    if(i>=L.length)
        return false;
    for ( j = i; j<L.length && L.data[j] <= t; j++);
    for(;j<L.length;i++,j++){
        L.data[i]=L.data[j]; 
    }
    L.length=i;
    return true;

}

/* 
    test6
 */
bool Del_same(SqList &s){
    if(s.length==0)
        return false;
    if (s.length==1)
        return true;
    
    int k=0;
    int temp=s.data[0];
    for (int i = 1; i < s.length; i++)
    {
        if(s.data[i]!=s.data[i-1])
            k++;
            s.data[k]=s.data[i];
    }
    s.length=k+1;
    return true;
}

/* 
    test7
 */
bool Merge(SqList s1,SqList s2,SqList &s){
    if (s1.length+s2.length>s.Maxsize)
        return false;
    int i=0,j=0,c=0;
    while (i<s1.length&&j<s2.length)
    {
        if (s1.data[i]<=s2.data[j])
            s.data[c++]=s1.data[i++];
        else
            s.data[c++]=s2.data[j++];
    }
    while (i<s1.length)
        s.data[c++]=s1.data[i++];
    while (j<s2.length)
        s.data[c++]=s2.data[j++];
    s.length=c;
    return true;
}

/* 
    test8
 */
//反转left和right之间的元素
void Reverse(Elemtype A[],int left,int right,int arraysize){
    if (left>=right&&right>=arraysize)
        return ;
    for (int i = left,j=right; i <= left+(right-left)/2; i++)
    {
        Elemtype temp=A[i];
        A[i]=A[j];
        A[j--]=temp;
    }
    return;
}
void Exchange(Elemtype A[],int m,int n,int arraysize){
    if (n+m!=arraysize)
        return;    
    Reverse(A,0,m-1,m);
    Reverse(A,m,n-1,n);
    Reverse(A,0,arraysize-1,arraysize);
    return;
}

int main(){
    Elemtype a[]={3,5,2,2,7,1,4};
    // Elemtype a[]={1,1,2,2,3,3,4};
    Elemtype b[]={1,3,3,4,4,7};
    SqList s=InitList(a,7);
    printarr(s.data,s.length);
    // ListInsert(s,3,3);
    // cout<<locateElem(s,2)<<endl;

    // Elemtype e=0;
    // ListDelete(s,2,e);

    // printf("%d\n",s.length);
    // printf("%d",s.data[0]);
    Elemtype value=0;
    // deletmin(s,value);
    // printf("%d\n",value);
    // Reverse_e(s);
    // Del_x_1(s,2);
    // Del_s_t2(s,2,5);
    // Del_same(s);
    // SqList d=InitList(b,6);
    // SqList c=InitList(b,0);
    // Merge(s,d,c);
    // Exchange(a,3,4,7);
    // printarr(s.data,s.length);
    
    
}