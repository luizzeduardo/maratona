#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int n;
    cin >> n;

    vector<pair<string, int>> cows(n);
    for(int i=0; i<n; i++){
        cin >> cows[i].first;
        cin >> cows[i].second;
    }

    int menor = INT_MAX;
    for(int i=0; i<n; i++){
        int local = 0;
        for(int j=0; j<n; j++){
            if(cows[j].first == "G" && cows[i].second < cows[j].second) local++;
            if(cows[j].first == "L" && cows[i].second > cows[j].second) local++;
        }

        if(local < menor){
            menor = local;
        }
    }

    cout << menor << endl;
}