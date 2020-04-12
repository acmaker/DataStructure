/*** 
 * @Author      : acmaker
 * @Date        : 2020-03-25 18:06:32
 * @LastEditTime: 2020-03-25 19:27:15
 * @FilePath    : \myCPlusPlusCode\DataStructure\Queue\yangHuiTriangle_queue.cpp
 * @Website     : http://csdn.acmaker.vip
 * @Description : 
 */


#include <bits/stdc++.h> 
using namespace std; 
#define rg register 
#define sc scanf 
#define pf printf 
typedef long long ll; 

void yangHuiTriangle( int row ) {
    queue<int> Q;
    int sum = 0,
        temp;
    while ( !Q.empty() ) Q.pop();
    Q.push( 1 );
    for ( int i = 2; i <= row; ++i ) {
        Q.push( 1 );
        for ( int j = 1; j <= row-2; ++j ) {
            sum = Q.front();
            Q.pop();
            cout << sum << " ";
            temp = Q.front();
            sum += temp;
            Q.push( sum );
        }
        temp = Q.front();
        Q.pop();
        cout << temp << " " << endl;
        Q.push( 1 );
    }
    while ( !Q.empty() ) {
        cout << Q.front() << " ";
        Q.pop();
    }
}

int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    yangHuiTriangle( 10 );




    return 0 ; 
} 