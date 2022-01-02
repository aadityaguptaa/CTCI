#include<bits/stdc++.h>

using namespace std;

class BSTNode{
public:
    int data;
    BSTNode *left = nullptr;
    BSTNode *right = nullptr;
    BSTNode *parent = nullptr;
};

BSTNode * insert(BSTNode *root, int data){

    if(root == nullptr){
        root = new BSTNode;
        root -> data = data;
        root -> left = nullptr;
        root -> right = nullptr;
        root -> parent = nullptr;
    }else if(root->data < data){
        root -> right = insert(root->right, data);
        root->right->parent = root;
    } else{
        root -> left = insert(root->left, data);
        root->left->parent = root;
    }

    return root;
}

void inOrder(BSTNode *node){
    if(node == nullptr){
        return;
    }
    inOrder(node->left);
    cout << node -> data << endl;
    inOrder(node->right);
}

void preOrder(BSTNode *node){
    if(node == nullptr){
        return;
    }
    cout << node -> data << endl;
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(BSTNode *node){
    if(node == nullptr){
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout << node -> data << endl;

}

int main(void){

    BSTNode *root = nullptr;

    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);

    inOrder(root);
}