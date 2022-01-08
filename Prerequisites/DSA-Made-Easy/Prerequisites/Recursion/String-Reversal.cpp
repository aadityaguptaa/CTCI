#include<bits/stdc++.h>

using namespace std;

string reverseString(string input){

    if(input == ""){
        return "";
    }

    return reverseString(input.substr(1)) + input[0];
}

int main(){

    string input = "Hello Motherfucker";
    cout << reverseString(input);
}