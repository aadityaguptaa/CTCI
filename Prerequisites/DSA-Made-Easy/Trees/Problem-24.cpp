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
        root -> right = insert(root -> right, data);
        root -> right -> parent = root;
    }else{
        root -> left = insert(root -> left, data);
        root -> left -> parent = root;
    }

    return root;
}

BSTNode *mirrorBinaryTree(BSTNode *root){
    if(root == nullptr){
        return nullptr;
    }

    BSTNode *left = mirrorBinaryTree(root -> left);
    BSTNode *right= mirrorBinaryTree(root -> right);

    root -> left = right;
    root -> right = left;

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



int main(void){

    BSTNode * root = nullptr;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 20);

    cout << "Before" << endl;
    traverse(root);

    root = mirrorBinaryTree(root);
    cout << "After" << endl;
    traverse(root);




}