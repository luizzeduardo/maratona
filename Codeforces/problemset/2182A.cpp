#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        //20252026, 21026, 20262026, 000 (new year)
        //2025, 20256, 20252025, 000202500020226 (n é new year)
        int n;
        cin>> n;
        string s;
        cin >> s;
        bool year2026 = false;
        bool year2025 = false;
        for(int i=0; i<n; i++){
            if( s.substr(i, 4) == "2026" ){
                year2026 = true;
                break;
            }
            else if( s.substr(i, 4) == "2025" ){
                year2025 = true;
            }
        }
        if(year2026){
            cout << 0 << endl;
        }
        else if(year2025){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
}