#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

#include "lzystructure/linearList.h"
#include "algorithm/lzybasic.h"

using namespace std;

int main(){
    linearList * L;
    int a[]={1,2,3,4,5,6,7,8,9,0};
    createList(L,a,10);
    cout<<"是否是空：";
    printToString(listEmpty(L),true);
    printList(L);
    cutLine();
    insertElem(L, 0, 666);
    insertElem(L, 1, 2333);
    cout<<"是否是空：";
    printToString(listEmpty(L),true);
    printList(L);
    cutLine();
    deleteElem(L,0);
    printList(L);
    destroyList(L);
    system("pause");
}
