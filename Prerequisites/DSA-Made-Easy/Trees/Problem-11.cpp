#include <bits/stdc++.h>

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
    queue<BSTNode *> que;
    que.push(root);

    int height = 0;
    int nodeCount = 0;

    while(!que.empty()){
        height++;
        nodeCount = que.size();

        while (nodeCount--){
            BSTNode *temp = que.front();
            if(temp -> left){
                que.push(temp->left);
            }
            if(temp -> right){
                que.push(temp->right);
            }

            que.pop();
        }
    }

    return height;
}

int main(void){

    BSTNode * root = nullptr;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);

    cout << treeHeight(root) << endl;

}