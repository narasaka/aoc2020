#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> jolts;
map<int, ll> mem;

ll dp(int index);

int main(){
	int jolt;
	while(cin >> jolt)
		jolts.push_back(jolt);

	sort(jolts.begin(), jolts.end());
	int n = jolts.size();
	int one = 0, three = 0;
	int curr = jolts[0];
	//add the outlet
	if(curr==1) one++;
	else if(curr==3) three++;
	//start
	for(int i = 1; i<n; ++i){
		if(jolts[i]-curr==1)
			one++;
		else if(jolts[i]-curr==3)
			three++;
		
		curr = jolts[i];
	}
	//add the built in adapter
	three++;

	//append+insert built in and outlet
	jolts.push_back(jolts[jolts.size()-1]+3);
	jolts.insert(jolts.begin(), 0);

	//aaaanddd go!
	cout << dp(0);

	return 0;
}

ll dp(int index){
	int n = jolts.size();
	if(index==n-1) return 1;
	if(mem.count(index)>0) return mem[index];
	ll comb = 0;
	for(int i = index+1; i<n; ++i){
		if(jolts[i]-jolts[index]<=3)
			comb += dp(i);
	}
	mem[index]=comb;
	return comb;
}
