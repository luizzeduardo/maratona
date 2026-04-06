#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int query(int x, int y){
    cout << "? " << x << " " << y << endl;
    cout.flush();
    int a;
    cin >> a;
    return a;
}

int high(int n, int m){
    if(n>m){
        return n;
    }
    else{
        return m;
    }
}

int main(){
    int n;
    cin >> n;
    int pos_n = 1;
    vector<int> p(n+1, 0);
    //achar em n + n/2 + n/4 + n/8 ... + 1
    // i mod(n_pos) < n_pos mod(i) -> n_pos > i

    
    for (int i = 2; i <= n; i++) {
        int r1 = query(pos_n, i);
        int r2 = query(i, pos_n);
        
       if (r1 > r2) {
            p[pos_n] = r1; 
            pos_n = i; 
        } else {
            p[i] = r2; 
        }
    }
    p[pos_n] = n;

    cout << "! ";
    for(int i=1; i<=n; i++){
        cout << p[i] << " ";
    }
}