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

pair<int, int> verticalSum(BSTNode *root, int hash, unordered_map<int, int> *mp){
    static int hashMax = INT16_MIN;
    static int hashMin = INT16_MAX;
    if(root == nullptr){
        return make_pair(hashMin,hashMax);
    }

    verticalSum(root->left, hash-1, mp);
    if(hashMax < hash) hashMax = hash;
    if(hashMin > hash) hashMin = hash;
    if((*mp)[hash]){
        (*mp)[hash] += root->data;
    }else{
        (*mp)[hash] = root->data;
    }
    verticalSum(root->right, hash+1, mp);

    return make_pair(hashMin,hashMax);

}

int main(void){

    BSTNode * root = nullptr;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 20);

    unordered_map<int, int> mp;
    pair<int, int> ans =  verticalSum(root, 0, &mp);

    for(int i = ans.first; i <= ans.second; i++){
        cout << mp[i] << " ";
    }

}