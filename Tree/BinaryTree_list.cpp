/*** 
 * @Author      : acmaker
 * @Date        : 2020-04-10 21:24:42
 * @LastEditTime: 2020-04-11 12:10:09
 * @FilePath    : \myCPlusPlusCode\DataStructure\Tree\BinaryTree_list.cpp
 * @Website     : http://csdn.acmaker.vip
 * @Description : 
 */


#include <bits/stdc++.h> 
using namespace std; 
#define rg register 
#define sc scanf 
#define pf printf 
typedef long long ll; 

typedef char TreeElemType;
typedef struct Node {
    TreeElemType data;
    Node *l, *r;
}Node, *BinaryTree;
BinaryTree tree;

void CreateTree ( Node **nd ) {
    TreeElemType data;
    cin >> data;
    if ( data=='.' ) {
        nd = NULL;
        return;
    }
    (*nd) = new Node();
    (*nd)->data = data;
    CreateTree( &((*nd)->l) );
    CreateTree( &((*nd)->r) );
}


int main ( ) {  // freopen( "F:\\in\\.txt" , "r" , stdin ); 

    CreateTree( &tree );





    return 0 ; 
} 