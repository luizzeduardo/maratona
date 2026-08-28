#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){

    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int k, n;
    cin >> k >> n;
    vector<vector<int>> cows(k, vector<int>(n));
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            cin >> cows[i][j];
        }
    }

    int resp = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;

            bool antes = true;
            bool anterior = false;
            bool seguinte = false;

            for(int m=0; m<k; m++){
                bool anterior = false;
                bool seguinte = false;
                for(int l=0; l<n; l++){
                    if(cows[m][l] == i+1) anterior = true;
                    if(cows[m][l] == j+1) seguinte = true;

                    if(seguinte && !anterior){
                        antes = false;
                        break;
                    }
                }
                if(!antes) break;
            }

            if(antes) resp++;
        }
    }

    cout << resp << endl;

}