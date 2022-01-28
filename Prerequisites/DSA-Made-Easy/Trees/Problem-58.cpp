#include<bits/stdc++.h>

using namespace std;

class DLLNode{
public:
    int data;
    DLLNode *prev = nullptr;
    DLLNode *next = nullptr;
};


DLLNode *findMiddleNode(DLLNode *root){
    DLLNode *pnt1 = root;
    DLLNode *pnt2 = root;

    while (pnt2 != nullptr || pnt2 -> next != nullptr){
        pnt1 = pnt1 -> next;
        pnt2 = pnt2 -> next -> next;
    }

    return pnt1;

}

DLLNode *DLLtoBST(DLLNode *root){
    DLLNode *temp, *p, *q;
    if(root == nullptr || root -> next == nullptr){
        return root;
    }

    temp = findMiddleNode(root);
    p = root;

    while(p -> next != temp){
        p = p -> next;
    }
    p -> next = nullptr;
    q = temp -> next;

    temp -> prev = nullptr;
    temp -> next = nullptr;

    temp -> prev = DLLtoBST(root);
    temp -> next = DLLtoBST(q);

    return temp;


}

int main(void){

}