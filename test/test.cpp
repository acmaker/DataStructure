/**
 * author: dzs
 * date: 2019年12月17日20:18:12
 * effect: test
 */
#include <bits/stdc++.h> 
using namespace std; 
#define rg register 
#define sc scanf 
#define pf printf 
typedef long long ll; 



/**
 * @description: 
 * @param : 
 * @return: 
 */
int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    int* arr = new int[10]( );

    // for( int* it = arr; it != NULL; ++it ) {
    //     cout << *it << endl;
    // }

    auto test = [=]( int* arr ) {
        // for ( int i = 0; i < 10; ++i ) {
        //     if ( (i+1)%5==0 ) *(arr+i) = 999;
        //     cout << *(arr+i) << " ";
        // } 
        for ( int i = 0; i < 10; ++i ) {
            if ( (i+1)%5==0 ) arr[i] = 999;
            cout << arr[i] << " ";
        }
    };

    test( arr ); 
    cout << endl;

    for ( int i = 0; i < 10; ++i ) {
        // if ( (i+1)%5==0 ) *(arr+i) = 999;
        cout << *(arr+i) << " ";
    }





    return 0 ; 
} 
