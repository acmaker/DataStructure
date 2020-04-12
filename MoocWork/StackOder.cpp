/***
 * @Author      : acmaker
 * @Date        : 2020-03-20 20:23:20
 * @LastEditTime: 2020-03-20 20:23:54
 * @FilePath    : \myCPlusPlusCode\DataStructure\MoocWork\StackOder.cpp
 * @Website     : http://csdn.acmaker.vip
 * @Description :
 */

#include <stack>
#include <bits/stdc++.h>
using namespace std;

bool Check(int stack_in[], int stack_out[] ) {
    int len_in = sizeof(stack_in) / sizeof(stack_in[0]),  //入栈序列长度
        len_out = sizeof(stack_out) / sizeof(stack_out[0]);  //出栈序列长度

    if ( len_in!=len_out ) return false;

    stack<int> s;
    for ( int i = 0, j = 0; i < len_in; ++i) {
        s.push(stack_in[i]);
        while (s.size() > 0 && s.top() == stack_out [j]) { //入栈序列栈顶元素与当前出栈序列元素不相等，不合法 
            s.pop();
            ++j;
        }
    }
    return (s.size() > 0 ? false : true);  //当所有出栈序列元素都匹配完之后，栈不为空，不合法
}

int main() {

    int stack_in[] = {1, 2, 3, 4, 5};                     //入栈序列
    int stack_out[] = {4, 5, 3, 2, 1};                    //出栈序列

    bool res = Check(stack_in, stack_out);

    cout << ( res ? "不合法!" : "合法" ) << endl;


    return 0;
}