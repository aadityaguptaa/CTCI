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

int treeHeight(BSTNode *root){
    if(root == nullptr){
        return 0;
    }else{
        int left = treeHeight(root->left) ;
        int right = treeHeight(root -> right);
        if(left > right){
            return left+1;
        }else{
            return right+1;
        }
    }
}


int main(){

    BSTNode * root = nullptr;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);

    cout << treeHeight(root) << endl;
}