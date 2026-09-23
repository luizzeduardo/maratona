#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    vector<int> a(3);
    for(int i=0; i<3; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int maior = INT_MIN;
    int menor = INT_MAX;

    int d1 = a[1] - a[0];
    int d2 = a[2] - a[1];

    if(d1 == 1 && d2 == 1) menor = 0;
    else if(d1 == 2 || d2 == 2) menor = 1;   
    else menor = 2;

    maior = max(d1, d2) - 1;


    cout << menor << endl;
    cout << maior << endl;
}