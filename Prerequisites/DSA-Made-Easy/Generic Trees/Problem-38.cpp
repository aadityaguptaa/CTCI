#include<bits/stdc++.h>

using namespace std;

class GTBode{
public:
    int data;
    GTBode *firstChild = nullptr;
    GTBode *next = nullptr;
};

int findSum(GTBode *root){
    if(root == nullptr) return 0;

    return root -> data + findSum(root -> firstChild) + findSum(root -> next);
}

int main(void){

}