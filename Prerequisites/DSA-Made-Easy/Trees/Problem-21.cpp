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

bool pathExists(BSTNode *root, int sum){
    if(root == nullptr){
        if(sum == 0){
            return true;
        }else{
            return false;
        }

    }
    if(sum == 0){
        return true;
    }
    if(sum < 0 ){
        return false;
    }


    return pathExists(root->left, sum - root->data) || pathExists(root->right, sum - root->data) ;



}

int main(void){

    BSTNode * root = nullptr;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 20);

    cout << pathExists(root, 70) << endl;



}