#include <bits/stdc++.h>
using namespace std;

int  main(){
    int t;
    cin >> t;
    while(t--){
        int n, s, x;
        cin >> n >> s >> x;
        vector<int> a(n);
        int sum = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            sum += a[i];
        }

        bool possivel = true;

        if(sum > s){
            possivel = false;
        }

        int resto = sum - s;
        if(resto%x != 0){
            possivel = false;
        }

        if(possivel){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}