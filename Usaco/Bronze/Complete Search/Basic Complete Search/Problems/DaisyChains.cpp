#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    int total = 0;
    for(int i=0; i<n; i++){
        cin >> nums[i];
        total += nums[i];
    }

    int resp = n;

    for(int i=0; i<n; i++){
        int total = nums[i];
        int quant = 1;
        for(int j=i+1; j<n; j++){
            total+= nums[j];
            quant++;
            for(int k=i; k<=j; k++){
                if(nums[k]*quant == total){
                    resp++;
                    break;
                }
            }
        }
    }
    cout << resp << endl;
}