#include<bits/stdc++.h>

using namespace std;

class BSTNode{
public:
    int data;
    BSTNode *left = nullptr;
    BSTNode *right = nullptr;
    BSTNode *nextSibling = nullptr;
};

BSTNode *insert(BSTNode *root, char data){
    if(root == nullptr){
        root = new BSTNode();
        root -> data = data;
        root -> left = nullptr;
        root -> right = nullptr;
        root -> nextSibling = nullptr;
    }else if(root -> data < data){
        root -> right = insert(root->right, data);
    }else{
        root -> left = insert(root -> left, data);
    }

    return root;
}

int fillSiblings(BSTNode *root){
    queue<BSTNode *> que;
    que.push(root);

    while(!que.empty()){
        int n = que.size();

        for(int i = 0; i < n; i++){
            BSTNode *temp = que.front();
            que.pop();
            if(i != n-1) {
                temp -> nextSibling = que.front();
            }

            if(temp->left != nullptr){
                que.push(temp->left);
            }
            if(temp->right != nullptr){
                que.push(temp->right);
            }
        }
    }
}

void traverse(BSTNode *root){
    if(root == nullptr){
        return;
    }
    traverse(root->left);
    cout << "Left: " << root -> left << endl;
    cout << root -> data << endl;
    cout << "Right: " << root -> right << endl;
    cout << "Next Sibling: " << root -> nextSibling << endl;
    traverse(root -> right);


}

int main(void){

    BSTNode * root = nullptr;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 20);

    fillSiblings(root);
    traverse(root);


}