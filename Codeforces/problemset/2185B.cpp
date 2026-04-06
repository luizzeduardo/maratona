#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }


        int maior = a[0];
        for(int i=0; i<n; i++){
            if(maior < a[i]){
                maior = a[i];
            }
        }
        int total =  maior*n;

        
        cout << total << endl;
    }


}