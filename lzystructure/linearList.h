#pragma once
#ifndef LINEARLIST
#define LINEARLIST

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
// #include "memory.h"
// 暂时假装定义要存储的数据类型，在main中去实现 需要重新定义比较判断模块，暂未整合，只支持int和char类型
typedef int ElemType;
const bool DEBUG = true;

/**
 * 线性表——顺序存储结构
 * 
 **/

#define MaxSize 50  // 定义线性表存储最大长度

// 需要文件中include后声明以下函数
/**
 * 线性链表操作函数
 * 快速操作 说明手册

void initList(linearList * &L); // 初始化一个空的线性表
void createList(linearList * &L, ElemType data[], int n) // 自动确定长度的初始化方法
void destroyList(linearList * &L); // 销毁线性表并释放其所存储的空间
bool insertElem(linearList * &L, int i, ElemType el); // 在第 i 个位置插入 el 元素，i 不正确或空间不足返回false.
// bool insertElem(linearList * &L, int i, ElemType * el); // insertElem 方法的重载
bool deleteElem(linearList * &L, int i, ElemType &el); // 删除第 i 个元素，并用 el 返回其值
//  deleteElem(linearList * &L, int i); // deleteElem 方法的重载

// 以下方法只读取数据无需改实参值的引用传递
bool listEmpty(linearList * L); // @return [Bool] 线性表是否为空
int listLength(linearList * L); // 返回线性表（数据的）的长度
void printList(linearList * L); // （控制台）打印线性表
bool getElem(linearList * L, int index, ElemType &el); // 获取线性表中引索为 index 的元素的值，引用赋值到传入`el`的实参上，越界时返回false
// void getElem(linearList * L, int index, ElemType * el); // getElem 方法的重载，指针赋值给 ElemType 的数据类型（理论更省空间）
int locateElem(linearList * L, ElemType el); // 顺序查找第一个线性表数据中第一个和 el 相等的数据的引索，没有找到则返回-1
// void locateElem(linearList * L, ElemType * el); // locateElem 方法的重载，指针操作 ElemType 的数据类型（理论更省空间）

 *
 **/
// 写入方法需要修改线性表，引用传参
void initList(); // 初始化一个空的线性表
void createList(); // 使用数据初始化线性表，替代initList方法
void destroyList(); // 销毁线性表并释放其所存储的空间
bool insertElem(); // 在第 i 个位置插入 el 元素，i 不正确或空间不足返回false.
bool deleteElem(); // 删除第 i 个元素，并用 el 返回其值

// 以下只读方法读取数据无需改线性表实参值
bool listEmpty(); // @return [Bool] 线性表是否为空
int listLength(); // 返回线性表（数据的）的长度
void printList(); // （控制台）打印线性表
bool getElem(); // 获取线性表中引索为 index 的元素的值，引用赋值到传入`el`的实参上，越界时返回false
int locateElem(); // 顺序查找第一个线性表数据中第一个和 el 相等的数据的引索，没有找到则返回-1

// 构造数据结构 `linearList` 并用其定义一个变量实例 `L`
typedef struct
{
    int length;
    ElemType data[MaxSize];
} linearList;

// linearList L;

void initList(linearList * &L){
    L = (linearList *) malloc(sizeof(linearList));
    L->length = 0;
}
// 替代 initList 的初始化
bool createList(linearList * &L, ElemType data[], int n){
    int i=0;
    L=(linearList *) malloc(sizeof(linearList));
    while (i<n)
    {
        L->data[i]=data[i];
        i++;
    }
    L->length=i;
    return true;
}
void destroyList(linearList * &L){
    free(L);
}
bool listEmpty(linearList * L){
    return L->length==0;
}
int listLength(linearList * L){
    return L->length;
}
void printList(linearList * L, bool inlinePrint=false){
    for(int i=0;i<L->length;++i){
        if(inlinePrint) cout<<L->data[i]<<"  ";
        else cout<<endl<<"第"<<i+1<<"个元素是："<<L->data[i];
    }
    cout<<endl;
}
bool getElem(linearList * L, int index, ElemType &el){
    if(index<0 || index>=L->length) return false;
    return el=L->data[index] || true;
}
int locateElem(linearList * &L, ElemType el){
    int i;
    for(i=0;i<L->length && L->data[i]!=el;++i){};
    if(i >= L->length) return -1; // 未找到，执行了最后一次循环 使i==length
    else return i;
}
// 插入元素，允许负索引（最后一个为-1），从0开始计数
bool insertElem(linearList * &L, int index, ElemType el){
    if(index<0) index+=L->length;
    int temp;
    if(index<0 || index >= L->length || L->length==MaxSize) return false;
    for(temp = L->length; temp > index; temp--) L->data[temp]=L->data[temp-1]; // 将 index 位置之后的元素后一位
    L->data[index] = el;
    // cout<<"插入成功"<<endl;
    return !!(L->length++);
    // return true;
}
// 删除元素，允许负引索
bool deleteElem(linearList * &L, int index){
    if(index<0) index+=L->length;
    int temp;
    if(index<0 || index >= L->length) return false;
    for(temp=index;temp <= L->length;temp++) L->data[temp] = L->data[temp+1];
    L->length--;
    return true;
}
// 重载，增加一个输出参数
bool deleteElem(linearList * &L, int index, ElemType &el){
    int temp;
    if(index<0 || index >= L->length) return false;
    el=L->data[index];
    for(temp=index;temp<L->length;temp++) L->data[temp] = L->data[temp+1]; // 循环左移动
    L->length--;
    return true;
}
// 同locateElem，从左查找的方法
int indexOf(linearList *L, const ElemType el){
    int i;
    for(i=0;i<L->length && L->data[i]!=el;++i){};
    if(i >= L->length) return -1; // 未找到，执行了最后一次循环 使i==length
    else return i;
}
// 类似indexOf，从右边开始查找
int lastIndexOf(linearList *L, ElemType el){
    int i;
    for(i=L->length - 1; i >= 0 && L->data[i]!=el;--i){};
    return i;
}
bool slice(linearList *&L, int start, int end){
    if(start<0) start+=L->length; if(end<0) end+=L->length;
    if(start>end || end > L->length || start<0) return false;
    int temp, gap=end-start;
    for(temp=start;temp<end;temp++){ L->data[temp] = L->data[temp+gap];
    if(DEBUG) cout<<endl<<"Executed: 在"<<temp<<"位置删除元素 "<<L->data[temp]<<endl;}
    L->length -= gap;
    return true;
}
// 逆转线性表
bool reverse(linearList * &L){
    for(int i=0;i<(int)L->length/2;i++){
        swap(L->data[i],L->data[L->length-i-1]);
    }
}

#endif