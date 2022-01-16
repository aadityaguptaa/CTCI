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
        root -> right = insert(root->right, data);
    }else{
        root -> left = insert(root -> left, data);
    }

    return root;
}

void ZigZagTraversal(BSTNode *root){
    int leftToRight = 1;

    stack<BSTNode *> stack1;
    stack<BSTNode *> stack2;

    stack1.push(root);

    while (!stack1.empty()){
        BSTNode *temp = stack1.top();
        stack1.pop();
        cout << temp -> data << " ";
        if(leftToRight){
            if(temp -> left != nullptr) stack2.push(temp->left);
            if(temp -> right != nullptr) stack2.push(temp->right);
        }else{
            if(temp -> right != nullptr) stack2.push(temp->right);
            if(temp -> left != nullptr) stack2.push(temp->left);
        }

        if(stack1.empty()){
            leftToRight = 1 - leftToRight;
            swap(stack1, stack2);
            cout << endl;
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

    ZigZagTraversal(root);
}