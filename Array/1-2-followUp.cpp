//
// Created by rocko on 23-12-2021.
//

#include <bits/stdc++.h>

using namespace std;

int main(){
    string string1 = "god";
    string string2 = "dod";
    int flag=0;
    unordered_map<char,int>m;

    for(int i=0; i<string1.length(); i++){
        if(m[string1[i]]== NULL){
            m[string1[i]] = 1;
        }
        else{
            m[string1[i]]++;
        }
    }
    for(int i=0; i<string2.length(); i++){
        if(m[string2[i]]== NULL){
            m[string2[i]] = 1;
        }
        else{
            m[string2[i]]++;
        }
    }
    for(int i=0;i<string1.length(); i++){
        if(m[string1[i]] == m[string2[i]]){
            flag++;
        }
    }
    if(flag == string1.length()) {
        cout << "It is a permutation" << endl;
    }
    else{
        cout << "It is not a permutation" << endl;
    }
}