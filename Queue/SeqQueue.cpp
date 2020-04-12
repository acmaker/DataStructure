/*** 
 * @Author      : acmaker
 * @Date        : 2020-03-25 21:45:27
 * @LastEditTime: 2020-03-25 22:15:44
 * @FilePath    : \myCPlusPlusCode\DataStructure\Queue\SeqQueue.cpp
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

#define MAX_SIZE (int)(1e1)
typedef int ElemType;
typedef struct SeqQueue {
    ElemType e[MAX_SIZE];
    int _front, _rear;
    SeqQueue( );
    void init( );
    ElemType front ( );
    State pop ( );
    State push ( ElemType data );
    State empty ( );
}SeqQueue;
SeqQueue::SeqQueue ( ) {
    init();
}
void SeqQueue::init ( ) {
    _front = _rear = 0;
}
ElemType SeqQueue::front ( ) {
    return e[_front];
}
State SeqQueue::pop ( ) {
    if ( (_rear+1)%MAX_SIZE==_front ) return FALSE;
    _front = (_front+1)%MAX_SIZE;
    return TRUE;
}
State SeqQueue::push ( ElemType data ) {
    if ( (_rear+1)%MAX_SIZE==_front ) return FALSE;
    e[_rear] = data;
    _rear = (_rear+1)%MAX_SIZE;
    return TRUE;
}
State SeqQueue::empty ( ) {
    return ( (_rear+1)%MAX_SIZE==_front );
}

int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    SeqQueue Q;

    for ( int i = 0; i < 10; ++i ) Q.push( i );

    for ( int i = 0; i < 10; ++i ) 
        cout << Q.front() << endl,
        Q.pop();


    return 0 ; 
} 