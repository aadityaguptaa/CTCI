//
// Created by rocko on 23-12-2021.
//

#include <bits/stdc++.h>

using namespace std;

int main(){
    string string1 = "god";
    string string2 = "dod";
    int flag = 0;

    sort(string1.begin(), string1.end());
    sort(string2.begin(), string2.end());

    for(int i = 0; i<string2.length(); i++){
        if(string1[i]==string2[i]){
            flag++;
        }
    }
    if(flag == string2.length()){
        cout << "Is a permutation" << endl;
    }
    else{
        cout << "Is not a permutation" << endl;
    }

}