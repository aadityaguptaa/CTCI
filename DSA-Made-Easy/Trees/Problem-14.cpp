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

int noOfLeafNodes(BSTNode *root){

    queue<BSTNode *> que;
    que.push(root);
    int count = 0;

    while (!que.empty()){
        BSTNode *temp = que.front();
        que.pop();
        if(temp -> left == nullptr && temp -> right == nullptr){
            count++;
        }

        if(temp ->left != nullptr){
            que.push(temp->left);
        }

        if(temp ->right != nullptr){
            que.push(temp->right);
        }


    }

    return count;
}

int main(void){
    BSTNode * root = nullptr;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 20);

    cout << noOfLeafNodes(root);

}