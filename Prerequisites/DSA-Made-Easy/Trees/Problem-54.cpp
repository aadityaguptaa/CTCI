#include<bits/stdc++.h>

using namespace std;

class BSTNode{
public:
    int data;
    BSTNode *left = nullptr;
    BSTNode *right = nullptr;
    BSTNode *nextSibling = nullptr;
};

BSTNode *insert(BSTNode *root, char data){
    if(root == nullptr){
        root = new BSTNode();
        root -> data = data;
        root -> left = nullptr;
        root -> right = nullptr;
        root -> nextSibling = nullptr;
    }else if(root -> data < data){
        root -> right = insert(root->right, data);
    }else{
        root -> left = insert(root -> left, data);
    }

    return root;
}

bool isBST(BSTNode *root, int min, int max){
    if(root == nullptr){
        return true;
    }

    return ( min < root->data) && (max > root->data) && isBST(root->left, min, root->data) && isBST(root -> right, root->data, max);
}

int main(void){
    BSTNode * root = nullptr;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 20);

    cout << isBST(root, INT16_MIN, INT16_MAX);
}