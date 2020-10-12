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
const bool DEBUG = true;

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
/*尾插法初始化链表； initList的替代方法*/
bool createList(linkNode * &L,ElemType a[], int n){
    int i=0;
    L = (linkNode *)malloc(sizeof(linkNode));
    linkNode *p=L, *newcomer;
    // while(i<sizeof(a)/sizeof(a[0]) && p!=NULL){ // sizeof是在编译阶段处理的关键词，会被替换常量，在定义函数中`sizeof(a)/sizeof(a[0])`, 传入参数`a`只是数组地址了，编译时无法获取信息
    while(i<n){
        newcomer = (linkNode *)malloc(sizeof(linkNode));
        newcomer->data = a[i]; // 保存数据
        newcomer->next = p->next; // 链接后链
        p->next = newcomer; // 更改前链 以链接
        p=p->next;
        i++;
    }
    p->next=NULL;
    return true;
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

void printList(linkNode *L, bool inlinePrint=false){
    linkNode *p=L;
    int i=0;
    if(p->next==NULL) cout<<"『当前链表为空』"<<endl;
    while (p->next!=NULL)
    {
        i++;
        p=p->next; // 先执行以跳过头节点
        if(inlinePrint) cout<<p->data<<"  ";
        else cout<<endl<<"第"<<i<<"个元素是："<<p->data;
    }
    cout<<endl;
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

bool insertElem(linkNode *&L, int index,const ElemType e){
    linkNode *p = L, *target;
    if(index<0) index+=listLength(L);
    if(index<0) return false;
    for(int i=0;i<index && p!=NULL;i++){
        p=p->next;
    }
    // 未找到第i个节点返回 false
    if(p==NULL){
        if(DEBUG) cout<<"[insertElem] 传入链表指针为空"<<endl;
        return false;
    }else{
        target = (linkNode *)malloc(sizeof(linkNode));
        target->data = e;
        target->next = p->next; // 新节点连接到后链
        p->next = target; // 前链连接新节点
        return true;
    }
}

bool deletElem(linkNode *&L, int index){
    int i = 0;
    // 允许负引索
    if(index<0) index+=listLength(L);
    linkNode *p=L, *target;
    if(i<0) return false;
    // 遍历不为NULL的节点
    while(i<index && p->next!=NULL){
        i++;
        p=p->next;
    }
    if(p->next==NULL) return false; // index溢出了
    else{
        target=p->next; // 找到第index个的目标节点
        if(target==NULL) return false;
        p->next=target->next;
        free(target);
        return true;
    }
}
// 重载，用第三个参数接收返回值
bool deletElem(linkNode *&L, int index, ElemType &e){
    int i = 0;
    linkNode *p=L, *target;
    if(i<0) return false;
    // 遍历不为NULL的节点
    while(i<index && p->next!=NULL){
        i++;
        p=p->next;
    }
    if(p->next==NULL) return false; // index溢出了
    else{
        target=p->next; // 找到第index个的目标节点
        if(target==NULL) return false;
        e = target->data;
        p->next=target->next;
        free(target);
        return true;
    }
}

// bool slice(); 删除从start 到 end（不包括end） 引索位置的元素
bool slice(linkNode *L, int start, int end){
    int length=listLength(L);
    if(start<0) start+=length; if(end<0) end+=length;
    if(start>end || end > length || start<0){
        if(DEBUG) cout<<"Error:in slice() 引索溢出：start:"<<start<<" end:"<<end<<endl;
        return false;
    }
    int temp, gap=end-start, i = 0;
    linkNode *p=L, *target;
    // 遍历不为NULL的节点
    while(i<start && p!=NULL){
        i++;
        p=p->next;
    }
    if(p==NULL){if(DEBUG) cout<<"Error:in Slice() 遍历节点出错,Start引索位置溢出"<<endl; return false;} // start 溢出了
    else{
        
        for(int j=0;j<gap;++j){
            target=p->next; // 找到start位置的目标节点
            if(target==NULL){
                if(DEBUG) cout<<"Error:in Slice() 删除节点时出错，End引索位置过大溢出"<<endl;
                return false;
            }
            p->next=target->next;
            free(target);
        }
        return true;
    }
}

// 倒序链表：采用头插法插入新增链表，时间复杂度为O(n), 空间复杂度为O(1) 而递归实现事实上性能差不多
bool reverse(linkNode *&L){
    linkNode *p=L, *pre, *prePre, *temp;
    int i=0;
    initList(temp);
    if(p->next!=NULL) prePre=pre=p;
    while(p->next!=NULL){
        // if(i>0) pre = p;
        // if(i>1) prePre = pre;
        p=p->next; // 优先，可跳过头结点
        insertElem(temp,0,p->data);
        // printList(temp,true);
        // 一边销毁p，减小空间占用
        // if(i>1){ deletElem(prePre,0);}
        // printList(prePre,true);
        // printList(p,true);
        // if(i==0) free(pre);
        i++;
    }
    destroyList(pre); // 销毁最后的尾节点和头结点
    L = temp;
    return true;
}

#endif
