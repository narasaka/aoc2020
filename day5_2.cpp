#include <bits/stdc++.h>

using namespace std;

int main(){
	string bp;
	vector<int> ids;
	int rows = 127, cols = 7;
	while(cin >> bp){
		int rowL = 0, rowR = rows, rowM;
		for(int i = 0; i<7; ++i){
			rowM = (rowL+rowR)/2;
			if (bp[i]=='F') rowR = rowM;
			else rowL = rowM + 1;
		}

		int colL = 0, colR = cols, colM;
		for(int i = 7; i<10; ++i){
			colM = (colL+colR)/2;
			if(bp[i]=='L') colR = colM;
			else colL = colM + 1;
		}

		int id = rowL*8+colL;
		ids.push_back(id);
	}

	sort(ids.begin(), ids.end());
	for(int i = ids[0]; i<ids[ids.size()-1]; ++i)
		if(!binary_search(ids.begin(), ids.end(), i)){
			cout << i;
			break;
		}
}
