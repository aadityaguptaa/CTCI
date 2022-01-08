#include <bits/stdc++.h>

using namespace std;

bool palindrome(string input){
    if(input.size() == 0 || input.size() == 1){
        return true;
    }

    if(input[0] == input[input.size() -1]){
        return palindrome(input.substr(1, input.size()-2));
    }

    return false;
}

int main(void){

    string pal = "aabbbaaa";

    cout << palindrome(pal);
}