#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;

        int menor = min(a, b);
        int maior = max(a, b);

        int resp = -1;

        //multiplos a e b

        // um deles é divisor do outro
        if(maior%menor == 0){
            int p = maior/menor;
            resp = maior*p;
        }
        

        // primos entre si nesse caso
        //x = a.p e x = b.r, ent o x é o proprio mmc (menor multiplo comum)
        else{
            int mdc = gcd(a, b);
            resp = a/mdc * b;
        }

        cout << resp << endl;

    }
}