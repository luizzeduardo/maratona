#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){


    int k, n;
    cin >> k >> n;

    int extra = n - 2*k + 1;

    if(extra < 0 || extra > k+1) {
        cout << "*" << endl;
        return 0;
    }

    string s;
    if(extra){ 
        s+= '-';
        extra--;
    }
    for(int i = 0; i < k; i++){
        s += 'X';
        if(i + 1 < k){                       
            s += '-';                        
            if(extra){ 
                s += '-'; 
                extra--; 
            } 
        }
    }

    if(extra) s += '-';

    cout << s << endl;;
}

// Tempo Pensando: 9min
// Tempo Codando: 13min
// Tempo Debugando: 3min
// Tempo Total: 25min

