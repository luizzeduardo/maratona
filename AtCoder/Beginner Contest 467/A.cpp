#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int h, w;
    cin >> h;
    cin >> w;
    float bmi = w * 10000;

    bmi/=h;
    bmi/=h;


    if(bmi >= 20){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}