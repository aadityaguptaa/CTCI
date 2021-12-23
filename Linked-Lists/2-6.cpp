#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next = nullptr;
};

int palindrome(struct Node *head){
    int length = 0;
    struct Node *temp = head;

    struct Node *head2 = nullptr;
    struct Node *temp2 = nullptr;

    while (temp != nullptr){
        struct Node *newNode = (struct Node *) malloc(sizeof (struct Node));
        newNode -> data = temp -> data;
        newNode -> next = nullptr;
        if(head2 == nullptr){
            head2 = newNode;
            temp2 = head2;
        }else{
            temp2 -> next = newNode;
            temp2 = newNode;
        }
        temp = temp -> next;
    }

    struct Node *prev = nullptr;
    struct Node *temp4 = nullptr;

    temp2 = head2 -> next;
    prev = head2;
    head2 ->next = nullptr;

    while (temp2 != nullptr){
        temp4 = temp2->next;
        if(temp4 == nullptr){
            temp2 -> next = prev;
            head2 = temp2;
            break;
        } else{
            temp2 -> next = prev;
            prev = temp2;
            temp2 = temp4;
        }

    }

    temp2 = head2;

    temp = head;
    while (temp != nullptr){
        if(temp -> data != temp2 -> data){
            return -1;
        }
        temp = temp -> next;
        temp2 = temp2 -> next;
    }


    return  1;


}

int main(void ){
    int n;
    cout << "Enter the number of elements in the linked list\n";

    cin >> n;

    struct Node *head = nullptr;
    struct Node *temp = nullptr;

    for(int i = 0; i < n; i++){
        struct Node *newNode = (struct Node *) malloc(sizeof (struct Node));
        int k;
        cout << "Enter Node " << i+1 << " data" << endl;
        cin >> k;
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
    int a = palindrome(head);

    if(a != 1){
        cout << "Not Palindrome" << endl;
    }else{
        cout << "Palindrome" << endl;
    }

}