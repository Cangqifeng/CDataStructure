#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

#include "algorithm/lzybasic.h"
#include "lzyclass/LinearList.h"

using namespace std;

// 删除连续的相同的元素
void LinearList::deleteSame(){
    int compare = 0, rollback=0;
    for(int i=0+1;i<this->L->length;i++){
        
        if(this->L->elem[compare]==this->L->elem[i]){
            // this->L->elem[i]
            // i--; // 指针回溯
            rollback++;
        }else{
            this->L->elem[i-rollback]=this->L->elem[i];
            compare = i-rollback;
            // rollback=0;
        }
        // cout<<"rollback: "<<rollback;
    }
    this->L->length -= rollback;
};

void LinearList::ordInsert(const ElemType e){
    int temp,index=0;
    if(this->L->length==MaxSize) return; // 错误的引索、线性表已满的情况直接返回false
    for(index=this->L->length-1;index>=0;index--) if(this->L->elem[index]<e) break;
    index++;
    for(temp = this->L->length; temp > index-1; temp--) this->L->elem[temp]=this->L->elem[temp-1]; // 将 index 位置之后的元素后一位
    this->L->elem[index] = e;
    this->L->length++;
};


int main(){
    /**
     * cpp类 顺序表 使用用实例
     * 推荐使用类指针，链式调用模式。
    */
    ElemType a[]={1,2,3,4,5,6,7,8,9,0};
    // 实例化一个类
    LinearList mylist;
    // LinearList mylist(NULL, a, 10);
    cout<<"是否是空：";
    printToString(mylist.listEmpty(),true);
    mylist.printList(true);
    cutLine();
    mylist.insertElem( 0, 666);
    mylist.insertElem( 1, 2333);
    cout<<"是否是空：";
    printToString(mylist.listEmpty(),true);
    mylist.printList(true);
    cutLine();
    cout<<"元素6位于引索："<<mylist.lastIndexOf(6)<<endl;
    mylist.deleteElem(0);
    mylist.printList(true);
    cutLine("逆序后：");
    mylist.reverse();
    mylist.insertElem(0, 3);
    mylist.printList(true);
    // cutLine();
    // mylist.sort();
    // mylist.printList();
    cutLine("分区后：");
    mylist.partition();
    mylist.printList(true);
    
    mylist.destroyList();
    cout<<endl<<endl<<endl;

    /**
     * 线性表的链式调用示例：
    */
    // 实例化类指针
    int init[] = {1,1,3,6,9,9,9,11,13,13};
    LinearList * secondList = new LinearList(NULL,init,10);
    secondList->printList(true);
    // secondList->deleteSame();
    // cutLine("删除重复元素后：");
    // secondList->printList(true);

    cutLine("插入`7`到适当的位置后：");
    secondList->ordInsert(7);
    secondList->printList(true);

    cout<<endl<<endl<<"线性表是否为空：";
    printToString(secondList->listEmpty(),true);
    // 两轮插入和删除一次性操作
    secondList->insertElem(0, 222)->printList(true)->insertElem(1,333)->printList()->reverse()->printList()->deleteElem(1)->printList(true)->deleteElem(0)->printList();

    cout<<endl<<endl;

    system("pause");
    
    /**
     * 链表 cpp类 链表 链式调用示例：
    */

    // LinkList * mylist = new LinkList();
    // ElemType a[]={1,2,3,4,5,6};
    // mylist->createList(a,6)->printList();
    // mylist->insertElem(0,1)->printList()->insertElem(1,2)->printList();
    // cutLine("Debug!");
    // mylist->insertElem(2,2333)->printList();
    // // lzytoString(NULL,true);
    // // lzytoString(false,true);
    // printToString("试试",true);
    // // lzytoString("试试",true);
    // // lzytoString(2333,true);
    // delete mylist;
    // system("pause");
}
