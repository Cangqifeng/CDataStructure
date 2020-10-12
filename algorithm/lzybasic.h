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
int lzystrlen();
const char *toString(const char *i);
int swap();

// 抄来的菜单
void menu(){
	printf("********1.创建                        2.插入*********\n");
	printf("********3.删除                        4.查找*********\n");
	printf("********5.倒置                        6.数据置空*****\n");
	printf("********7.打印                        8.销毁*********\n");
	printf("********9.退出                       10.清屏*********\n");
}
const char *toString(const char *i){
    if(i==NULL){
		return "NULL";
	}
    return i;
}
const char *toString(long long i){
    if(i==NULL){
		return "NULL";
	}
}
const char *toString(int i){
    char buffer[11];
    const char *p=itoa(i,buffer,10);
    return p;
}
const char *toString(bool i){
    if(i==NULL)
		return "NULL";
    else if(i==false){
        return "false";
	}else{
        return "true";
    }
}
void printToString(char i[], bool newline=false){
    if(i==NULL){
		cout<<"NULL";
	}
    cout<<i;
    if(newline) cout<<endl;
}
void printToString(int i, bool newline=false){
    cout<<i;
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
int lzystrlen(const char *str, bool ZH_Count = true){
    int i = 0, count = 0;
    while ( str[count] != '\0'){
        i++;count++;
        if(ZH_Count && str[count]<0) count++;//只要小于0，说明是汉字，占用两个字节，后一个字节跳过，不统计
    }
    // cout<<"当前的：`"<<str<<"`长度为："<<i;
    return i;
}
void cutLine(){
    cout<<endl<<"<-----------------------------------"<<endl;
    for(int i=0;i<14;i++) cout<<" ";
    cout<<"more"<<endl<<" ----------------------------------->"<<endl<<endl;
}
// 中文字符算两个长度，最大长度32内还较为可观
void cutLine(const char msg[]){
    const int length = lzystrlen(msg,false);
    // if(length>8)
    cout<<endl<<"<-----------------------------------"<<endl<<"  "; // 满格34，先补充两格
    for(int i=0;i<(32-length)/2;i++) cout<<" ";    
    cout<<msg<<endl<<" ----------------------------------->"<<endl<<endl;
}
    // 示例及测试
    // cutLine("trytrytrytrytrytrytrytrytry"); // 英文字符算一个
    // cutLine("我要试试八个字的");  // 中文字符算两个，比较美观
    // cutLine("其实最多只能试十二个字的"); // 较可观的分割线
    // cutLine("但是中英文Mix的话Maybe不止12个字"); // 最长类输出了 最长32字符

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
