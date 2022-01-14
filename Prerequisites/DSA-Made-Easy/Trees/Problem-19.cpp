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

int maxLevelSum(BSTNode *root){
    queue<BSTNode *> que;
    que.push(root);

    int maxSum = INT16_MIN;

    while (!que.empty()){
        int num = que.size();
        int sumTemp = 0;
        for(int i = 0; i < num; i++){
            BSTNode *temp = que.front();
            que.pop();
            sumTemp+= temp->data;
            if(temp->left != nullptr){
                que.push(temp->left);
            }
            if(temp->right != nullptr){
                que.push(temp->right);
            }

        }

        if(sumTemp > maxSum){
            maxSum = sumTemp;
        }
    }

    return maxSum;
}

int main(){

    BSTNode * root1 = nullptr;
    root1 = insert(root1, 10);
    root1 = insert(root1, 15);
    root1 = insert(root1, 5);
    root1 = insert(root1, 25);
    root1 = insert(root1, 20);

    cout << maxLevelSum(root1) << endl;
}