#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int indexOf(int x);
vector<int> v;

int main(){
	int target = 2020;
	int temp;
	while(cin >> temp) v.push_back(temp);

	sort(v.begin(), v.end());

	int n, third, id1, id2, id3;
	n = v.size();
	for(int i = 0; i < n; ++i){
		bool found = false;
		for(int j = i+1; j < n; ++j){
			third = target-v[i]-v[j];
			id3 = indexOf(third);
			if (id3 != -1){
				found = true;
				id1 = i; id2 = j;
				break;
			}
		}
		if (found) break;
	}

	ll ans = (ll) v[id1]*v[id2]*v[id3];

	cout << ans;

	return 0;
}

int indexOf(int x){
	int l = 0, r = v.size()-1, m;
	while(l <= r){
		m = l + (r-l)/2;
		if (v[m]==x) return m;

		if (v[m]<x) l = m+1;
		else r = m-1;
	}

	return -1;
}
