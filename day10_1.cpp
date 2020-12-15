#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> jolts;
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

	cout << one*three;

	return 0;
}
