#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    int l;
    cin >> l;
    int r;
    cin >> r;
    

    if(t>l){
        cout << "Time Limit Exceeded" << endl;
    }
    else if(r == 0){
        cout << "Wrong Answer" << endl;
    }
    else{
        cout << "Accepted" << endl;
    }
}