#include <cstdio>
#include <cstdlib>
// #include <stdio.h>
// #include <windows.h>
// #include <iostream>

// #include "lzystructure/LinkList.h"
#include "lzystructure/linearList.h"
// #include "lzystructure/linkList.h"
#include "algorithm/lzybasic.h"

using namespace std;


// void fun(linearList *&L){
//     int i,j=0;
//     for( i=1;i<L->length;i++)
//         if(L->data[i]>L->data[j])
//             j=i;
//     for( i=j;i<L->length-1;i++)
//         L->data[i]=L->data[i+1];
//     L->length--;
// }

// void Union(linkNode *A,linkNode *B,linkNode *&C){
//     linkNode *p=A->next, *q=B->next; // 跳过头结点
//     int i=0;
//     while(p!=NULL && q!=NULL){
//         if(p->data < q->data){
//             insertElem(C,i,p->data);
//             p=p->next;
//         }else if(p->data > q->data){
//             insertElem(C,i,q->data);
//             q=q->next;
//         }else{
//             insertElem(C,i,q->data);
//             q=q->next; p=p->next;
//         }
//         i++;
//     }
//     while (p!=NULL && insertElem(C,i,p->data)){
//         p=p->next;
//         i++;
//     }
//     while (q!=NULL && insertElem(C,i,q->data)){
//         q=q->next;
//         i++;
//     }
// }
/**
 * 临时main
*/
// int main(){
    // ElemType A[]={1,2,5,6,7,8}, B[]={2,5,7,9,10};
    // linkNode *L1, *L2, *L3;
    // createList(L1,A,6);
    // createList(L2,B,5);
    // initList(L3); // 初始化空表
    // printList(L1,true);
    // printList(L2,true);
    // cutLine("执行集合合并:");
    // Union(L1,L2,L3);
    // cout<<endl<<"合并后的L3为：\n"; printList(L3,true);

//     printf("hello world\n");
//     printf("%s\n",toString(true));
//     char *a="非true";
//     // char *a=NULL;
//     printf("%s\n",toString(a));
//     printf("%s\n",toString(NULL));

//     cutLine();
//     printList(L3,true);
// }

/**
 * 游乐场 - 单链表
*/
// int main(){
//     cutLine("Welcome:单链表游乐场");
//     menu();
//     int choice, length=0, initData[1024]={0};
//     ElemType input=0,receive=0;
//     linkNode *L;
// 	while(1){
// 		printf("\n请输入菜单序号：\n>>> ");
// 		scanf("%d", &choice);
// 		if (9 == choice) break;
// 		switch (choice){
//             case 1:{
//                 cout<<"请输入要创建的单链表长度(>1)"<<endl<<">>> ";
//                 cin>>length;
//                 for(int i=0;i<length;i++){
//                     cout<<"请输入第"<<i+1<<"个数据："<<endl<<">>> ";
//                     cin>>initData[i];
//                 }
//                 if(createList(L,initData,length)) cout<<"创建成功！\n";
//                 break;
//             }
//             case 2:{
//                 cout<<"请输入要插入单链表的数据（整数）："<<endl<<">>> ";
//                 cin>>input;
//                 cout<<"请输入要插入数据引索（从0起计数）："<<endl<<">>> ";
//                 cin>>length;
//                 if(insertElem(L,length,input)) cout<<"插入数据成功！\n";
//                 break;
//             }
//             case 3:{
//                 cout<<"请输入要删除的数据的引索（从0起计数）："<<endl<<">>> ";
//                 cin>>input;
//                 if(deleteElem(L,input,receive)) cout<<"删除数据`"<<receive<<"`成功！\n";
//                 break;
//             }
//             case 4:{
//                 cout<<"请输入要查找的数据的值（整数）："<<endl<<">>> ";
//                 cin>>input;
//                 length=locateElem(L,input);
//                 cout<<"数据`"<<input<<"`的引索为："<<length;
//                 break;
//             }
//             case 5:reverse(L); break;
//             case 6:{
//                 if(slice(L,0,listLength(L))) cout<<"清空完成！\n"; break;
//             }
//             case 7:printList(L,true); break;
//             case 8:destroyList(L); cout<<"销毁完成\n"; break;
//             case 9:system("exit"); break;
//             case 10:{system("cls"); menu(); break;}
//             default:printf("输入错误！！！\n");
// 		}
//         cout<<endl;
// 	}    
//     system("pause");
// }

/**
 * 游乐场 - 线性表
*/
int main(){
    cutLine("Welcome:顺序表游乐场");
    menu();
    int choice, length=0, initData[1024]={0};
    ElemType input=0,receive=0;
    linearList *L;
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
                if(deleteElem(L,input,receive)) cout<<"删除数据`"<<receive<<"`成功！\n";
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
            case 7:printList(L,true); break;
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

