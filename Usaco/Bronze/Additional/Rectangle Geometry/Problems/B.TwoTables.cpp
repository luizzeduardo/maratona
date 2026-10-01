#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){

        int L, A;
        cin >> L >> A;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int la = x2 - x1;
        int aa = y2 - y1;

        //area restante
        int ar = A - aa;
        int lr = L - la;

        int l, a;
        cin >> l >> a;

        // tem como colocar
        int move = INT_MAX;
        //sempre vai ser um ou outro
        if(l<=lr && a<=A ){
            int restoSup = L-x2;
            int restoInf = L - la - restoSup;
            int falta = max(l - max(restoSup, restoInf), 0);
            move = min(move, falta);
        }
        if(a<=ar && l<=L){
            int restoSup = A-y2;
            int restoInf = A - aa - restoSup;
            int falta = max(a - max(restoSup, restoInf), 0) ;
            move = min(move, falta);            
        }
        if(move == INT_MAX){ cout << -1 << endl; continue;}


        cout << move << endl;

    }
}