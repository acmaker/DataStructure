/*** 
 * @Author      : acmaker
 * @Date        : 2020-04-07 09:32:53
 * @LastEditTime: 2020-04-10 21:15:46
 * @FilePath    : \myCPlusPlusCode\DataStructure\Matrix_And_GeneralizedList.cpp\Matrix.cpp
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
typedef struct Triple {
    int row, col;
    ElemType e;
}Triple;
const int MAX_SIZE = 1e3;
typedef struct TripleMatrix {
    int m, n, len;
    Triple triple[MAX_SIZE];
}TripleMatrix;

/*** 
 * @description: 列序递增法, 转置压缩矩阵
 * @param : 
 * @return: 
 */
State transformTripleMatrix ( TripleMatrix A, TripleMatrix *B ) {
    if ( A.len<=0 ) return FALSE;
    B->m = A.n;
    B->n = A.m;
    B->len = A.len;
    int k = 0;
    for ( int  j = 1; j < A.n; ++j ) {
        for ( int i = 1; i < A.len; ++i ) {
            if ( A.triple[i].col==i ) {
                B->triple[k].row = A.triple[i].col;
                B->triple[k].col = A.triple[i].row;
                B->triple[k].e = A.triple[i].e;
            }
        }
    }
    return TRUE;
}

/*** 
 * @description: 一次定位法, 转置压缩矩阵
 * @param : 
 * @return: 
 */
State transformTripleMatrix_rapidPosition ( TripleMatrix A, TripleMatrix *B ) {
    if ( A.len<=0 ) return FALSE;
    B->m = A.n;
    B->n = A.m;
    B->len=A.len;
    int *cnt = new int[A.n];
    memset( cnt, 0, sizeof(int)*(A.n+1) );
    for ( int i  = 1; i <= A.len; ++i ) ++cnt[A.triple[i].col];
    // for ( int i  = 1; i <= A.len; ++i ) ++*(cnt+i);
    int *pos = new int[A.n];
    pos[1] = 1;
    for ( int i = 2; i <= A.n; ++i ) pos[i] = pos[i-1]+cnt[i-1];
    // for ( int i = 2; i <= A.n; ++i ) *(pos+i) = *(pos+i-1)+*(cnt+i-1);
    for ( int i = 1; i <= A.len; ++i ) {
        int col = A.triple[i].col;
        int k = pos[col];
        // int k = *(pos+A.triple[i].col);
        B->triple[k].row = A.triple[i].col;
        B->triple[k].col = A.triple[i].row;
        B->triple[k].e = A.triple[i].e;
        ++pos[col];
    }
    return TRUE;
}

int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    TripleMatrix a, b;

    a.m = 4;
    a.n = 3;
    a.len = 4;
    a.triple[1].row = 1;
    a.triple[1].col = 1;
    a.triple[1].e = 1;

    a.triple[2].row = 2;
    a.triple[2].col = 2;
    a.triple[2].e = 2;

    a.triple[3].row = 3;
    a.triple[3].col = 3;
    a.triple[3].e = 3;

    a.triple[4].row = 4;
    a.triple[4].col = 3;
    a.triple[4].e = 4;

    cout << transformTripleMatrix_rapidPosition( a, &b ) << endl;

    return 0 ; 
} 