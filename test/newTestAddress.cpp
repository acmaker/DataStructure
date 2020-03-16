/*** 
 * @Author      : acmaker
 * @Date        : 2020-03-03 10:13:40
 * @LastEditTime: 2020-03-11 13:34:21
 * @FilePath    : \myCPlusPlusCode\DataStructure\test\newTestAddress.cpp
 * @Website     : http://csdn.acmaker.vip
 * @Description : 
 */



#include <bits/stdc++.h> 
using namespace std; 
#define rg register 
#define sc scanf 
#define pf printf 
typedef long long ll; 



int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

// 三种数据类型
    typedef struct {
        int one;
        char two;
        bool three;
    }TEST;
    TEST a = { 0, 'a', true };

    int b = 0;

    char c = 'a';
// 三种指针
    TEST* _a;
    _a = &a;

    int* _b;
    _b = &b;

    char* _c;
    _c = &c;

    cout << "Address of a: " << "\t" << &a << "\n" << "Address of _a:" << "\t" << _a << endl;
    cout << "Address of b: " << "\t" << &b << "\n" << "Address of _b:" << "\t" << _b << endl;
    cout << "Address of c: " << "\t" << &c << "\n" << "Address of _c:" << "\t" << _c << endl;




    return 0 ; 
} 

