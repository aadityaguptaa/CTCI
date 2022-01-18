#include <bits/stdc++.h>

using namespace std;

int height(vector<int> arr){
    int maxi = INT16_MIN;

    for(int i = 0; i < arr.size(); i++){
        int temp = i;
        int height = 0;
        while(arr[temp] != -1){
            temp = arr[temp];
            height++;
        }
        maxi = max(height, maxi);
    }

    return maxi;
}

int main(void){
    vector<int> inp = {-1, 0, 1, 6, 6, 0, 0, 2, 7};
    cout << height(inp);
}