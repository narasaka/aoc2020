#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	vector<int> v;
	int target = 2020;
	int temp;
	while(cin >> temp) v.push_back(temp);

	sort(v.begin(), v.end());

	int n, total;
	n = v.size();
	for(int i = 0; i < n-2; ++i){
		bool found = false;
		int a = v[i], j = i+1, k = n-1;
		while(j < k){
			int b = v[j], c = v[k];
			total = a+b+c;
			if (total<target) j++;
			else if (total>target) k--;
			else{
				found = true;
				ll ans = (ll) a*b*c;
				cout << ans;
				break;
			}
		}
		if (found) break;
	}

	return 0;
}

