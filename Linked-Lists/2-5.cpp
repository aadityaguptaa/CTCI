#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next = nullptr;
};

int addNumbers(struct Node *num1, struct Node *num2){
    int dec = 1;
    struct Node *temp1 = num1;
    struct Node *temp2 = num2;

    int ans = 0;

    while(temp1!= nullptr){
        ans += (temp1 -> data)*dec;
        dec *= 10;
        temp1 = temp1 -> next;
    }
    dec = 1;
    while(temp2!= nullptr){
        ans += (temp2 -> data)*dec;
        dec *= 10;
        temp2 = temp2 -> next;
    }

    return ans;
}

int main(void){
    cout << "Enter details about 1st number\n" << endl;
    int n;
    cout << "Enter digit count\n";
    cin >> n;

    struct Node *firstNumber = nullptr;
    struct Node *temp = nullptr;

    for(int i = 0; i < n; i++){
        cout << "Enter digit " << i+1 << endl;
        int k;
        cin >> k;

        struct Node *newNode = (struct Node *) malloc(sizeof (struct Node));
        newNode -> data = k;
        newNode -> next = nullptr;

        if(firstNumber == nullptr){
            firstNumber = newNode;
            temp = firstNumber;
        }else{
            temp-> next = newNode;
            temp = newNode;
        }
    }

    cout << "Enter details about 2nd number\n" << endl;
    cout << "Enter digit count\n";
    cin >> n;

    struct Node *secondNumber = nullptr;
    temp = nullptr;

    for(int i = 0; i < n; i++){
        cout << "Enter digit " << i+1 << endl;
        int k;
        cin >> k;

        struct Node *newNode = (struct Node *) malloc(sizeof (struct Node));
        newNode -> data = k;
        newNode -> next = nullptr;

        if(secondNumber == nullptr){
            secondNumber = newNode;
            temp = secondNumber;
        }else{
            temp-> next = newNode;
            temp = newNode;
        }
    }

    int ans = addNumbers(firstNumber, secondNumber);
    cout <<  " The Sum of the two numbers is\n";
    cout << ans << endl;
}