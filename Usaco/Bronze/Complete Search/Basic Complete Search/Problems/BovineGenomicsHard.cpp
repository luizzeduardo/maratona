#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n; cin >> n;
    int m; cin >> m;

    vector<string> spotty(n);
    for(int i=0; i<n; i++){
        cin >> spotty[i];
    }

    vector<string> plain (n);
    for(int i=0; i<n; i++){
        cin >> plain[i];
    }

    int total = 0;
    
    for(int a=0; a<m-2; a++){
        for(int b=a+1; b<m-1; b++){
            for(int c=b+1; c<m; c++){

                set<string> spottys;
                bool unico = true;

                for(int i=0; i<n; i++){
                    string A = string(1, spotty[i][a]);
                    A += spotty[i][b];
                    A += spotty[i][c];
                    spottys.insert(A);
                }

                for(int i=0; i<n; i++){
                    string seq = string(1, plain[i][a]);
                    seq += plain[i][b];
                    seq += plain[i][c];
                    if(spottys.count(seq) != 0){
                        unico = false;
                        break;
                    }
                }

                if(unico) total++;
            }
        }
    }

    cout << total << endl;

}