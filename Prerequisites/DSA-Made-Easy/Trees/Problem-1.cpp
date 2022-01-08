#include<bits/stdc++.h>

using namespace std;

class BSTNode{
public:
    int data;
    BSTNode * left = nullptr;
    BSTNode * right = nullptr;
    BSTNode * parent = nullptr;
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
        root -> left = insert(root -> left, data);
        root -> left -> parent = root;
    }

    return  root;
}

int findMax(BSTNode *root){
    int max = INT_MIN;
    int root_data;
    if(root!= nullptr){
        root_data = root->data;
        int left = findMax(root->left);
        int right = findMax(root->right);
        if(left > right){
            max = left;
        } else{
            max = right;
        }
        if(root_data> max){
            max = root_data;
        }
    }
    return max;
}

int main(void){
     BSTNode * root = nullptr;
     root = insert(root, 10);
     root = insert(root, 15);
     root = insert(root, 5);
     root = insert(root, 25);
     root = insert(root, 20);

     cout << findMax(root);
}