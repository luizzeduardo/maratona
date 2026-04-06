#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n-1);
    for(int i=0; i<n-1; i++){
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    for(int i=0; i<n; i++){
        if(i+1 != p[i]){
            cout << i+1 << endl;
            break; 
        }
    }
}