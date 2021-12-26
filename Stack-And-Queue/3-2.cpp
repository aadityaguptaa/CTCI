#include<bits/stdc++.h>

//Algorithm
//When you push an element onto the stack, the element is given the current minimum (in this case, I used hash map)

//Disadvantage
//There's just one issue with this approach: if we have a large stack, we waste a lot of space by keeping track of the min for every single element.


using namespace std;

class Stack{

public:
    int top = -1;
    int arr[100];
    int n = 100;

    int min = INT_MAX;
    unordered_map<int, int> mp;

    int push(int data){
        if(top >= n-1){
            cout << "Stack Overflow" << endl;
            return -1;
        }else{
            top++;
            arr[top] = data;
            if(arr[top] < min){
                min = arr[top];
            }
            mp[top] = min;
        }
        return 1;
    }

    int pop(){
        if(isEmpty()){
            cout << "Empty Stack" << endl;
        }else{
            top--;
            min = mp[top];
        }
    }

    int peek(){
        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    int findMin(){
        if(!isEmpty()){
            return mp[top];
        }
    }
};

int main(void){
    Stack st = Stack();

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