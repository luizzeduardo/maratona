#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int t;
    cin >> t;
    while(t--){ 

        int n;
        cin >> n;

        //nums >0
        int max = INT_MIN;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(max < a[i]){
                max = a[i];
            }
        }

        
        int menor = a[0];
        for (int i = 1; i < n; i++) {
            menor = gcd(menor, a[i]);
        }


        int total = max/menor;

        cout << total << endl;

    }

    return 0;
        
}