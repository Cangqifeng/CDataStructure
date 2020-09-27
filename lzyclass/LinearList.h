#pragma once
#ifndef LINEARLIST
#define LINEARLIST

#include <iostream>
#include <stdlib.h>
#include "algorithm/lzybasic.h"

using namespace std;

#define MaxSize 50
typedef int ElemType;

// 构造数据结构 `linearList`
typedef struct{
    int length;
    ElemType elem[MaxSize];
} linearList;

/**
 * 暂且直接使用类实例
 * 未来改用类指针，可链式调用
 * */

class LinearList{
    private:
        // 调试模式：设为true以开启，调用方法时输出流程信息
        const bool DEBUG = false; // 定义类内的常量而不是宏以提高内聚性
        // const int MaxSize=50;
        void initList(){
            this->L = (linearList *) malloc(sizeof(linearList)); // 同 `new linearList;` 运算符 `new` 返回当前new出空间的结构的指针类型
            this->L->length = 0;
        }
      
    protected:
        linearList * L;
    public:
        // 构造函数
        LinearList(linearList * L=NULL, ElemType a[]=NULL, int n=0){
            this->initList(); // 自动初始化
            cout<<"调用了构造函数"<<endl;
            if(L!=NULL)
                this->L = L;
            if(a!=NULL){
                // cout<<"调用了数组初始化"<<endl;
                // for(int i=0;i<n;i++){
                //     this->L->elem[i]=a[i];
                //     cout<<a[i]<<endl;
                // }
                // this->createList(a);
                this->createList(a, 10);
            }
        }
        // 析构函数
        ~LinearList(){this->destroyList();}
        void createList( ElemType data[]){
            int i=0,k=0;
            if(sizeof(data)==0) return;
            cout<<"总数组长度是:"<<sizeof(data)<<"第二个是："<<sizeof(data[0])<<endl;
            while (i < (sizeof(data)/sizeof(data[0])) )
            {
                this->L->elem[k]=data[i];
                k++;i++;
            }
            this->L->length=k;
        }
        void createList( ElemType data[], int n){
            int i=0;
            while (i<n)
            {
                this->L->elem[i]=data[i];
                i++;
            }
            this->L->length=i;
        }
        void destroyList(){
            free(this->L);
        }
        bool listEmpty(){
            return this->L->length==0;
        }
        int listLength(){
            return this->L->length;
        }
        void printList(){
            for(int i=0;i<this->L->length;++i){
                cout<<"第"<<i+1<<"个元素是："<<this->L->elem[i]<<endl;
            }
        }
        bool getElem(int index, ElemType &el){
            if(index<0 || index>=this->L->length) return false;
            return el=this->L->elem[index] || true;
        }
        int locateElem( ElemType el){
            int i;
            for(i=0;i<this->L->length && this->L->elem[i]!=el;++i){};
            if(i >= this->L->length) return -1; // 未找到，执行了最后一次循环 使i==length
            else return i;
        }
        bool insertElem( int index, ElemType el){
            int temp;
            if(index<0 || index > this->L->length || this->L->length==MaxSize) return false; // 错误的引索、线性表已满的情况直接返回false
            for(temp = this->L->length; temp > index-1; temp--) this->L->elem[temp]=this->L->elem[temp-1]; // 将 index 位置之后的元素后一位
            this->L->elem[index] = el;
            // cout<<"插入成功"<<endl;
            return !!(this->L->length++);
            // return true;
        }
        bool deleteElem( int index){
            int temp;
            if(index<0 || index >= this->L->length) return false;
            for(temp=index;temp < this->L->length;temp++) this->L->elem[temp] = this->L->elem[temp+1];
            this->L->length--;
            return true;
        }
        bool deleteElem( int index, ElemType &el){
            int temp;
            if(index<0 || index >= this->L->length) return false;
            el=this->L->elem[index];
            for(temp=index;temp<this->L->length;temp++) this->L->elem[temp] = this->L->elem[temp+1];
            this->L->length--;
            return true;
        }
        /**
         * 附加增强方法
         *   - bool reverse(); 逆序表中元素
         *   - bool sort(); 排序表中的元素，暂只支持 ElemType 为 int 或 char 类型
         **/
        bool reverse(){
            if(this->L->length <= 0){
                if(DEBUG) cout<<"reverse操作终止：顺序表为空！";
                return false;
            }
            ElemType temp;
            for(int i=0;i<(int) this->L->length/2;i++){
                temp=this->L->elem[i];
                // 做交换
                this->L->elem[i]=this->L->elem[this->L->length - i - 1];
                this->L->elem[this->L->length - i - 1] = temp;
                // cout<<endl<<"第"<<i<<"次交换："<<endl;
            }
            if(DEBUG) cout<<"Executed: reverse()"<<endl;
            return true;
        }

        bool sort(){
            if(this->L->length <= 0){
                if(DEBUG) cout<<"reverse操作终止：顺序表为空！";
                return false;
            }
            // 来自algorithm的排序函数，暂时未写好
            bubblingSort(this->L->elem, this->L->length);
        }
        // 没什么实际作用 P40页教材例题
        bool partition(){
            int i=0,j=this->L->length - 1;
            ElemType pivot=this->L->elem[0];
            while (i<j)
            {
                while(i<j && this->L->elem[j] > pivot) j--;
                while(i<j && this->L->elem[i] <= pivot) i++;
                if(i<j) swap(this->L->elem[i], this->L->elem[j]);
            }
            swap(this->L->elem[0], this->L->elem[i]);
        }
};

#endif
