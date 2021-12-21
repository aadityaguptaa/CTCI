#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next = nullptr;
};

struct Node * partition(int data, struct Node *head){
    struct Node *lessThan = nullptr;
    struct Node *moreThan = nullptr;
    struct Node *temp1 = nullptr;
    struct Node *temp2 = nullptr;
    struct Node *temp = head;

    while(temp != nullptr){
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode -> data = temp -> data;
        newNode -> next = nullptr;

        if(temp -> data < data){
            if(lessThan == nullptr){
                lessThan = newNode;
                temp1 = lessThan;
            } else{
                temp1 -> next = newNode;
                temp1 = newNode;
            }
        }else{
            if(moreThan == nullptr){
                moreThan = newNode;
                temp2 = moreThan;
            }else{
                temp2 -> next = newNode;
                temp2 = newNode;
            }
        }

        temp = temp -> next;
    }
    temp1 -> next = moreThan;
    return lessThan;


}

int main(){

    cout << "Enter the number of elements in the linked list\n";
    int n;
    cin >> n;

    struct Node *head = nullptr;
    struct Node *temp = nullptr;

    for(int i = 0; i < n; i++){
        cout << "Enter the Node data\n";
        int k;
        cin >> k;
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode -> data = k;
        newNode -> next = nullptr;
        if(head == nullptr){
            head = newNode;
            temp = head;
        }else{
            temp -> next = newNode;
            temp = newNode;
        }
    }

    cout << "Enter the element to do the transition\n";
    int number;
    cin >> number;

    cout << "Before\n";
    temp = head;
    while (temp != nullptr){
        cout << temp -> data << " -> ";
        temp = temp->next;
    }
    cout << endl;

    head = partition(number, head);
    temp = head;

    while (temp != nullptr){
        cout << temp -> data << " -> ";
        temp = temp->next;
    }
    cout << endl;


}