#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int n, b;
    cin >> n;
    cin >> b;
    int menor = INT_MAX;
    vector<int> x(n);
    vector<int> y(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
        cin >> y[i];
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int q1 = 0;
            int q2 = 0;
            int q3 = 0; 
            int q4 = 0;

            for(int k=0; k<n; k++){
                if(x[k] > x[i]+1){
                    if(y[k] > y[j]+1) q1++;
                    else q2++;
                }
                else{
                    if(y[k] > y[j]+1) q4++;
                    else q3++;                
                }
            }

            menor = min(menor, max(max(q1, q2), max(q3, q4)));
        }
    }

    cout << menor << endl;
}