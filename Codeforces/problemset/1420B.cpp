#include <bits/stdc++.h>
using namespace std;

int mian(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(__lg(a[i]) && __lg(a[j]) >= __lg(a[i]) + __lg(a[j])){// mais significativo de a[] já serve
                    
                } 

            }
        }
    }
}