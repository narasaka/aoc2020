#include <bits/stdc++.h>

using namespace std;

int main(){
	string data, type, content;
	set<string> types;
	bool haveCid = false;
	int setSize, sizeNow, valid = 0;

	while(cin >> data){
		replace(data.begin(), data.end(), ':', ' ');
		stringstream ss(data);
		ss >> type >> content;
		setSize = types.size();

		if (type == "cid") haveCid = true;
		types.insert(type);
		sizeNow = types.size();

		if (sizeNow == setSize){
			if (sizeNow == 8) valid++;
			else if (sizeNow == 7 && !haveCid) valid++;

			types.clear();
			types.insert(type);
			haveCid = false;
		}
	}

	cout << valid;

	return 0;
}
