#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c ,d;
    cin >> a >> b >> c >> d;

    int A = b - a;
    int B = d - c;

    // intersecção
    int total = A + B;
    //totalmente contido
    if(a>=c && b<=d || a<=c && b>=d ){
        cout << max(A, B) << endl;
        return 0;
    }
    // intersecção
    
    else if(a>c && a<d){
        total -= (d-a);
    }
    else if(c>a && c<b){
        total -= (b-c);
    }
    cout << total << endl;

}