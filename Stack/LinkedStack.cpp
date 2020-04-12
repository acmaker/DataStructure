/*** 
 * @Author      : acmaker
 * @Date        : 2020-03-23 15:30:12
 * @LastEditTime: 2020-03-24 09:36:13
 * @FilePath    : \myCPlusPlusCode\DataStructure\Stack\LinkedStack.cpp
 * @Website     : http://csdn.acmaker.vip
 * @Description : 
 */


#include <bits/stdc++.h> 
using namespace std; 
#define rg register 
#define sc scanf 
#define pf printf 
typedef long long ll; 

#define TRUE 1
#define FALSE 0
typedef int State;

typedef int ElemType;
typedef struct {
    ElemType data;
    LinkedStackNode* next;
}LinkedStackNode, *LinkedStack;

ElemType top ( LinkedStack S ) {
    return S->next->data;
}

State pop ( LinkedStack S, ElemType *e ) {
    if ( S->next==NULL ) return FALSE;
    LinkedStackNode *t = S->next;
    *e = t->data;
    S->next = t->next;
    free( t );
    return TRUE;
}

State push ( LinkedStack S, ElemType e ) {
    LinkedStackNode *t = new LinkedStackNode;
    if ( t==NULL ) return FALSE;
    t->data = e;
    t->next = S->next;
    S->next = t;
    return TRUE;
}

int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    




    return 0 ; 
} 