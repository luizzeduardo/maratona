#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    //0 = par, 1 = impar
    int par = 0;
    int lastpar =-1;
    int impar =0;
    int lastimpar = -1;
    for(int i=0; i<n; i++){
        if(a[i]%2 == 0){
            par++;
            lastpar = i+1;
        }
        else{
            impar++;
            lastimpar = i+1;
        }
    }

    if(par > impar){
        cout << lastimpar << endl;
    }
    else{
        cout << lastpar << endl;
    }
}