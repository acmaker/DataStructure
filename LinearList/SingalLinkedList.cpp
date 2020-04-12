/*** 
 * @Author      : acmaker
 * @Date        : 2020-03-10 11:33:03
 * @LastEditTime: 2020-03-17 19:26:32
 * @FilePath    : \myCPlusPlusCode\DataStructure\LinearList\SingalLinkedList.cpp
 * @Website     : http://csdn.acmaker.vip
 * @Description : 
 */



#include <bits/stdc++.h> 
using namespace std; 
#define rg register 
#define sc scanf 
#define pf printf 
typedef long long ll; 

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

// 线性表的链式存储结构
typedef char ElemType;
typedef struct Node {
    ElemType data;
    Node* next;
}Node, *LinkedList;
LinkedList L;

long long ListLength ( LinkedList L );
void InitList ( LinkedList *L );
void CreateFromHead ( LinkedList L );
void CreateFromTail ( LinkedList L );
Node* Get ( LinkedList L, long long pos );
Node* Locate ( LinkedList L, ElemType key );
int InsList ( LinkedList L, int pos, ElemType e );
int DelList ( LinkedList L, int pos, ElemType *e );
void DestroyList ( LinkedList L );
void reverseList ( LinkedList );


int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    InitList( &L );

    // CreateFromHead( L );

    CreateFromTail( L );

    cout << Get( L, 3 )->data << endl;

    cout << Get( L, 2 )->data << endl;

    cout <<  Locate( L, '3' ) << endl;

    cout << InsList( L, 1, '8' ) << endl;

    ElemType backup;
    cout << DelList( L, 1, &backup ) << endl;

    DestroyList( L );
    

    return 0 ; 
} 

// 代码实现.

/***
 * @description: 计算带头结点的单链表 长度
 * @param :
 * @return:
 */
long long ListLength ( LinkedList L ) {
    Node *p = L->next;
    long long i;
    for ( i = 0; p!=NULL; ++i ) {
        p = p->next;
    }
    return i;
}

/*** 
 * @description: 初始化头结点, 注意传递的参数是头指针!
 * @param : 
 * @return: 
 */
void InitList ( LinkedList *t ) { 
    *t = (LinkedList)malloc( sizeof(Node) );
    (*t)->next = NULL;
}

/*** 
 * @description: 头插法建表
 * @param : 
 * @return: 
 */
void CreateFromHead ( LinkedList L ) {
    Node *s;
    bool state = true; // false为输入结束
    ElemType input;
    while ( state ) {
        cin >> input;
        if ( input=='$' ) state = false;
        else {
            s = (Node*)malloc( sizeof(Node) );
            s->data = input;
            s->next = L->next;
            L->next = s;
        }
    }
}

/*** 
 * @description: 尾插法建表
 * @param : 
 * @return: 
 */
void CreateFromTail ( LinkedList L ) {
    Node *s, *r = L;
    bool state = true;
    ElemType input;
    while ( state ) {
        cin >> input;
        if ( input=='$' ) state = false, r->next = NULL;
        else {
            s = (Node*)malloc( sizeof(Node) );
            s->data = input;
            r->next = s;
            r = s;
        }
    }
}

/*** 
 * @description: 带头结点单链表查找第 i 个结点
 * @param : 
 * @return: 
 */
Node* Get ( LinkedList L, long long pos ) {
    Node* p = L;
    long long i = 0;
    for ( ; (p->next!=NULL)&&(i<pos); ++i ) {
        p = p->next;
    }
    return (i==pos ? p : NULL);
}

/*** 
 * @description: 带头结点的单链表 查找值为key的结点
 * @param : 
 * @return: 返回查找到的值的地址...貌似没啥用...
 */
Node* Locate ( LinkedList L, ElemType key ) {
    Node* p = L->next;
    for ( ; p!=NULL; p=p->next ) {
        if ( p->data==key ) break;
    }
    return p;
}

/*** 
 * @description: 带头结点的单链表 插入
 * @param : 
 * @return: 
 */
int InsList ( LinkedList L, int pos, ElemType e ) {
    if ( pos<=0 ) return ERROR;
    Node *pre = L;
    for ( long long i = 0; (pre!=NULL)&&(i<pos-1); ++i ) {
        pre = pre->next;
    }
    if ( pre==NULL ) {
        cout << "超出链表最大长度!" << endl;
        return ERROR;
    }
    Node *s = (Node*)malloc( sizeof(Node) );
    s->data = e;
    s->next = pre->next;
    pre->next = s;
    return OK;
}

/*** 
 * @description: 带头结点的单链表 删除一个元素
 * @param : 注意, ElemType参数需要传递引用!
 * @return: 
 */
int DelList ( LinkedList L, int pos, ElemType *e ) {
    if ( pos<0 ) return ERROR;
    Node *pre = L; // 注意删除的时候从头结点开始算
    for ( long long i = 0; (pre->next!=NULL)&&(i<pos-1); ++i ) {
        pre = pre->next;
    }
    if ( pre->next==NULL ) {
        cout << "超出链表最大长度!" << endl;
        return ERROR;
    }
    Node *t = pre->next;
    pre->next = t->next;
    *e = t->data;
    free(t);
    return OK;
}

/*** 
 * @description: 销毁单链表
 * @param : 
 * @return: 
 */
void DestroyList ( LinkedList L ) { 
    Node *p = L, *t;
    while ( p->next!=NULL ) { 
        t = p->next;
        free(p);
        p = t;
    }
}

/*** 
 * @description: 逆置单链表( 使用头插法 )
 * @param : 
 * @return: 
 */
void reverseList( LinkedList L ) {
    Node *p = L->next, *q;
    L->next = NULL;
    for ( ; p!=NULL; p=q ) {
        q = p->next;
        p->next = L->next;
        L->next = p;
    }
}
