/*** 
 * @Author      : acmaker
 * @Date        : 2020-03-11 14:23:43
 * @LastEditTime: 2020-03-11 15:16:11
 * @FilePath    : \myCPlusPlusCode\DataStructure\MoocWork\SeqList_work.cpp
 * @Website     : http://csdn.acmaker.vip
 * @Description : 编写算法，从顺序表中删除自第i个元素开始的k个元素。若不够k个元素时，将i后面的元素全部删除。
 */


#include <bits/stdc++.h> 
using namespace std; 
#define rg register 
#define sc scanf 
#define pf printf 
typedef long long ll; 

#define MAXSIZE (int)(1e2+100)
typedef  long long ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int size;
}SeqList;
SeqList L;


int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    // 初始化线性表
    L.size = 0;

    // 构造数据
    for ( int i = 0; i < (int)(1e2); ++i ) {
        L.data[i] = rand();
        L.size++;
    }

    // 开始执行
    int pos, th;
    cin >> pos >> th;

    for ( int i =  pos+1; (i+th)<L.size; ++i ) {
        L.data[i] = L.data[i+th];
    }
    L.size -= th;

    // 输出
    for ( int i = 0; i < L.size; ++i ) {
        cout << "i:\t" << i << "Data: " << L.data[i] << endl;
    }






    return 0 ; 
} 