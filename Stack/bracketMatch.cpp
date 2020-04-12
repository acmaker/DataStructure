/*** 
 * @Author      : acmaker
 * @Date        : 2020-03-24 11:40:25
 * @LastEditTime: 2020-03-24 12:26:49
 * @FilePath    : \myCPlusPlusCode\DataStructure\Stack\bracketMatch.cpp
 * @Website     : http://csdn.acmaker.vip
 * @Description : 
 */


#include <bits/stdc++.h> 
using namespace std; 
#define rg register 
#define sc scanf 
#define pf printf 

#define State int
#define LEFT_UNNECESSARY -2
#define RIGHT_UNNECESSARY -1
#define TYPE_ERROR 0
#define OK 1

/*** 
 * @description: 栈实现括号匹配问题
 * @param : 
 * @return: 右括号多余返回-2, 做括号多余返回-1, 不匹配返回0, 匹配返回1
 */
State bracketMatch ( string str ) {
    stack<char> S;
    for ( auto e : str ) {
        switch ( e ) {
            case '{':
            case '[':
            case '(':
                S.push(e);
                break;
            case '}':
            case ']':
            case ')': { // 加花括号是为了限制 变量ch 的作用域
                if ( S.empty() ) return RIGHT_UNNECESSARY;
                char ch = S.top();
                if ( ch=='{'&&e=='}' || ch=='['&&e==']' || ch=='('&&e==')' ) {
                    S.pop();
                } else {
                    return TYPE_ERROR;
                }
            }
            default: break;
        }
    }
    return ( S.empty() ? OK : LEFT_UNNECESSARY );
}

int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    cout << bracketMatch( "{12[3(4)3]21}") << endl;

    cout << bracketMatch( "{12[3(43]21}") << endl;

    cout << bracketMatch( "{12[34)3]21}") << endl;

    cout << bracketMatch( "{12[34") << endl;

    cout << bracketMatch( "4)3]21}") << endl;



    return 0 ; 
} 