#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int n;
    cin >> n;
    set<int> a;
    for(int i=0; i<n; i++){
        int aux; cin >> aux;
        a.insert(aux);
    }
 
    cout << a.size() << endl;
 
}