#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> inter(ll a1, ll a2, ll b1, ll b2){
    ll ab1 = max(a1, b1);
    ll ab2 = min(a2, b2); 

    if(ab2 - ab1 <= 0){
        ab1 = 0;
        ab2 = 0;
    }
    return {ab1, ab2};
}

ll area(ll a1,ll a2,ll b1,ll b2){
    ll total = (a2-a1)*(b2-b1);
    return total;
}


int main(){
    ll ax1, ay1, ax2, ay2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;

    ll bx1, by1, bx2, by2;
    cin >> bx1 >> by1 >> bx2 >>by2;

    ll cx1, cy1, cx2, cy2;
    cin >> cx1 >> cy1 >> cx2 >> cy2;

    //A -> area do branco
    //B -> area do preto 1
    //C -> area do preto 2
    ll A = area(ax1, ax2, ay1, ay2);

    pair<ll, ll> ABx = inter(ax1, ax2, bx1, bx2);
    pair<ll, ll> ABy = inter(ay1, ay2, by1, by2);
    ll AB = area(ABx.first, ABx.second, ABy.first, ABy.second);

    pair<ll, ll> ACx = inter(ax1, ax2, cx1, cx2);
    pair<ll, ll> ACy = inter(ay1, ay2, cy1, cy2);
    ll AC = area(ACx.first, ACx.second, ACy.first, ACy.second);
    
    pair<ll, ll> ABCx = inter(ACx.first, ACx.second, ABx.first, ABx.second);
    pair<ll, ll> ABCy = inter(ABy.first, ABy.second, ACy.first, ACy.second);

    ll ABC = area(ABCx.first, ABCx.second, ABCy.first, ABCy.second);


    if(A - AB - AC + ABC <= 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}