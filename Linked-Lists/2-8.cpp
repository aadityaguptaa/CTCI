#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next = nullptr;
};

int detectLoop(struct Node *head){
    struct Node *temp = nullptr;

    struct Node *slowPointer = nullptr;
    struct Node *fastPointer = nullptr;

    slowPointer = head;
    fastPointer = head;

    temp = head;

    while(slowPointer != fastPointer || fastPointer == head){
        slowPointer = slowPointer-> next;
        fastPointer = fastPointer -> next ;
        fastPointer = fastPointer -> next ;
    }

    while(temp != slowPointer){
        temp = temp-> next;
        slowPointer = slowPointer->next;
    }

    return temp -> data;
}

int main(void){

    struct Node *head = nullptr;
    struct Node *temp = nullptr;

    int n;
    cout << "Enter the number of elements in Linked List\n";
    cin >> n;

    for(int i = 0; i < n; i++){

        struct Node *newNode = (struct Node *) malloc(sizeof (struct Node));
        newNode -> data = i;
        newNode -> next = nullptr;

        if(head == nullptr){
            head = newNode;
            temp = newNode;
        }else{
            temp -> next = newNode;
            temp = temp -> next;
        }


    }
    struct Node *temp2 = head -> next;
    temp -> next = temp2;

    int ans = detectLoop(head);
    cout << ans << endl;

}