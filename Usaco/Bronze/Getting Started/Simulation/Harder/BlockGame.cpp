#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();
    vector<int> quant(26, 0);
    
    for(int i=0; i<n; i++){
        vector<int> qa(26, 0);
        vector<int> qb(26, 0);
        string a, b;
        cin >> a >> b;
        int tama = a.length();
        int tamb = b.length();

        for(int j=0; j<tama; j++){
            if(a[j] != ' '){
                qa[a[j]-'a']++;
            }
        }
        for(int j=0; j<tamb; j++){
            if(b[j] != ' '){
                qb[b[j]-'a']++;
            }
        }
        for(int i=0; i<26; i++){
            quant[i] += max(qa[i], qb[i]);
        }
    }

    for(int i=0; i<26; i++){
        cout << quant[i] << endl;
    }
}