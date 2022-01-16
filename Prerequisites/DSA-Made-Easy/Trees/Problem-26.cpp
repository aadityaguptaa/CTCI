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
        root -> right = insert(root -> right, data);

    }else{
        root -> left = insert(root -> left, data);
    }

    return root;
}

bool findPath(BSTNode *root, int data, vector<int> &arr){
    if(root == nullptr){
        return false;
    }

    arr.push_back(root->data);

    if(root -> data == data){
        return true;
    }

    if((root -> left && findPath(root->left, data, arr)) || (root -> right && findPath(root->right, data, arr))) return true;

    arr.pop_back();
    return false;

}

int LCA(int n1, int n2, vector<int> path1, vector<int> path2){
    int k;
    int n = min(path1.size(), path2.size());
    for(int i = 0; i < n; i++){
        if(path1[i] == path2[i]){
            k = path2[i];
        }else{
            break;
        }
    }

    return k;
}
int main(void){

    BSTNode * root = nullptr;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 20);

    vector<int> path1;
    vector<int> path2;

    findPath(root, 20, path1);
    findPath(root, 5, path2);

    int ans = LCA(20, 5, path1, path2);

    cout << ans << endl;
}