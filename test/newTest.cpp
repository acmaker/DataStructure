/*** 
 * @Author      : acmaker
 * @Date        : 2020-02-27 20:43:03
 * @LastEditTime: 2020-02-27 22:04:38
 * @FilePath    : \myCPlusPlusCode\DataStruct\newTest.cpp
 * @Website     : http://csdn.acmaker.vip
 * @Description : 
 */
#include<bits/stdc++.h>
using namespace std;

int main ( ) {

int bg, sec;
    cin >> bg  >> sec;

    int hour_bg = bg/100,
        minutes_bg = bg%100,
        hour_ed = hour_bg+sec/60,
        minutes_ed = minutes_bg+sec%60;
    
    if( minutes_ed>=60 ) {
        minutes_ed -= 60;
        hour_ed ++;
    }

    if( minutes_ed<0 ) {
        minutes_ed += 60;
        hour_ed --;
    }

    if ( hour_ed>24 ) {
        hour_ed -= 24;
    }

    cout << hour_ed << minutes_ed << endl;






    return 0;
}

