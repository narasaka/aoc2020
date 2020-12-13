#include <bits/stdc++.h>

using namespace std;

int main(){
	string data;
	int size = 0, valid = 0;
	bool haveCid = false;
	while(getline(cin, data)){
		if(data.size()){
			string type, content;
			replace(data.begin(), data.end(), ':', ' ');
			stringstream ss(data);
			while(ss >> type){
				ss >> data;
				if(type=="cid") haveCid = true;
				size++;
			}
		}else {
			if(size == 8 || (size==7 && !haveCid)) valid++;
			haveCid = false;
			size = 0;
		}
	}

	cout << valid;

	return 0;
}
