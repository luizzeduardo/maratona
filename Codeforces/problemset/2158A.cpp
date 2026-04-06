#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int y, r;
        cin >> y >> r;

        int total = r + y/2;
        if(total>n){
            total = n;
        }
        cout << total << endl;
    }
}