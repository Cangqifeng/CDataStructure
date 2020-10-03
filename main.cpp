#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

#include "lzystructure/linearList.h"
#include "algorithm/lzybasic.h"

using namespace std;


void fun(linearList *&L){
    int i,j=0;
    for( i=1;i<L->length;i++)
        if(L->elem[i]>L->elem[j])
            j=i;
    for( i=j;i<L->length-1;i++)
        L->elem[i]=L->elem[i+1];
    L->length--;
}

int main(){
    linearList * L;
    // initList(L);
    int a[]={1,2,3,4,5,6,7,8,9,0};
    createList(L,a,10);
    cout<<"是否是空：";
    printToString(listEmpty(L),true);
    // cout<<endl;
    printList(L);
    cutLine();
    insertElem(L, 0, 666);
    insertElem(L, 1, 2333);
    cout<<"是否是空：";
    printToString(listEmpty(L),true);
    printList(L);
    cutLine();
    deleteElem(L,0);
    deleteElem(L,0);
    printList(L);
    cutLine("切换fun函数：删除最大");
    fun(L);
    printList(L);
    destroyList(L);
    system("pause");
};

// void initList(linearList * &L){
//     L = (linearList *) malloc(sizeof(linearList));
//     L->length = 0;
// }
