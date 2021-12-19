#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next = nullptr;
};

int kthLast(int k, struct Node *head){
    struct Node *ptr1 = head;
    struct Node *ptr2 = head;

    for(int i = 1; i < k; i++){
        ptr2 = ptr2->next;
        if(ptr2 == nullptr){
            return -1;
        }
    }

    while (ptr2 -> next != nullptr){
        ptr2 = ptr2 -> next;
        ptr1 = ptr1 -> next;
    }

    return ptr1 -> data;
}

int main(void){
    int n;
    cout << "Enter the number of elements in the Linked List" << endl;
    cin >> n;

    struct Node *head = nullptr;
    struct Node *temp = nullptr;

    for(int i = 0; i < n; i++){
        cout << "Enter " << i+1 << " Node data" << endl;
        int k;
        cin >> k;
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode -> data = k;
        newNode -> next = nullptr;

        if(head == nullptr){
            head = newNode;
            temp = head;
        } else{
            temp -> next = newNode;
            temp = temp -> next;
        }
    }

    cout << "--------------Program to find Kth last value of a singly Linked List------------\n" << endl;
    cout << "Enter the value of k" << endl;

    int k;
    cin >> k;
    int ans = kthLast(k, head);
    cout << "The kth last value is: " << ans << endl;
}