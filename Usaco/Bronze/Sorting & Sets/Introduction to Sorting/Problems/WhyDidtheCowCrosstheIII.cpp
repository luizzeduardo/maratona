#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main(){

    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);
    for(int i=0; i<n; i++){
        cin >> cows[i].first;
        cin >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    int total = 0;
    for(int i=0; i<n; i++){
        if(total <= cows[i].first) total = cows[i].first  + cows[i].second;
        else total += cows[i].second;
    }

    cout << total << endl;

}