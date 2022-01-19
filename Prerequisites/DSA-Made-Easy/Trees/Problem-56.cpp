#include<bits/stdc++.h>

using namespace std;

class BSTNode{
public:
    int data;
    BSTNode *left = nullptr;
    BSTNode *right = nullptr;
};

BSTNode *insert(BSTNode *root, char data){
    if(root == nullptr){
        root = new BSTNode();
        root -> data = data;
        root -> left = nullptr;
        root -> right = nullptr;
    }else if(root -> data < data){
        root -> right = insert(root->right, data);
    }else{
        root -> left = insert(root -> left, data);
    }

    return root;
}

BSTNode *BSTtoDLL(BSTNode *root){
    static BSTNode *head = nullptr;
    static BSTNode *tail = nullptr;

    if(root == nullptr){
        return nullptr;
    }

    BSTtoDLL(root -> left);

    if(head == nullptr){
        head = root;
        tail = root;
    }else{
        tail-> right = root;
        root -> left = tail;
        tail = root;
    }

    BSTtoDLL(root -> right);

    head -> left = tail;
    tail -> right = head;

    return head;

}

void DLLTraverse(BSTNode *root){
    BSTNode *head = root;
    BSTNode *temp = root->right;

    while(temp != head){
        cout << temp -> data << " ";
        temp = temp->right;
    }
}

int main(void){
    BSTNode * root = nullptr;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 20);

    root = BSTtoDLL(root);
    DLLTraverse(root);

}