#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> bags;
bool contains = false;

void checkBag(vector<string> bag){
	if (contains) return;
	for(auto i : bag){
		if (i == "shinygold") contains = true;
		checkBag(bags[i]);
	}
}

int main(){
	int count = 0;
	string line;
	while(getline(cin, line)){
		set<string> s;
		string tone, clr, name, dump, amount;
		stringstream ss(line);

		ss >> tone >> clr;
		name = tone+clr;

		ss >> dump >> dump;
		while(ss >> amount){
			string content;
			if(amount=="no"){
				ss >> dump >> dump;
			}else{
				int n = stoi(amount);
				ss >> tone >> clr >> dump;
				content = tone+clr;
				for(int i = 0; i < n; ++i)
					s.insert(content);
			}
		}

		vector<string> v(s.begin(), s.end());
		bags[name] = v;
	}

	for(auto bag : bags){
		checkBag(bag.second);
		if (contains) count++;
		contains = false;
	}

	cout << count;
	return 0;
}

