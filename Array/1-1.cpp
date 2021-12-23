#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n = 10;
    string inp = "qwertyuiqo";

    unordered_map<int, char> mp;

    sort(inp.begin(), inp.end());

    for(int i = 0; i < inp.size()-1; i++){
        if(inp[i] == inp[i+1]){
            cout << "Duplicate";
            return 0;
        }
    }
    cout << "unique" << endl;
}