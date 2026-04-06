#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
 
        bool square = true;
        if(a != b){
            square = false;
        }
 
        if(a != c){
            square = false;
        }
 
        if(a != d){
            square = false;
        }
 
        if(b != c){
            square = false;
        }
 
        if(b != d){
            square = false;
        }
 
        if(c != d){
            square = false;
        }
 
        if(square){
            cout << "YES" << endl;
        }
 
        else{
            cout << "NO" << endl;
        }
    }
}