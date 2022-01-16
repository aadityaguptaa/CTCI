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
        root -> right = insert(root -> right, data);

    }else{
        root -> left = insert(root -> left, data);
    }

    return root;
}



bool isMirror(BSTNode *root1, BSTNode *root2){
    if(root1 == nullptr && root2 == nullptr){
        return true;
    }else if(root1 == nullptr){
        return false;
    }else if(root2 == nullptr){
        return false;
    }

    return isMirror(root1->right, root2->left) && isMirror(root1->left, root2->right);
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

int main(void){

}