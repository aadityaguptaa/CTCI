#include<bits/stdc++.h>

using namespace std;

struct node {
	int data;
	struct node *next = nullptr;
};

struct node * removeDuplicate(struct node *head){
    unordered_map<int, int> mp;
    struct node *temp = head;
    struct node *prev = head;
    while(temp != NULL){
        if(mp[temp->data] == 1){
            prev->next = temp->next;
            temp = temp->next;
        }else{
            mp[(temp->data)] = 1;
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

int main() {
	int n;
	cout << "Enter the number of nodes: \n";
	cin >> n;
	struct node *head = nullptr;
	struct node *temp = nullptr;
	for (int i = 0; i < n; i++) {
		struct node *newNode;
		newNode = (struct node *)malloc(sizeof(struct node));
        newNode -> next = nullptr;
		int k;
		cout << "Enter Data: \n";
		cin >> k;
		newNode -> data = k;

		if (head == nullptr) {
			head = newNode;
			temp = head;
		} else {
			temp->next = newNode;
			temp = newNode;
		}
	}
	temp = head;

	while (temp != nullptr) {
		cout << temp -> data << " -> ";
		temp = temp-> next;
	}
    cout << endl;

    head = removeDuplicate(head);
    temp = head;

    while (temp != nullptr) {
        cout << temp -> data << " -> ";
        temp = temp-> next;
    }

}