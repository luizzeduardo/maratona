#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int mod = 1000000007;

int main(){
    int n;
    cin >> n;

    //max de dados q pode dar n é n
    vector<int> count(n+1);
    count[0] = 1;

    for(int i=0; i<n+1; i++){
        for(int dado = 1; dado<7; dado++){
            if((i-dado) >= 0){
                count[i] = (count[i-dado] + count[i])%mod ;
            }
        }
    }

    cout << count[n]<< endl;
}