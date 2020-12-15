#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> visited;
	vector<pair<string, int>> ops;
	string op;
	int index = 0, acc = 0;
	
	while(getline(cin, op)){
		pair<string, int> temp = make_pair(op, index);
		ops.push_back(temp);
		index++;
	}

	string inst;
	int i = 0, amount;
	while(i < (int)ops.size()){
		if (binary_search(visited.begin(), visited.end(), ops[i].second)) break;
		visited.push_back(i);
		sort(visited.begin(), visited.end());
		stringstream ss(ops[i].first);
		ss >> inst >> amount;

		if(inst=="acc"){
			acc += amount;
			i++;
		}else if(inst=="jmp"){
			i += amount;
		}else i++;
	}

	cout << acc;

	return 0;
}
