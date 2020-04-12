/***
 * @Author      : acmaker
 * @Date        : 2020-03-17 19:33:40
 * @LastEditTime: 2020-03-17 19:56:46
 * @FilePath    : \myCPlusPlusCode\DataStructure\MoocWork\derivitive.cpp
 * @Website     : http://csdn.acmaker.vip
 * @Description : 某一元多项式采用带头结点的单链表存储，编写算法求其导数。
 * 函数声明：void Derivative(PolyNode *PL)，参数为一元多项式的头指针，
 * 该多项式按照幂次递增的次序排列，结果仍为PL所指的链表。
 */

#include <bits/stdc++.h>
using namespace std;
#define rg register
#define sc scanf
#define pf printf
typedef long long ll;

class PloyNode {
public:
    long long coef;
    long long exp;
    PloyNode *next;
    PloyNode() {}
    ~PloyNode( ) { }
};

class LinkedList {
public:
    PloyNode *head;
    LinkedList( ) {
        head = new PloyNode();
        head->next = NULL;
    }
    ~LinkedList ( ) {
        delete head;
    }
    void setDerivative ( );
    void print ( );
};
void LinkedList::setDerivative ( ) {
    PloyNode *p = head->next; // 指向首元素结点
    for ( ; p!=NULL; p=p->next ) {
        p->coef *= p->exp;
        --p->exp;
    }
}
void LinkedList::print( ) {
    PloyNode *p = head->next; // 指向首元素结点
    if ( p==NULL ) return;
    cout << p->coef;
    cout << ( p->exp!=0 ? "x"+p->exp : "" );
    cout << ( p->next!=NULL ? " + " : "" );
    p = p->next;
    for ( ; p!=NULL; p=p->next ) {
        cout << p->coef;
        cout << ( p->exp!=0 ? "x"+p->exp : "" );
        cout << ( p->next!=NULL ? " + " : "" );
    }
}