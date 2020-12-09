#include <bits/stdc++.h>

using namespace std;

int main(){
	int target = 2020;
	int temp;
	vector<int> v;
	while(cin >> temp) v.push_back(temp);

	sort(v.begin(), v.end());

	int l, r, total;
	l = 0; r = v.size() - 1; total = 0;

	total = v[l] + v[r];
	while(total != target){
		if (total < target) l++;
		else if (total > target) r--;
		total = v[l] + v[r];
	}

	cout << v[l]*v[r];

	return 0;
}
