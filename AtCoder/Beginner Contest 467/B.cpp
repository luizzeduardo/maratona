#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    int n;
    cin >> n;
    int perda = 0;

    while(n--){
        int a, b;
        string s;
        cin >> a >> b >> s;

        if(s == "keep"){    
            perda += b - a;
        }
    }

    cout << perda << endl;
}