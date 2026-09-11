#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;


    // 2
    // 00
    // 01
    // 10
    // 11

    // 3
    // 000
    // 001
    // 011
    // 010
    // 110
    // 100
    // 101
    // 111

    for (int i = 0; i < (1 << n); i++){   
        int g = i ^ (i >> 1);            
        for (int b = n - 1; b >= 0; b--)  
            cout << ((g >> b) & 1);
        cout << '\n';
    }

}