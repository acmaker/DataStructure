/*** 
 * @Author      : acmaker
 * @Date        : 2020-03-25 15:43:52
 * @LastEditTime: 2020-03-25 18:05:03
 * @FilePath    : \myCPlusPlusCode\DataStructure\Queue\LinkedQueue.cpp
 * @Website     : http://csdn.acmaker.vip
 * @Description : 
 */



#include <bits/stdc++.h> 
using namespace std; 
#define rg register 
#define sc scanf 
#define pf printf 
typedef long long ll; 

typedef int State;
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef struct LinkedQueueNode {
    ElemType data;
    LinkedQueueNode *next;
}LinkedQueueNode;
typedef struct LinkedQueue {
    LinkedQueueNode *front, *rear;
}LinkedQueue;

State initQueue( LinkedQueue *Q ) {
    Q->front = new LinkedQueueNode;
    if ( Q->front==NULL ) return FALSE;
    Q->rear = Q->front;
    Q->rear->next = NULL;
    return TRUE;
}

State push ( LinkedQueue *Q, ElemType x ) {
    LinkedQueueNode *t = new LinkedQueueNode;
    if ( t==NULL ) return FALSE;
    t->data = x;
    t->next = NULL;
    Q->rear->next = t;
    Q->rear = t;
    return TRUE;
}

State pop ( LinkedQueue *Q, ElemType *x ) {
    if ( Q->front==Q->rear ) return FALSE;
    LinkedQueueNode *t = Q->front->next;
    Q->front->next = t->next;
    *x = t->data;
    free( t );
    if ( Q->rear==t ) Q->rear = Q->front;
    return TRUE;
}

int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    LinkedQueue Q;

    initQueue( &Q );

    push( &Q, 1 );
    push( &Q, 2 );
    push( &Q, 3 );
    push( &Q, 4 );

    pop( &Q, new int );
    pop( &Q, new int );
    pop( &Q, new int );
    pop( &Q, new int );




    return 0 ; 
} 