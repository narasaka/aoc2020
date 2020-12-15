#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	vector<ll> all;
	ll temp, target;
	while(cin >> temp) all.push_back(temp);
	
	int n = all.size();
	for(int i = 0; i<n-25; ++i){
		vector<ll> preamble(all.begin()+i, all.begin()+i+26);
		sort(preamble.begin(), preamble.begin()+25);
		int l=0, r=24;
		ll invalid=preamble[25];
		
		while(l < r){
			ll total = preamble[l]+preamble[r];
			if (total < invalid) l++;
			else if (total > invalid) r--;
			else break;
		}

		if(l >= r){
			target = invalid;
			break;
		}
	}

	int inc = 2;
	ll total = 0;
	while(inc < n){
		for(int i = 0; i<=n-inc; ++i){
			for(int j = i; j<i+inc; ++j){
				total += all[j];
			}
			if(total==target){
				ll best = INT_MIN;
				ll worst = INT_MAX;
				for(int k = i; k<i+inc; ++k){
					best = max(best, all[k]);
					worst = min(worst, all[k]);
				}
				cout << best+worst;
				return 0;
			}
			total = 0;
		}
		inc++;
	}
	
	return 0;
}
