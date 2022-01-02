#include<bits/stdc++.h>

using namespace std;

class Stack3{
    int top;
    int arr[4];
    int n;
public:
    Stack3() {
        top = -1;
        n = 4;
    }
    bool push(int data){
        if(top >= n-1){
            return false;
        }else{
            top++;
            arr[top] = data;
        }
        return true;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        } else{
            return false;
        }
    }

    bool pop(){
        if(!isEmpty()){
            top--;
            return true;
        }else {
            return false;
        }
    }

    int peek(){
        if(!isEmpty()){
            return arr[top];
        }
    }
};

struct stackNode{
    class Stack3 stack;
    struct stackNode *next = nullptr;
    struct stackNode *prev = nullptr;

};

class SetOfStacks{

    struct stackNode *head = (struct stackNode *) malloc(sizeof (struct stackNode));
    struct stackNode *temp = head;

public:
    SetOfStacks(){
        head -> next = nullptr;
        head -> prev = nullptr;
    }


    void setPush(int data){
        bool p = temp->stack.push(data);
        if(!(p)){
            struct stackNode *newStack = (struct stackNode *) malloc(sizeof (struct stackNode));
            newStack -> prev = temp;
            newStack -> next = nullptr;
            temp->next = newStack;
            temp = temp->next;
            temp->stack.push(data);
        }
    }

    bool isSetEmpty(){
        return head->stack.isEmpty();
    }

    int setPop(){
        if(temp->stack.isEmpty() && temp->prev != nullptr){
            temp = temp -> prev;
        }
        int ret = temp->stack.pop();

        return ret;
    }

    int setPeek(){
        if(temp->stack.isEmpty() && temp->prev != nullptr){
            temp = temp->prev;
        }
        return temp->stack.peek();
    }

};


int main(void){

    SetOfStacks st = SetOfStacks();

    st.setPush(5);
    cout << st.setPeek() << endl;

    st.setPush(5);
    cout << st.setPeek() << endl;

    st.setPush(5);
    cout << st.setPeek() << endl;

    st.setPush(5);
    cout << st.setPeek() << endl;

    st.setPush(5);
    cout << st.setPeek() << endl;

    st.setPush(5);
    cout << st.setPeek() << endl;

    st.setPush(5);
    cout << st.setPeek() << endl;

    st.setPush(5);
    cout << st.setPeek() << endl;

    st.setPop();
    cout << st.setPeek() << endl;
    st.setPop();
    cout << st.setPeek() << endl;
    st.setPop();
    cout << st.setPeek() << endl;
    st.setPop();
    cout << st.setPeek() << endl;
    st.setPush(6);
    cout << st.setPeek() << endl;

    st.setPush(6);
    cout << st.setPeek() << endl;
    st.setPush(6);
    cout << st.setPeek() << endl;
    st.setPush(6);
    cout << st.setPeek() << endl;
    st.setPush(6);
    cout << st.setPeek() << endl;
}