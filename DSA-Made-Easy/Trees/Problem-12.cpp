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

BSTNode * deepestNode(BSTNode *root){
    queue<BSTNode *> que;
    que.push(root);
    BSTNode *temp = nullptr;

    while(!que.empty()){
        temp = que.front();
        que.pop();

        if(temp->left != nullptr){
            que.push(temp -> left);
        }


        if(temp->right != nullptr){
            que.push(temp -> right);
        }
    }

    return temp;
}

int main(void){

    BSTNode * root = nullptr;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);

    cout << deepestNode(root)->data << endl;

}