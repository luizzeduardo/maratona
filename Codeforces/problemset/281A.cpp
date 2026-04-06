#include <bits/stdc++.h>
using namespace std;

int main(){
    string palavra;
    cin >> palavra;

    int inicio = palavra[0] - 'A';
    if(inicio >= 32){
        palavra[0] -= 32;
    }

    cout << palavra << endl;
}