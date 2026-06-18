#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;
    string pode = "Yes";
    if(x > 18 || x < 3){
        pode = "No";
    }

    cout << pode << endl;
}
