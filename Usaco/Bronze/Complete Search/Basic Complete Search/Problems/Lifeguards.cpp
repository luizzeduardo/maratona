#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);


    int n;
    cin >> n;
    vector<pair<int, int>> inter(n);
    for(int i=0; i<n; i++){
        cin >> inter[i].first;
        cin >> inter[i].second;
    }



    sort(inter.begin(), inter.end()); //O(logn)


    int total = INT_MIN;

    for(int i=0; i<n; i++){
        int menor_local = INT_MAX;
        int maior_local = INT_MIN;
        int total_local = 0;
        for(int j=0; j<n; j++){
            if(i == j) continue;

            if(total_local == 0){ 
                total_local += inter[j].second - inter[j].first;
                menor_local = inter[j].first;
                maior_local = inter[j].second;
            }

            // mais abaixo
            if(inter[j].first < menor_local && inter[j].second >= menor_local){
                total_local += menor_local - inter[j].first;
                menor_local = inter[j].first;

            }

            // mais acima
            if(inter[j].first <= maior_local && inter[j].second > maior_local){ 
                total_local += inter[j].second - maior_local;
                maior_local = inter[j].second;
            }

            // disjunto acima
            if(inter[j].first > maior_local){
                total_local += inter[j].second - inter[j].first;
                maior_local = inter[j].second;
            }  

            //disjujto abaixo
            if(inter[j].second < menor_local){
                total_local += inter[j].second - inter[j].first;
                menor_local = inter[j].first;
            }  


        }

        total = max(total, total_local);
    }

    cout << total << endl;
}