#pragma once
#ifndef LZYBASIC
#define LZYBASIC

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "sorts.h"
using namespace std;
/**
 * 一些简单常用的基础函数包装头文件
 * 提高效率
 **/

// 函数声明
void printToString();
void cutLine();

void printToString(char i[], bool newline=false){
    cout<<i;
    if(newline) cout<<endl;
}
void printToString(int i, bool newline=false){
    if(i==false)
        cout<<"false";
    else if(i==NULL){
		cout<<"NULL";
	}
	else
        cout<<"true";
    if(newline) cout<<endl;
}
void printToString(bool i, bool newline=false){
    if(i==false)
        cout<<"false";
    else if(i==NULL){
		cout<<"NULL";
	}
	else
        cout<<"true";
    if(newline) cout<<endl;
}
void cutLine(){
    cout<<endl<<"<-----------------------------------"<<endl<<"\t\tmore"<<endl<<" ----------------------------------->"<<endl<<endl;
}
void cutLine(const char msg[]){
    if(strlen(msg)>8)
        cout<<endl<<"<-----------------------------------"<<endl<<"\t"<<msg<<endl<<" ----------------------------------->"<<endl<<endl;
    else
        cout<<endl<<"<-----------------------------------"<<endl<<"\t\t"<<msg<<endl<<" ----------------------------------->"<<endl<<endl;
}
// 指针交换
int swap(int *a, int *b){
    int *temp = a;
    a = & *b;
    b = temp;
}
char swap(char *a, char *b){
    char *temp = a;
    a = & *b;
    b = temp;
}
// 引用实现
int swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
char swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}

/**
 * 函数模板，泛型编程，提高效率
 * 部分暂时还有问题	
*/
// template <size_t N>
// int arrayLength(int *(&array)[N]) // 利用模板传递参数 array是数组的引用
// {
//     int res = 0L;
//     for (size_t i = 0;i < N;i ++) {
//         res += array[i];
//     }
//     return res;
// }

// template <size_t N>
// int arrayLength(ElemType (&array)[N]) // 利用模板传递参数 array是数组的引用
// {
//     return N;
// }

template <typename T>
inline T const& Max (T const& a, T const& b) 
{ 
    return a < b ? b:a; 
};
template <typename T>
inline T const& lzytoString(T const& str, bool newline=false){
	if(str==NULL)
		cout<<"NULL";
	else if(str==false)
		cout<<"false";
	else if(str==true)
		cout<<"true";
	else cout<<str;
	if(newline) cout<<endl;
};

#endif
