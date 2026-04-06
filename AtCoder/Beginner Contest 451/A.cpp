#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool e5 = false;

    if(s.length()%5 == 0){
        e5 = true;
    }

    if(e5){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}