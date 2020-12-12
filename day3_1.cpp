#include <bits/stdc++.h>

using namespace std;

int main(){
	string path;
	cin >> path;

	int width = path.size(), r = 0, tree = 0;
	while(cin >> path){
		r += 3;
		r %= width;
		if (path[r]=='#') tree++;
	}

	cout << tree;
	
	return 0;
}
