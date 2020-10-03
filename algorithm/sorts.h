#pragma once
#ifndef LZYSORTS
#define LZYSORTS

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 * 排序函数 重载支持 int char 类型
 * 预计包含：冒泡排序、快速排序、插入排序、……
**/

// 冒泡排序优化版 边界区分
char* bubblingSort(char* unsort) {
	char templeChar = { 0 },
		sorting[1024] = { 0 };
	for (int i = 0;i < 1024;i++) {
		sorting[i] = *(unsort + i);
	}
	int control = 0,
		count=1,
		init = strlen(sorting)-1,
		judgeChar = 0,
		lastExchangeIndex = 0;//每一轮排序的最后，记录下最后一次元素交换的位置，那个位置也就是无序数列的边界，再往后就是有序区了
	for (int i = 0;i < strlen(sorting);++i) {
		bool isSorted = true;
		for (int j = 0;j < init ;++j) {
			if (sorting[j] >= sorting[j + 1]) {
				templeChar = sorting[j + 1];
				sorting[j + 1] = sorting[i];
				sorting[j] = templeChar;
				lastExchangeIndex = j;//记录下冒泡边界
				isSorted = false;
			}
			else
			{
				continue;
			}
			templeChar = {0};
		}
		if (isSorted){break;}
		init = lastExchangeIndex;
		//printf("正在进行第 %d 次冒泡！\n", count);
		//printf("现在的结果是: %s \n", sorting);
		count++;
	}
	cout << "排序完成！！！" << endl;
	for (int i = 0;i < strlen(sorting);i++) {
		*(unsort+i) = sorting[i];
	}	
	return unsort;
}
int* bubblingSort(int* unsort, int length) {
	int templeChar = { 0 },
		sorting[1024] = { 0 };
	for (int i = 0;i < length;i++) {
		sorting[i] = *(unsort + i);
	}
	int control = 0,
		count=1,
		init = sizeof(sorting)/sizeof(sorting[0])-1,
		judgeChar = 0,
		lastExchangeIndex = 0;//每一轮排序的最后，记录下最后一次元素交换的位置，那个位置也就是无序数列的边界，再往后就是有序区了
	for (int i = 0;i < sizeof(sorting)/sizeof(sorting[0]);++i) {
		bool isSorted = true;
		for (int j = 0;j < init ;++j) {
			if (sorting[j] >= sorting[j + 1]) {
				templeChar = sorting[j + 1];
				sorting[j + 1] = sorting[i];
				sorting[j] = templeChar;
				lastExchangeIndex = j;//记录下冒泡边界
				isSorted = false;
			}
			else
			{
				continue;
			}
			templeChar = {0};
		}
		if (isSorted){break;}
		init = lastExchangeIndex;
		//printf("正在进行第 %d 次冒泡！\n", count);
		//printf("现在的结果是: %s \n", sorting);
		count++;
	}
	cout << "排序完成！！！" << endl;
	for (int i = 0;i < length;i++) {
		*(unsort+i) = sorting[i];
	}	
	return unsort;
}

#endif
