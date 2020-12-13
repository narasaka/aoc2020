#include <bits/stdc++.h>

using namespace std;

int main(){
	string bp;
	int rows = 127, cols = 7, best = INT_MIN;
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
		best = max(best, id);
	}
	cout << best;
}
