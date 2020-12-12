#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	string path;
	cin >> path;

	int width = path.size();
	int r[5] = {0, 0, 0, 0, 0};
	int trees[5] = {0, 0, 0, 0, 0};
	int rTurn = 0;
	while(cin >> path){
		r[0] += 1;
		r[1] += 3;
		r[2] += 5;
		r[3] += 7;

		r[0] %= width;
		r[1] %= width;
		r[2] %= width;
		r[3] %= width;

		rTurn++;
		if (rTurn%2==0){
			r[4] += 1;
			r[4] %= width;
			if (path[r[4]]=='#') trees[4]++;
		}

		if (path[r[0]]=='#') trees[0]++;
		if (path[r[1]]=='#') trees[1]++;
		if (path[r[2]]=='#') trees[2]++;
		if (path[r[3]]=='#') trees[3]++;
	}

	ll prod = 1;
	for (auto tree : trees){
		prod *= (ll) tree;
	}

	cout << prod;
	
	return 0;
}
