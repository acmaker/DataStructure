/*** 
 * @Author      : acmaker
 * @Date        : 2020-03-16 10:11:31
 * @LastEditTime: 2020-03-16 11:26:05
 * @FilePath    : \myCPlusPlusCode\DataStructure\LinearList\DoubleLinkedList.cpp
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

#define OK 1
#define Error 0

typedef char ElmeType;
typedef struct { 
    ElmeType data;
    DNode *prior, *next;
}DNode, *DoubleLinkedList;

int InsPrior ( DoubleLinkedList L, int pos, ElemType e ) {
    if ( pos<0 ) return ERROR;
    DNode *p = L->next;
    for ( long long i = 0; (p!=NULL)&&(i<pos); ++i ) {
        p = p->next;
    }
    if ( p==NULL ) {
        cout << "超出链表最大长度!" << endl;
        return ERROR;
    }
    DNode *s = (DNode*)malloc( sizeof(DNode) );
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s->next;
    return OK;
}

int Del ( DoubleLinkedList L, int pos, ElemType *e ) {
    if ( pos<0 ) return ERROR;
    DNode *p = L;
    for ( long long i = 0; (p!=NULL)&&(i<pos); ++i ) {
        p = p->next;
    }
    if ( p==NULL ) {
        cout << "超出链表最大长度!" << endl;
        return ERROR;
    }
    *e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free( p );
    return OK;
}

int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    




    return 0 ; 
} 