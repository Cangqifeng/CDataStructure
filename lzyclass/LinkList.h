/**
 * 单链表
 * 普通单指针操作链式线性基本表的Cpp类封装
 * 支持链式调用
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
    LNode * next; // 嵌套定义
    // LNode * next;
} linkNode;

class LinkList{
    private:
        // 调试模式：设为true以开启，调用方法时输出流程信息
        const bool DEBUG = false; // 定义类内的常量而不是宏以提高内聚性
        LinkList * initList(){
            this->L=(linkNode *) malloc(sizeof(linkNode));
            this->L->next=NULL; // 创建头结点，将其next域设置为空
            return this;
        }

    protected:
        linkNode * L;

    public:
        LinkList(){
            this->initList();
        }

        ~LinkList(){
            this->destroyList();
        }

        void destroyList(){
            linkNode * pre=L, * p=L->next;
            while (p!=NULL)
            {
                free(pre);
                pre=p;
                p=pre->next;
            }
        }
        bool listEmpty(){
            return this->L->next==NULL;
        }

        int listLength(){
            int n=0;
            linkNode *p=this->L;
            while (p->next!=NULL)
            {
                n++;
                p=p->next;
            }
            return n;
        }
        // 获取元素，下表从零开始记录
        bool getElem(int i, ElemType &e){
            int j=0;
            linkNode * p=this->L;
            if(i<0) return false;
            while (p->next!=NULL && j<=i)
            {
                p=p->next;
                j++;
            }
            if(p==NULL) return false; // 如果在末尾第i+1个元素不一定存在
            else return true;
        }

        int locateElem(ElemType e){
            int i=0;
            linkNode *p=this->L->next;
            while (p!=NULL && p->data!=e)
            {
                p=p->next;
                i++;
            }
            if(p==NULL) return -1;
            else return i;
        }
        // 支持链式调用
        // 从1号位置陆续插入数据
        LinkList * createList(ElemType a[], int n){
            int i=0;
            linkNode *p=this->L, *newcomer;
            // while(i<sizeof(a)/sizeof(a[0]) && p!=NULL){ // sizeof是在编译阶段处理的关键词，会被替换常量，在定义函数中`sizeof(a)/sizeof(a[0])`, 传入参数`a`只是数组地址了，编译时无法获取信息
            while(i<n && p!=NULL){
                newcomer = (linkNode *)malloc(sizeof(linkNode));
                newcomer->data=a[i]; // 保存数据
                newcomer->next=p->next; // 链接后链
                p->next = newcomer; // 更改前链
                p=p->next;
                i++;
            }
            return this;
        }
        // LinkList * createList(ElemType a[]){
        //     int i=0;
        //     linkNode *p=this->L->next;
        //     cout<<arrayLength(a);
        //     // while(i<sizeof(a)/sizeof(a[0]) && p!=NULL){ // sizeof是在编译阶段处理的关键词，会被替换常量，在定义函数中`sizeof(a)/sizeof(a[0])`, 传入参数`a`只是数组地址了，编译时无法获取信息
        //     while(i<arrayLength(a) && p!=NULL){
        //         p->data=a[i];
        //         p=p->next;
        //         i++;
        //     }
        //     return this;
        // }
        LinkList * printList(){
            linkNode *p=this->L->next;int i=0;
            while (p!=NULL)
            {
                i++;
                cout<<"第"<<i<<"个元素是："<<p->data<<endl;
                p=p->next;
            }
            return this;
        }
        LinkList * insertElem(int index, ElemType e){
            linkNode *p = this->L, *newcomer;
            int i=0;
            while(i<index && p!=NULL){
                i++;
                p=p->next;
            }
            if(p==NULL){
                if(DEBUG) cout<<"Exit: 已经达到了尾节点，未插入元素!"<<endl;
                // return NULL;
                return this;
            }
            newcomer = (linkNode *)malloc(sizeof(linkNode));
            newcomer->data=e; // 保存数据
            newcomer->next=p->next; // 链接后链
            p->next = newcomer; // 更改前链
            return this;
        }

        LinkList * slice(int start, int end){}
};

#endif
