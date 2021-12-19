//
// Created by rocko on 19-12-2021.
//

#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next = nullptr;
};

void removeMiddleElement(struct Node *element){

    struct Node *ptr = element;
    struct Node *prev = element;
    while (ptr -> next != nullptr){
        ptr -> data = ptr -> next -> data;
        prev = ptr;
        ptr = ptr -> next;
    }

    prev -> next = nullptr;
}

int main(void){
    int n;
    cout << "Enter the number of elements in the list\n";
    cin >> n;
    struct Node *head = nullptr;
    struct Node *temp = nullptr;

    for(int i = 0; i < n; i++){
        cout << "Enter the Node data" << endl;
        int k;
        cin >> k;
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode -> data = k;
        newNode -> next = nullptr;
        if(head == nullptr){
            head = newNode;
            temp = head;
        }else{
            temp -> next = newNode;
            temp = temp -> next;
        }


    }

    temp = head;
    while(temp != nullptr){
        cout << temp-> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;

    temp = head;
    temp = temp -> next -> next;
    removeMiddleElement(temp);
    temp = head;
    while(temp != nullptr){
        cout << temp-> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}