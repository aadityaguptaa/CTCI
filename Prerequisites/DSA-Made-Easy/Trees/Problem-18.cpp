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
        root->data = data;
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

int maxi = INT16_MIN;

void diameter(BSTNode *root){

    if(root == nullptr) return;

    int lh = treeHeight(root -> left);
    int rh = treeHeight(root -> right);

    maxi = max(maxi, lh+rh);
    if(root -> left != nullptr){
        diameter(root -> left);
    }
    if(root -> right != nullptr){
        diameter(root -> right);
    }

}

int main(void ){

    BSTNode * root1 = nullptr;
    root1 = insert(root1, 10);
    root1 = insert(root1, 15);
    root1 = insert(root1, 5);
    root1 = insert(root1, 25);
    root1 = insert(root1, 20);

    diameter(root1);

    cout << maxi;

}