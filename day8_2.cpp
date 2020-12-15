#include <bits/stdc++.h>

using namespace std;

int acc = 0;

bool repeating(vector<pair<string, int>> v, int pos){
	vector<int> visited;
	vector<int> checked;
	bool repeat = false;

	string inst;
	int i = 0, amount;
	while(i != (int)v.size()){
		if(binary_search(visited.begin(), visited.end(), v[i].second)){
			repeat = true;
			acc = 0;
			return repeat;
		}
		visited.push_back(i);
		sort(visited.begin(), visited.end());
		stringstream ss(v[i].first);
		ss >> inst >> amount;

		if(inst=="acc"){
			acc += amount;
			i++;
		}else if(inst=="jmp"){
			if(i == pos) i++;
			else i += amount;
		}else{
			if(i==pos) i += amount;
			else i++;
		}
	}

	return repeat;
}

int main(){
	vector<pair<string, int>> ops;
	string op;
	int index = 0;
	
	while(getline(cin, op)){
		pair<string, int> temp = make_pair(op, index);
		ops.push_back(temp);
		index++;
	}

	for(auto i : ops){
		string inst, amount;
		stringstream ss(i.first);
		ss >> inst >> amount; 
		int at = i.second;

		if(inst == "jmp" || inst == "nop"){
			if(!repeating(ops, at)) break;
		}
	}

	cout << acc;

	return 0;
}
