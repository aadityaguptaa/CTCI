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
    }else if(root->data < data){
        root -> right = insert(root->right, data);
        root->right->parent = root;
    }else{
        root -> left = insert(root->left, data);
        root->left->parent = root;
    }

    return root;
}

bool search(BSTNode *root, int data){
    int temp;
    if(root == nullptr){
        return false;
    }
    else{
        if(root->data == data){
            return true;
        }
        temp = search(root->left, data);
        if(temp == 1){
            return temp;
        }else{
            return search(root->right, data);
        }
    }
}
int main(void){

    BSTNode * root = nullptr;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 20);

    cout << search(root, 20) << endl;

}