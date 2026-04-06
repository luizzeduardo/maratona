#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        //n >= 2
        // podemos fazer todos iguais a 1
        //5 4 3 2 1 -> 1 1 1 0
     
        for(int i=n; i>0; i--){
            cout << i << " ";
        }
        cout << endl;
    }
}