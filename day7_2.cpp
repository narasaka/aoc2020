#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> bags;
bool contains = false;
int inside = 0;

void checkBag(vector<string> bag){
	for(auto i : bag){
		inside++;
		checkBag(bags[i]);
	}
}

int main(){
	string line;
	while(getline(cin, line)){
		vector<string> v;
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
					v.push_back(content);
			}
		}

		bags[name] = v;
	}
	checkBag(bags["shinygold"]);

	cout << inside;
	return 0;
}

