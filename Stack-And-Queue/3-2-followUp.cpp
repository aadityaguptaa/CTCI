#include<bits/stdc++.h>

using namespace std;

class Stack{
    int top = -1;
    int arr[100];
    int n = 100;
public:
    bool push(int data){
        if(top > n-1){
            cout << "Stack Overflow" << endl;
            return false;
        }else{
            top++;
            arr[top] = data;
        }
        return true;
    }

    int peek(){
        if(isEmpty()){
            cout << "stack is empty" << endl;
        }else{
            return arr[top];
        }
    }

    int pop(){
        if(isEmpty()){
            cout << "stack underflow" << endl;
            return -1;
        }else{
            top--;
        }
        return 1;
    }

    bool isEmpty(){
        return top == -1;
    }

};

class StackWithMin{
    Stack minStack = Stack();
    int min = INT16_MAX;
    Stack normalStack = Stack();
public:
    int pop(){
        if(normalStack.peek() == min){
            minStack.pop();
            min = minStack.peek();
        }
        return normalStack.pop();
    }

    int findMin(){
        return minStack.peek();
    }

    bool push(int data){
        if(normalStack.push(data)){
            if(data < min){
                min = data;
                minStack.push(min);
            }
            return true;
        }else{ return false;}
    }
};

int main(void){

    StackWithMin st = StackWithMin();

    st.push(5);
    cout << st.findMin() << endl;



    st.push(6);
    cout << st.findMin() << endl;

    st.push(3);
    cout << st.findMin() << endl;

    st.push(7);
    cout << st.findMin() << endl;

    st.pop();
    cout << st.findMin() << endl;

    st.pop();
    cout << st.findMin() << endl;

}