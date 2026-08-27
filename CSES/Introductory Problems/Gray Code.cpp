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

    int ans = 000;
    for(int i=1; i<n; i++){
        ans = (i-1)^(i); 
        cout << ans << endl;
    }

}