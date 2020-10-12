#include <cstdio>
#include <cstdlib>
// #include <stdio.h>
// #include <windows.h>
// #include <iostream>

// #include "lzystructure/linearList.h"
// #include "lzystructure/linkList.h"
#include "lzystructure/linkList.h"
#include "algorithm/lzybasic.h"

using namespace std;

/**
 * 游乐场
*/
int main(){
    cutLine("Welcome:单链表游乐场");
    menu();
    int choice, length=0, initData[1024]={0};
    ElemType input=0,receive=0;
    linkNode *L;
	while(1){
		printf("\n请输入菜单序号：\n>>> ");
		scanf("%d", &choice);
		if (9 == choice) break;
		switch (choice){
            case 1:{
                cout<<"请输入要创建的单链表长度(>1)"<<endl<<">>> ";
                cin>>length;
                for(int i=0;i<length;i++){
                    cout<<"请输入第"<<i+1<<"个数据："<<endl<<">>> ";
                    cin>>initData[i];
                }
                if(createList(L,initData,length)) cout<<"创建成功！\n";
                break;
            }
            case 2:{
                cout<<"请输入要插入单链表的数据（整数）："<<endl<<">>> ";
                cin>>input;
                cout<<"请输入要插入数据引索（从0起计数）："<<endl<<">>> ";
                cin>>length;
                if(insertElem(L,length,input)) cout<<"插入数据成功！\n";
                break;
            }
            case 3:{
                cout<<"请输入要删除的数据的引索（从0起计数）："<<endl<<">>> ";
                cin>>input;
                if(deletElem(L,input,receive)) cout<<"删除数据`"<<receive<<"`成功！\n";
                break;
            }
            case 4:{
                cout<<"请输入要查找的数据的值（整数）："<<endl<<">>> ";
                cin>>input;
                length=locateElem(L,input);
                cout<<"数据`"<<input<<"`的引索为："<<length;
                break;
            }
            case 5:reverse(L); break;
            case 6:{
                if(slice(L,0,listLength(L))) cout<<"清空完成！\n"; break;
            }
            case 7:cout<<endl;printList(L,true); break;
            case 8:destroyList(L); cout<<"销毁完成\n"; break;
            case 9:system("exit"); break;
            case 10:{system("cls"); menu(); break;}
            default:printf("输入错误！！！\n");
		}
        cout<<endl;
	}    

    system("pause");
}

/**
 * 顺序表测试
*/
// int main(){
    // linearList * L;
    // // initList(L);
    // int a[]={1,2,3,4,5,6,7,8,9,0};
    // createList(L,a,10);
    // cout<<"是否是空：";
    // printToString(listEmpty(L),true);
    // // cout<<endl;
    // printList(L);
    // cutLine();
    // insertElem(L, 0, 666);
    // insertElem(L, 1, 2333);
    // cout<<"是否是空：";
    // printToString(listEmpty(L),true);
    // printList(L);
    // cutLine();
    // deleteElem(L,0);
    // deleteElem(L,0);
    // printList(L);
    // cutLine("切换fun函数：删除最大");
    // fun(L);
    // printList(L);
    // destroyList(L);
// }


/**
 * 链表示例
*/
// int main(){
//     linkNode *L;
//     // initList(L);

//     int a[]={1,2,3,4,5,6,7,8,9,0};
//     createList(L,a,10);
//     printList(L);
//     cout<<endl<<"链表的长度是"<<listLength(L)<<endl;
//     // 在头部插入元素
//     cout<<endl<<"在头部插入元素的执行结果：";
//     printToString(insertElem(L,0,666));
//     // 删除末尾元素
//     cout<<endl<<"删除末尾元素的结果：";
//     printToString(deletElem(L,-1));
//     cutLine("修改完成后：");
//     printList(L,true);

//     cout<<endl<<"值为7的元素位于引索："<<locateElem(L,7)<<endl;

//     cout<<"删除所有引索大于等于2的元素"<<endl;slice(L,2,listLength(L));
//     printList(L);

//     system("pause");
// };

