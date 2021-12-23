
// program to implement stack using one array.

#include<bits/stdc++.h>

using namespace std;

class Stack{
    int arr[100];
    int top1 = 0;
    int top2 = 1;
    int top3 = 2;
    int n = 100;

    void pushToStack1(int data){
        if(top1 > n - 1){
            cout << "Stack Overflow" << endl;
        }else{
            arr[top1] = data;
            top1+=3;
        }
    }

    void pushToStack2(int data){
        if(top2 > n - 1){
            cout << "Stack Overflow" << endl;
        }else{
            arr[top2] = data;
            top2+=3;
        }
    }
    void pushToStack3(int data){
        if(top3 > n - 1){
            cout << "Stack Overflow" << endl;
        }else{
            top3+=3;
            arr[top3] = data;
        }
    }
    void pop1(){
        if(top1 < 0){
            cout << "Stack Underflow" << endl;
        }else{
            top1-=3;
        }
    }

    void pop2(){
        if(top2 < 0){
            cout << "Stack Underflow" << endl;
        }else{
            top2-=3;
        }
    }

    void pop3(){
        if(top3 < 0){
            cout << "Stack Underflow" << endl;
        }else{
            top3-=3;
        }
    }

    int peek1(){
        if(top1 > n-1 || top1 < 0){
            cout << "Unable to get data" << endl;
        }else if(!isEmpty()){
            return arr[top1];
        }
    }


    int peek2(){
        if(top2 > n-1 || top2 < 0){
            cout << "Unable to get data" << endl;
        }else if(!isEmpty()){
            return arr[top2];
        }
    }


    int peek3(){
        if(top3 > n-1 || top3 < 0){
            cout << "Unable to get data" << endl;
        }else if(!isEmpty()){
            return arr[top3];
        }
    }

    bool isEmpty(){
        return top1 == -1;
    }
};

int main(void){

    Stack st1 = Stack();



}