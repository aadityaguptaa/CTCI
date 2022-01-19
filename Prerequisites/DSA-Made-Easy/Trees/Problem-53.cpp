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

int maxInTheTree(BSTNode * root){
    static int maxi = INT16_MIN;

    if(root == nullptr){
        return 0;
    }

    if(root -> data > maxi){
        maxi = root -> data;
    }
    maxInTheTree(root -> left);
    maxInTheTree(root -> right);

    return maxi;
}


int minInTheTree(BSTNode * root){
    static int mini = INT16_MAX;

    if(root == nullptr){
        return 0;
    }

    if(root -> data < mini){
        mini = root -> data;
    }
    maxInTheTree(root -> left);
    maxInTheTree(root -> right);

    return mini;
}
bool isBinary(BSTNode *root){
    if(root == nullptr){
        return true;
    }

    if(root -> data < maxInTheTree(root->left) || root -> data > minInTheTree(root->right)) return false;

    return isBinary(root->left) && isBinary(root -> right);

}

int main(void){

}