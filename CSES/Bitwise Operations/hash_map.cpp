#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// Você recebe uma lista N de n elementos, e K numero alvo. 
// O seu objetivo é retornar quantos valores de N podem formar N[i] + N[j] = K para i<j

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;

    //receber n elemento e ver quantos pares deles dá k

    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    // pq n dá pra ser vetor? pq n dá pra saber o quao grandes vao ser os valores dos nums
    // e tbm n permite negativos em um vector normal
    ll ans = 0;
    unordered_map<int, int> somas;
    for(int i=0; i<n; i++){
        int complemento = k - nums[i];
        
        if(somas.count(complemento)){
            ans += somas[complemento];
        }

        somas[nums[i]]++;
    }

    cout << ans << endl;
}