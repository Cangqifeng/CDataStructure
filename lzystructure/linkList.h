/**
 * 单链表
 * 普通单指针操作链式线性基本表
 **/
#pragma once
#ifndef LINkLIST
#define LINkLIST

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
// #include "memory.h"
// 暂时假装定义要存储的数据类型，在main中去实现 需要重新定义比较判断模块，暂未整合，只支持int和char类型
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode * next; // 嵌套定义
    // LNode * next;
} linkNode;

void initList(linkNode * &L){
    L=(linkNode *) malloc(sizeof(linkNode));
    L->next=NULL; // 创建头结点，将其next域设置为空
}

void destroyList(linkNode * &L){
    linkNode * pre=L, * p=L->next;
    while (p!=NULL)
    {
        free(pre);
        pre=p;
        p=pre->next;
    }
}

bool listEmpty(linkNode *L){
    return L->next==NULL;
}

int listLength(linkNode *L){
    int n=0;
    linkNode *p=L;
    while (p->next!=NULL)
    {
        n++;
        p=p->next;
    }
    return n;
}

void printList(linkNode *L){
    linkNode *p=L->next;
    while (p->next!=NULL)
    {
        cout<<p->data<<endl;
    }
}
// 获取元素，下表从零开始记录
bool getElem(linkNode * L, int i, ElemType &e){
    int j=0;
    linkNode * p=L;
    if(i<0) return false;
    while (p->next!=NULL && j<=i)
    {
        p=p->next;
        j++;
    }
    if(p==NULL) return false; // 如果在末尾第i+1个元素不一定存在
    else return true;
}

int locateElem(linkNode * L, ElemType e){
    int i=0;
    linkNode *p=L->next;
    while (p!=NULL && p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL) return -1;
    else return i;
}

#endif
