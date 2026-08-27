#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    int n;
    cin >> n;

    int mascara = n-1;
    int ans = 0;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if((i & mascara) == i){ // paridade
            ans ^= a;
        }
    }

    cout << ans << endl;

    // fj-1(p) xor fj-1(p+1) = fj(p)
}