#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *next = nullptr;
};

void removeDuplicates(struct node *head){
    struct node *temp = head;

    while(temp != nullptr){
        int d = temp->data;
        struct node *temp2 = temp->next;
        struct node *prev = temp;
        while (temp2 != nullptr){
            if(temp2 -> data == d){
                prev-> next = temp2->next;
                temp2 = temp2->next;
            } else{
                prev = temp2;
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
}

int main(void){
    int n;
    cout << "Enter the number of elements you want to insert\n";
    cin >> n;
    struct node *head = nullptr;
    struct node *temp = nullptr;

    for(int i = 0; i < n; i++){
        struct node *newNode = (struct node *) malloc(sizeof(struct node));
        cout << "Enter the data\n";
        newNode->next = nullptr;
        cin >> newNode->data;
        if(head == nullptr){
            head = newNode;
            temp = head;
        }else{
            temp-> next = newNode;
            temp = newNode;
        }
    }
    temp = head;
    while(temp != nullptr){
        cout << temp->data << " " ;
        temp = temp->next;
    }
    cout << "\n";
    removeDuplicates(head);
    temp = head;
    while(temp != nullptr){
        cout << temp->data << " " ;
        temp = temp->next;
    }
}