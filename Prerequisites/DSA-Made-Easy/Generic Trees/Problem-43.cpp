#include<bits/stdc++.h>

using namespace std;

class GTNode{
public:
    int data;
    GTNode * firstChild;
    GTNode *nextSibling = nullptr;
};

bool isIsomorphic(GTNode * root1, GTNode *root2){
    if(!root2 && !root1){
        return true;
    }

    if((!root2 && root1) || (!root1 && root2)){
        return false;
    }

    return isIsomorphic(root2->firstChild, root1 -> firstChild) && isIsomorphic(root1 -> nextSibling, root2 -> nextSibling);
}

int main(void){

}