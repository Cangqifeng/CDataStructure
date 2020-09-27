#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

#include "lzyclass/LinkList.h"
#include "algorithm/lzybasic.h"

using namespace std;

int main(){
    // linearList * L;
    // initList(L);
    // ElemType a[]={1,2,3,4,5,6,7,8,9,0};
    // createList(L,a,10);
    // LinearList mylist;
    // LinearList mylist(NULL, a, 10);
    // cout<<"是否是空：";
    // printToString(mylist.listEmpty(),true);
    // mylist.printList();
    // cutLine();
    // mylist.insertElem( 0, 666);
    // mylist.insertElem( 1, 2333);
    // cout<<"是否是空：";
    // printToString(mylist.listEmpty(),true);
    // mylist.printList();
    // cutLine();
    // mylist.deleteElem(0);
    // mylist.printList();
    // cutLine();
    // mylist.reverse();
    // mylist.insertElem(0, 3);
    // mylist.printList();
    // cutLine();
    // mylist.sort();
    // mylist.printList();
    // cutLine("逆序后：");
    // mylist.partition();
    // mylist.printList();
    // int input=0;
    // cout<<"hello world"<<endl;
    // mylist.destroyList();
    // cin>>input;

    /**
     * 链表 cpp类链式调用示例：
    */

    LinkList * mylist = new LinkList();
    mylist->insertElem(0,1)->printList()->insertElem(1,2)->printList();
    cutLine("Debug!");
    mylist->insertElem(2,2333)->printList();
    printToString("试试",true);
    delete mylist;
    system("pause");
}
