#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	vector<ll> all;
	ll temp;
	while(cin >> temp) all.push_back(temp);
	
	int n = all.size();
	for(int i = 0; i<n-25; ++i){
		vector<ll> preamble(all.begin()+i, all.begin()+i+26);
		sort(preamble.begin(), preamble.begin()+25);
		int l=0, r=24, target=preamble[25];
		
		while(l < r){
			ll total = preamble[l]+preamble[r];
			if (total < target) l++;
			else if (total > target) r--;
			else break;
		}

		if(l >= r){
			cout << target;
			break;
		}
	}
	
	return 0;
}
