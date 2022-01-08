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

BSTNode *findMin(BSTNode *root){
    int min = INT_MAX;
    BSTNode *minNode = nullptr;
    queue<BSTNode *> que;
    que.push(root);
    while (!que.empty()){
        BSTNode *temp = que.front();
        que.pop();
        if(min > temp->data){
            min = temp->data;
            minNode = temp;
        }
        if(temp->left != nullptr){
            que.push(temp->left);
        }
        if(temp->right != nullptr){
            que.push(temp->right);
        }
    }
    return minNode;
}

BSTNode *deleteNode(BSTNode *root, int data){

    if(root == nullptr){
        return root;
    }


    if(root -> left == nullptr && root -> right == nullptr){
        delete root;
    }else if(root -> data < data){
        deleteNode(root -> right, data);
    }else if(root -> data > data){
        deleteNode(root -> left, data);
    }else{

        //Case1
        if(root -> left == nullptr && root -> right == nullptr){
            delete root;
        } else if(root -> left == nullptr){
            BSTNode *temp = root;
            root = root->right;
            delete temp;
        } else if(root -> right == nullptr){
            BSTNode *temp = root;
            root = root->left;
            delete temp;
        } else{
            BSTNode *temp = findMin(root ->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);

        }
    }
}

int main(void){


}