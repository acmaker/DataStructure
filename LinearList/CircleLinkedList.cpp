/*** 
 * @Author      : acmaker
 * @Date        : 2020-03-16 09:42:12
 * @LastEditTime: 2020-03-16 10:22:15
 * @FilePath    : \myCPlusPlusCode\DataStructure\LinearList\CircleLinkedList.cpp
 * @Website     : http://csdn.acmaker.vip
 * @Description : 
 */


#include <bits/stdc++.h> 
#include "SingalLinkedList.cpp"
using namespace std; 
#define rg register 
#define sc scanf 
#define pf printf 
typedef long long ll; 

typedef char ElemType;
typedef struct CNode {
    ElemType data;
    CNode* next;
}CNode, *CircleLinkedList;

/*** 
 * @description: 传入两个单链表的表头, 合并为 循环链表
 * @param : 
 * @return: 
 */
CircleLinkedList merge_1 ( CircleLinkedList LA, CircleLinkedList LB ) {
    CNode *pa, *pb;
    while ( pa->next!=NULL ) pa->next;
    while ( pb->next!=NULL ) pb->next;
    pa->next = LB->next;
    free( LB );
    pb->next = LA;
    return LA;
}


/*** 
 * @description: 传入两个单链表的表尾, 合并为 循环链表
 * @param : 
 * @return: 
 */
CircleLinkedList merge_2 ( CircleLinkedList RA, CircleLinkedList RB ) {
    CNode *t = RA;
    RA->next = RB->next->next;
    free( RB->next );
    RB->next = t->next;
    return RB; // 返回新的表尾
}



int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    




    return 0 ; 
} 