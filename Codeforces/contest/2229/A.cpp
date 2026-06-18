#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(a[i] > max){
                max = a[i];
            }
            if(a[i] < min){
                min = a[i];
            }
        }

        cout << (max - min + 1)/2 << endl;

        //selecionar um x entre
        //aperar:
        //aj -= 1 se aj > x
        //aj += 1 se aj < x
        //Isso deve ser minimizado

        //Pegar o numero do meio entre os extremos

        // melhor optimo=(max-min+1)/2

    }
}