#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, int>> tri(n);
    for(int i=0; i<n; i++){
        cin >> tri[i].first;
        cin >> tri[i].second;
    }

    ll maior = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){

                bool valido = false; 
                if((tri[i].first == tri[j].first && tri[i].second == tri[k].second) || (tri[i].first == tri[k].first && tri[i].second == tri[j].second)) valido = true;
                if((tri[j].first == tri[i].first && tri[j].second == tri[k].second) || (tri[j].first == tri[k].first && tri[j].second == tri[i].second)) valido = true;
                if((tri[k].first == tri[j].first && tri[k].second == tri[i].second) || (tri[k].first == tri[i].first && tri[k].second == tri[j].second)) valido = true;


                if(!valido) continue;


                ll area = (ll)(tri[j].first  - tri[i].first) * (tri[k].second - tri[i].second)
                 - (ll)(tri[k].first  - tri[i].first) * (tri[j].second - tri[i].second);                
                
                area = abs(area);
                if(area > maior) maior = area;

            }
        }
    }

    cout << maior << endl;

}