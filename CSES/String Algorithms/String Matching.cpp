#include <bits/stdc++.h>
using namespace std;
using ll = long long;


const int B = 26;
const int A = 999999973;

int add(int a, int b){
    a += b;
    if(a >= A) a -= A;
    return a;
}


int sub(int a, int b){
    a -= b;
    if(a < 0) a += A;
    return a;
}


int mult(int a, int b){
    return ((ll)a*b) % A;
}

int binpow(int a, int b){
    int resp = 1;
    while(b){
        if(b & 1){
            resp = mult(resp, a);
        }

        a = mult(a, a);
        b >>= 1;
    }
    return resp;
}


int invmod(int a){
    return binpow(a, A-2);
}



int main(){
    string s, p;
    cin >> s >> p;

    int n, m;
    n = s.size();
    m = p.size();

    if(m>n){
        cout << 0 << endl;
        return 0;
    }

    vector<int> prefix_hash(n-m + 1);

    int hash_p = 0;

    for (char c : p) hash_p = add(mult(hash_p, B), c - 'a'); // adiciona cada elemento ao hash

    int powBm = binpow(B, m-1);
    for (int i=0; i<m; i++) prefix_hash[0] = add(mult(prefix_hash[0], B), s[i] - 'a');


    for (int i=1; i<prefix_hash.size(); i++) {
        prefix_hash[i] = sub(prefix_hash[i-1], mult(powBm, s[i-1] - 'a'));
        prefix_hash[i] = mult(prefix_hash[i], B);
        prefix_hash[i] = add(prefix_hash[i], s[i+m-1] - 'a');
    }

    int ans = 0;
    for (int hash : prefix_hash) ans += (hash == hash_p);

    cout << ans << '\n';

}