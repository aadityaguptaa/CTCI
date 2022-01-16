#include<bits/stdc++.h>

using namespace std;


class BSTNode{
public:
    int data;
    BSTNode *left = nullptr;
    BSTNode *right = nullptr;
};

BSTNode *insert(BSTNode *root, int data){
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

int printAnc(BSTNode *root, BSTNode *data){
    if(root == nullptr){
        return 0;
    }

    if((root -> left == data) || (root -> right == data) || printAnc(root->left, data) || printAnc(root->right, data)){
        cout << root -> data << " ";
        return 1;
    }

    return 0;
}

int main(void){

    BSTNode * root = nullptr;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 20);

    printAnc(root, root->right->right);
}