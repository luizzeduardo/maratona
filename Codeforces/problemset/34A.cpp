#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int min_diff = INT_MAX;
    int pos1 = 1, pos2 = 2;  
    
    for(int i=0; i<n-1; i++){
        int diff = abs(a[i] - a[i+1]);
        if(diff < min_diff){
            min_diff = diff;
            pos1 = i+1;  
            pos2 = i+2;
        }
    }
    
    int diff = abs(a[n-1] - a[0]);
    if(diff < min_diff){
        pos1 = n;
        pos2 = 1;
    }
    
    cout << pos1 << " " << pos2 << endl;
    
    return 0;
}