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

BSTNode *LCA(BSTNode *root, int alpha, int beta){
    if(root == nullptr){
        return nullptr;
    }
    while(1){
        if(alpha < root -> data  && beta > root -> data){
            return root;
        }else{
            if(alpha < root ->data){
                root = root->left;
            }else{
                root = root -> right;
            }
        }
    }


}


int main(void){

}