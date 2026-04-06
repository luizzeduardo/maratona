#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;

    // basta descobrir se existe um conjunto de 1 a n onde a soma é (n+1)*n/4

    ll total = (n+1)*n/2;

    if(total%2 == 1){
        cout << "NO" << endl;
    }

    else{
        cout << "YES" << endl;
        ll tam1 = 0;
        ll tam2 = 0;
        ll soma1 = 0;
        ll soma2 = 0;
        ll sonho = (n+1)*n/4;
        vector<ll> set1(n, 0);
        vector<ll> set2(n, 0);
        while(soma1 != sonho){
            for(ll i = n; i>0; i--){
                if((soma1 + i) <= sonho){
                    soma1+=i;
                    set1[i-1] = i;
                    tam1++;
                }
                else{
                    soma2+=i;
                    set2[i-1] = i;
                    tam2++;
                }
            }
        }

        cout << tam1 << endl;
        for(ll i=0;i<n;i++){
            if(set1[i] != 0){
                cout << set1[i] << " ";
            }
        }
        cout << endl;

        cout << tam2 << endl;
        for(ll i=0;i<n;i++){
            if(set2[i] != 0){
                cout << set2[i] << " ";
            }
        }
        cout << endl;
        
    }
}