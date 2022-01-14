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

void findPaths(BSTNode *root, string path, vector<string> *paths){
    path += to_string(root->data);
    if(root -> left == nullptr && root -> right == nullptr){
        (*paths).push_back(path);
        return;
    }
    if(root -> left || root -> right) path += "->";
    if(root -> left != nullptr){
        findPaths(root -> left, path, paths);
    }
    if(root -> right != nullptr){
        findPaths(root -> right, path, paths);
    }
}


int main(void){

    BSTNode * root = nullptr;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 20);

    vector<string> paths;
    findPaths(root, "", &paths);

    for(int i = 0; i < paths.size(); i++){
        cout << paths[i] << endl;
    }

}