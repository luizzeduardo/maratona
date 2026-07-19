#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int total = 0;    
    for(int i=0; i<n; i++){
        int aux;
        cin >> aux;
        total+=aux;
    }

    if(total > 120){
        total +=180;
    }

    if(total > 720){
        total+=180;
    }

    cout <<  total << endl;
}