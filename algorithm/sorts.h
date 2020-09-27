#pragma once
#ifndef SORTS
#define SORTS

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 * 排序函数 重载支持 int char 类型
 * 预计包含：冒泡排序、快速排序、插入排序、……
**/

// 冒泡排序优化版 边界区分 待实现
char* bubblingSort(char* unsort) {
	return unsort;
}
int* bubblingSort(int* unsort, int length) {
	return unsort;
}

#endif
