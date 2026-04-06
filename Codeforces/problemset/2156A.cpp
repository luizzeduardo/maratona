#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int eat=0;

        while(n>=3){
            int div = 0;
            div = n/3;
            n -= 2* div;
            eat+=div;
        }

        cout << eat << endl;
    }
}