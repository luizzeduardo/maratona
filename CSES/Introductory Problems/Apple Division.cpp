#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll menor = LLONG_MAX;
ll total = 0;

void apple(int maca, ll atual, int n, vector<int> &apples){
    if(maca==n){
        menor = min(menor, abs(total-2*(atual)));
        return;
    }
    apple(maca+1, atual+apples[maca], n, apples);
    apple(maca+1, atual, n, apples);
    return;
}

int main(){
    int n;
    
    cin >> n;
    vector<int> apples(n);
    for(int i=0; i<n; i++){ cin >> apples[i]; total+= apples[i];}
    // n<=20
    // força bruta

    
    apple(0, 0, n, apples);
    cout << menor << endl;
}