#pragma once
#ifndef LINEARLIST
#define LINEARLIST

#include <iostream>
#include <stdlib.h>
#include "../algorithm/lzybasic.h"

using namespace std;

#define MaxSize 50
// 定义标准类型
typedef int ElemType;
const ElemType NOTFOUND=-1;

// 构造数据结构 `linearList` !!!小写开头
typedef struct{
    int length;
    ElemType data[MaxSize];
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
        LinearList * initList(){
            this->L = (linearList *) malloc(sizeof(linearList)); // 同 `new linearList;` 运算符 `new` 返回当前new出空间的结构的指针类型
            this->L->length = 0;
            return this;
        }
      
    protected:
        linearList * L;
    public:
        // 构造函数
        LinearList(ElemType a[]=NULL, int n=0, linearList * L=NULL){
            if(DEBUG) cout<<"调用了构造函数"<<endl;
            if(L!=NULL)
                this->L = L;
            else this->initList(); // 自动初始化
            if(a!=NULL){
                this->createList(a, n);
            }
        }
        // 析构函数
        ~LinearList(){this->destroyList();}
        LinearList * createList( ElemType data[], int length){
            int i=0;
            while (i<length)
            {
                this->L->data[i]=data[i];
                i++;
            }
            this->L->length=i;
            return this;
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
        LinearList * printList(bool inlinePrint=false){
            for(int i=0;i<this->L->length;++i){
                if(inlinePrint) cout<<this->L->data[i]<<"  ";
                else cout<<endl<<"第"<<i+1<<"个元素是："<<this->L->data[i];
            }
            cout<<endl;
            return this;
        }
        LinearList * getElem(int index, ElemType &el){
            if(index<0) index+=this->L->length;
            if(index<0 || index>=this->L->length) return NULL;
            el=this->L->data[index];
            return this;
        }
        ElemType getElem(int index){
            if(index<0) index+=this->L->length;
            if(index<0 || index>=this->L->length) return NOTFOUND;
            return this->L->data[index];
        }
        int locateElem(const ElemType el){
            int i;
            for(i=0;i<this->L->length && this->L->data[i]!=el;++i){};
            if(i >= this->L->length) return -1; // 未找到，执行了最后一次循环 使i==length
            else return i;
        }
        // 同locateElem，从左查找的方法
        int indexOf(const ElemType el){
            int i;
            for(i=0;i<this->L->length && this->L->data[i]!=el;++i){};
            if(i >= this->L->length) return -1; // 未找到，执行了最后一次循环 使i==length
            else return i;
        }
        // 类似indexOf，从右边开始查找
        int lastIndexOf(ElemType el){
            int i;
            for(i=this->L->length - 1; i >= 0 && this->L->data[i]!=el;--i){};
            return i;
        }
        LinearList * insertElem(int index, ElemType el){
            int temp;
            if(index<0 || index > this->L->length || this->L->length==MaxSize) return NULL; // 错误的引索、线性表已满的情况直接返回false
            for(temp = this->L->length; temp > index-1; temp--) this->L->data[temp]=this->L->data[temp-1]; // 将 index 位置之后的元素后一位
            this->L->data[index] = el;
            this->L->length++;
            if(DEBUG) cout<<endl<<"Executed: 在"<<index<<"位置插入元素 "<<el<<endl;
            // return !!(this->L->length++);
            return this;
        }
        // 删除元素，允许负引索
        LinearList * deleteElem(int index){
            if(index<0) index+=this->L->length;
            int temp;
            if(index<0 || index >= this->L->length) return NULL;
            for(temp=index;temp < this->L->length-1;temp++) this->L->data[temp] = this->L->data[temp+1];
            if(DEBUG) cout<<endl<<"Executed: 在"<<index<<"位置删除元素 "<<this->L->data[index]<<endl;
            this->L->length--;
            return this;
        }
        bool deleteElem(int index, ElemType &el){
            if(index<0) index+=this->L->length;
            int temp;
            if(index<0 || index >= this->L->length) return false;
            el=this->L->data[index];
            for(temp=index;temp<this->L->length-1;temp++) this->L->data[temp] = this->L->data[temp+1];
            if(DEBUG) cout<<endl<<"Executed: 在"<<index<<"位置删除元素 "<<this->L->data[index]<<endl;
            this->L->length--;
            return true;
        }
        /**
         * 附加增强方法
         *   - bool reverse(); 逆序表中元素
         *   - bool sort(); 排序表中的元素，暂只支持 ElemType 为 int 或 char 类型
         *   - bool slice(); 删除从start 到 end（不包括end） 引索位置的元素
         **/
        LinearList* reverse(){
            if(this->L->length <= 0){
                if(DEBUG) cout<<endl<<"reverse操作终止：顺序表为空！";
                return NULL;
            }
            ElemType temp;
            for(int i=0;i<(int) this->L->length/2;i++){
                temp=this->L->data[i];
                // 做交换
                this->L->data[i]=this->L->data[this->L->length - i - 1];
                this->L->data[this->L->length - i - 1] = temp;
                // cout<<endl<<"第"<<i<<"次交换："<<endl;
            }
            if(DEBUG) cout<<endl<<"Executed: reverse"<<endl;
            return this;
        }

        bool sort(){
            if(this->L->length <= 0){
                if(DEBUG) cout<<"reverse操作终止：顺序表为空！";
                return false;
            }
            // 来自algorithm的排序函数，暂时未写好
            bubblingSort(this->L->data, this->L->length);
        }
        // 从start切片线性表到end(不包含该元素)，从允许负引索
        LinearList* slice(int start, int end){
            if(start<0) start+=this->L->length; if(end<0) end+=this->L->length;
            if(start>end || end >= this->L->length || start<0) return NULL;
            int temp, gap=end-start;
            for(temp=start;temp<end;temp++){ this->L->data[temp] = this->L->data[temp+gap];
            if(DEBUG) cout<<endl<<"Executed: 在"<<temp<<"位置删除元素 "<<this->L->data[temp]<<endl;}
            this->L->length -= gap;
            return this;
        }

        // 没什么实际作用 P40页教材例题
        LinearList * partition(){
            int i=0,j=this->L->length - 1;
            ElemType pivot=this->L->data[0];
            while (i<j)
            {
                while(i<j && this->L->data[j] > pivot) j--;
                while(i<j && this->L->data[i] <= pivot) i++;
                if(i<j) swap(this->L->data[i], this->L->data[j]);
            }
            swap(this->L->data[0], this->L->data[i]);
            return this;
        };
        // 练习中需要使用的到的函数都放在这里声明，到类外面去实现 ::
        void deleteSame();
        void ordInsert(const ElemType e);
};

#endif
