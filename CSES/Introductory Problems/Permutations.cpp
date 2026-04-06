#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    if(n>3 || n==1){
        for(int i=2; i<=n; i+=2){
            cout << i << " ";
        }
        for(int i=1; i<=n; i+=2){
            cout << i << " ";
        }
    }
    else{
        cout << "NO SOLUTION" << endl;
    }
}