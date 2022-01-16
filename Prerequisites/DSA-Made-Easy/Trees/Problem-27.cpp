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
        root -> left = nullptr;
        root -> right = nullptr;
    }else if(root -> data < data){
        root -> right = insert(root -> right, data);
    }else{
        root -> left = insert(root -> left, data);
    }

    return root;

}

int search(int inOrder[], int inOrderStart, int inOrderEnd, int data){
    for(int i = inOrderStart; i <= inOrderEnd; i++){
        if(inOrder[i] == data){
            return i;
        }
    }
}

BSTNode *constructTree(int preOrder[], int inOrder[], int inOrderStart, int inOrderEnd){
    static int preOrderIndex = 0;

    BSTNode *root = nullptr;
    if(inOrderStart > inOrderEnd) return nullptr;

    root = new BSTNode();

    root -> data = preOrder[preOrderIndex];
    preOrderIndex++;

    if(inOrderStart == inOrderEnd) return root;

    int inOrderIndex = search(inOrder, inOrderStart, inOrderEnd, root->data);

    root -> left = constructTree(preOrder, inOrder, inOrderStart, inOrderIndex-1);
    root -> right = constructTree(preOrder, inOrder, inOrderIndex+1, inOrderEnd);

    return root;

}

int main(void){

}