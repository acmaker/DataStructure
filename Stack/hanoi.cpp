/*** 
 * @Author      : acmaker
 * @Date        : 2020-03-25 11:52:02
 * @LastEditTime: 2020-03-25 12:52:01
 * @FilePath    : \myCPlusPlusCode\DataStructure\Stack\hanoi.cpp
 * @Website     : http://csdn.acmaker.vip
 * @Description : 
 */


#include <bits/stdc++.h> 
using namespace std; 
#define rg register 
#define sc scanf 
#define pf printf 
typedef long long ll; 

int cnt = 0;

void move ( int num, char start, char end ) {
    ++cnt;
    pf( "第%d次, 将%d号圆盘 : %c -> %c\n", cnt, num, start, end );
}

/*** 
 * @description: 从 start 移到 end, 以 temp 为辅助
 * @param : num为需要移动的盘子编号
 * @return: 
 */
void hanoi ( int num, char start, char end, char temp ) {
    if ( num==1 ) {
        move( 1, start, end ); // 将编号为 1 的圆盘移到终点end
        return;
    }
    hanoi( num-1, start, temp, end ); // 将编号为 n-1 的圆盘移到temp, 以end为辅助
    move( num, start, end ); // 将编号为 num 的圆盘移动到end
    hanoi( num-1, temp, end, start ); // 将编号为 n-1 的圆盘移到end, 以start为辅助
}

int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    hanoi( 3, 'A', 'C', 'B' );




    return 0 ; 
} 