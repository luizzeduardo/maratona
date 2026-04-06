#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> b(n);
    for(int i=0; i<n; i++){
        cin >> b[i];
    }

    int moves = 0;
    int aux = b[0];
    for(int i=1; i<n; i++){
        if(aux >= b[i]){
            int dif = aux - b[i];
            dif /= d;
            moves += dif+1;
            b[i] += (dif+1)*d;
        }
        aux = b[i];
    }

    cout << moves << endl;

}