#include <bits/stdc++.h>

using namespace std;

class BSTNode{
public:
    char data;
    BSTNode *left = nullptr;
    BSTNode *right = nullptr;
};

BSTNode *insert(BSTNode *root, char data){
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

BSTNode *constructTree(string inp){
    static int index = 0;

    BSTNode *root = new BSTNode();

    if(inp[index] == NULL){
        return nullptr;
    }
    root -> data = inp[index];
    root -> left = nullptr;
    root -> right = nullptr;

    if(inp[index] == 'L'){
        return root;
    }

    index++;
    root -> left = constructTree(inp);
    index++;
    root -> right = constructTree(inp);

    return root;
}

void traverse(BSTNode *root){
    if(root == nullptr){
        return;
    }
    traverse(root->left);
    cout << root -> data << endl;
    traverse(root -> right);


}


int main(void){
    string tree = "ILILL";

    BSTNode *root = constructTree(tree);

    traverse(root);

}