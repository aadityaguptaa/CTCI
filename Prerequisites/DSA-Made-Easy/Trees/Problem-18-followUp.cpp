//
// Created by rocko on 13-01-2022.
//

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
        root -> left = nullptr;
        root -> data = data;
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



int diameterOfTree(BSTNode *root, int *ptr){
    if(!root){
        return 0;
    }

    int lh = diameterOfTree(root->left, ptr);
    int rh = diameterOfTree(root->right, ptr);

    if(lh + rh > *ptr){
        *ptr = lh + rh;
    }
    return max(lh, rh) + 1;
}


int main(void){

    BSTNode * root1 = nullptr;
    root1 = insert(root1, 10);
    root1 = insert(root1, 15);
    root1 = insert(root1, 5);
    root1 = insert(root1, 25);
    root1 = insert(root1, 20);
    int ans = 0;
    diameterOfTree(root1, &ans);

    cout << ans << endl;

}