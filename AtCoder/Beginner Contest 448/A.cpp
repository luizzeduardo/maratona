#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        if(num < x){
            x = num;
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
}