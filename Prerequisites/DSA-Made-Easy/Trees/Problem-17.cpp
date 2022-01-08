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
        root->data = data;
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

bool compare(BSTNode *root1, BSTNode *root2){
    if(root1 == nullptr && root2 == nullptr) return true;
    if(root1 == nullptr || root2 == nullptr) return false;

    return (root2 -> data == root1 -> data) && compare(root2->left, root1->left) && compare(root1->right, root2->right);
}

int main(void){

    BSTNode * root1 = nullptr;
    root1 = insert(root1, 10);
    root1 = insert(root1, 15);
    root1 = insert(root1, 5);
    root1 = insert(root1, 25);
    root1 = insert(root1, 20);

    BSTNode * root2 = nullptr;
    root2 = insert(root2, 10);
    root2 = insert(root2, 15);
    root2 = insert(root2, 78);
    root2 = insert(root2, 25);
    root2 = insert(root2, 20);

    cout << compare(root2, root1) << endl;

}