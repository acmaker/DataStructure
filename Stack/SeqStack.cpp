/*** 
 * @Author      : acmaker
 * @Date        : 2020-03-22 10:31:14
 * @LastEditTime: 2020-03-22 13:38:59
 * @FilePath    : \myCPlusPlusCode\DataStructure\Stack\SeqStack.cpp
 * @Website     : http://csdn.acmaker.vip
 * @Description : 
 */


#include <bits/stdc++.h> 
using namespace std; 
#define rg register 
#define sc scanf 
#define pf printf 
typedef long long ll; 

#define State int
#define TRUE 1
#define FALSE 0

const int MAX_SIZE = 1e3+100;
typedef int ElemType;
typedef struct {
    ElemType data[MAX_SIZE];
    int _top;
    State init ( );
    ElemType top ( );
    State pop ( );
    State push ( int e );
    int size ( );
}SeqStack;

State SeqStack::init ( ) {
    _top = -1;
}
ElemType SeqStack::top ( ) {
    return data[_top];
}
State SeqStack::pop ( ) {
    if ( _top==-1 ) return FALSE;
    --_top;
    return TRUE;
}
State SeqStack::push ( int e ) {
    if ( _top==MAX_SIZE-1 ) return FALSE;
    data[++_top] = e;
    return TRUE;
}
int SeqStack::size( ) { 
    return _top+1;
}


int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    SeqStack S;
    
    S.init( );
    
    S.push( 1 );

    S.push( 2 );

    cout << S.size() << endl;



    return 0 ; 
} 