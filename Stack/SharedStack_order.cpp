/*** 
 * @Author      : acmaker
 * @Date        : 2020-03-22 14:11:34
 * @LastEditTime: 2020-03-22 14:45:23
 * @FilePath    : \myCPlusPlusCode\DataStructure\Stack\SharedStack_order.cpp
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

typedef int ElemType;
const int MAX_SIZE = 1e2+100;
typedef struct {
    ElemType data[MAX_SIZE];
    int _top[2];
    void init ( );
    ElemType top ( int i );
    State pop ( int i );
    State push ( int e, int i );
}SharedStack_order;

void SharedStack_order::init ( ) {
    _top[0] = -1;
    _top[1] = MAX_SIZE;
}
ElemType SharedStack_order::top ( int i ) {
    switch ( i ) {
        case 0: return data[_top[0]]; break;
        case 1: return data[_top[1]]; break;
        default: return -1;
    }
}
State SharedStack_order::pop ( int i ) {
    switch ( i ) {
        case 0: 
            if ( _top[0]==-1 ) return FALSE;
            --_top[0];
            return TRUE;
        case 1: 
            if ( _top[1]==MAX_SIZE ) return FALSE;
            ++_top[1];
        default: return FALSE;
    }
}
State SharedStack_order::push ( ElemType e, int i ) {
    switch ( i ) {
        case 0:
            if ( _top[0]+1==_top[1] ) return FALSE;
            data[++_top[0]] = e;
            return TRUE;
        case 1:
            if ( _top[1]-1==_top[0] ) return FALSE;
            data[--_top[1]] = e;
            return TRUE;
        default: return FALSE;
    }
}

int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    SharedStack_order S;

    S.init( );

    S.push( 111, 0 );

    S.push( 222, 0 );

    S.push( 111, 1 );

    S.push( 222, 1 );


    cout << S.top( 0 ) << endl;
    S.pop( 0 );

    cout << S.top( 1 ) << endl;
    S.pop( 1 );


    return 0 ; 
} 