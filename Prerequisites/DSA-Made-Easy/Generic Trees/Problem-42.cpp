#include <bits/stdc++.h>

using namespace std;

class GTNode{
public:
    int data;
    GTNode * firstChild = nullptr;
    GTNode * nextSibling = nullptr;
};

int siblingCount(GTNode *root){
    int count = 0;
    while(root){
        count++;
        root = root->nextSibling;
    }

    return count;
}

int main(void){

}