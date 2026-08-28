#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	
	int n, k; 
	cin >> n; 
	cin >> k;
	
	vector<int> dimas(n);
	int maior = INT_MIN;
	
	for(int i=0; i<n; i++){
		cin >> dimas[i];
	}
	
	for(int i=0; i<n; i++){
		int local =0;
		for(int j=0; j<n; j++){
			if( dimas[i] <= dimas[j] && dimas[i] + k >= dimas[j]){
				local++;
			}
		}
		
		if(local > maior) maior = local;
	}
	
	cout << maior << endl;
}