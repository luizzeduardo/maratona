#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;

    //calcula fat --> impossivel pra n=10^9

    ll zeros = 0;
    ll fat = 1;
    for(ll i = 0; i<n; i++){
        fat *= (i+1);
        if(fat%10 == 0){
            fat/=10;
            zeros++;
        }
    }

    cout << zeros << endl;

    
}