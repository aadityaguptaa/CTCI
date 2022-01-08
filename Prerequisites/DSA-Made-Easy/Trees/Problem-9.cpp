#include<bits/stdc++.h>

using namespace std;

class BSTNode{
public:
    int data;
    BSTNode *left = nullptr;
    BSTNode *right = nullptr;
    BSTNode *parent = nullptr;
};

BSTNode *insert(BSTNode *root, int data){
    if(root == nullptr){
        root = new BSTNode();
        root -> data = data;
        root -> left = nullptr;
        root -> right = nullptr;
        root -> parent = nullptr;
    }else if(root -> data < data){
        root -> right = insert(root->right, data);
        root -> right -> parent = root;
    }else{
        root -> left = insert(root->left, data);
        root -> left -> parent = root;
    }

    return root;
}

BSTNode * deleteTree(BSTNode *root){
    if(root == nullptr){
        return nullptr;
    }else{
        deleteTree(root->left);
        deleteTree(root->right);
        root = nullptr;
    }

    return root;
}

void traverse(BSTNode *root){
    if(root == nullptr){
        return;
    }
    traverse(root->left);
    cout << root -> data << endl;
    traverse(root -> right);


}

int main(){

    BSTNode * root = nullptr;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);

    cout << "Before" << endl;
    traverse(root);

    root = deleteTree(root);

    cout << "After" << endl;
    traverse(root);

}