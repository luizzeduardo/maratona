#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int delta(int l, int r, vector<int> &a, vector<int> &b){
    int ganho = (a[r] == b[l]) + (a[l] == b[r]);
    int perda = (a[l] == b[l]) + (a[r] == b[r]);
    return (ganho - perda);
}


int main(){


    int n;
    cin >> n;
    

    vector<int> atual(n);
    vector<int> desejado(n);


    for(int i=0; i<n; i++){
        cin >> atual[i]; 
    }
    for(int i=0; i<n; i++){
        cin >> desejado[i];
    }

    int certos = 0;
    for(int i=0; i<n; i++){
        if(atual[i] == desejado[i]) certos++;
    }

    vector<long long> ans(n + 1, 0);

    for(int s = 0; s <= 2 * (n - 1); s++){   
        int l = s / 2, r = s - l;           
        int P = 0;

        if(l != r) P += delta(l, r, atual, desejado); 
        ans[certos + P]++;                             

        while(l > 0 && r < n - 1){            
            l--; r++;                       
            P += delta(l, r, atual, desejado);  
            ans[certos + P]++;              
        }
    }

    for(int c = 0; c <= n; c++) cout << ans[c] << endl;


    // brute force n passa nem a reza

    // for(int c=0; c<=n; c++){
    //     int local = 0;
    //     for(int l=0; l<n; l++){
    //         for(int r=l; r<n; r++){
    //             int certos = 0;
    //             for(int i=0; i<n; i++){
    //                 if(i>=l && i <= r){
    //                     if(desejado[i] == atual[l+r-i]) certos++;
    //                 }
    //                 else{
    //                     if(desejado[i] == atual[i]) certos++;
    //                 }
    //             }
    //             if(certos == c) local++;
    //         }   
    //     }
    //     cout << local << endl;
    // }


}