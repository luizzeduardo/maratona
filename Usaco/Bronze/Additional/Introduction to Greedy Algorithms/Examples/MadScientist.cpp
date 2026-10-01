#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    bool mantem = false;
    int quant = 0;
    for(int i=0; i<n; i++){
        if(a[i] != b[i]){
            if(!mantem){ quant++; mantem=true;}
        }
        else{
            mantem = false;
        }
    }

    cout << quant << endl;
    
}