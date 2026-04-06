#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        if(n <= 3){
            cout << n << endl;
        }
        else{
            int rest;
            rest = n%2;
            cout << rest << endl;
        }
    }
    return 0;
}