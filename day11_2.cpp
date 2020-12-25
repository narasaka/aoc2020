#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> room;
vector<vector<char>> updated;

void processSeat(int y, int x);
//void printAll(vector<vector<char>> v);

int main(){
	string line;
	while(cin >> line){
		vector<char> seats;
		for(char i : line) seats.push_back(i);
		room.push_back(seats);
	}

	updated = room;

	int ymax = room.size();
	int xmax = room[0].size();

	do{
		room = updated;
		for(int y = 0; y<ymax; ++y)
			for(int x = 0; x<xmax; ++x)
				processSeat(y, x);

		//printAll(updated);

	}while(room != updated);

	int occupied = 0;
	for(int y = 0; y<ymax; ++y)
		for(int x = 0; x<xmax; ++x)
			if(room[y][x]=='#') occupied++;
	
	cout << "Occupied seats: " << occupied << '\n';

	return 0;
}

void processSeat(int y, int x){
	int xmax = room[0].size(), ymax = room.size();
	int empty = 0, seated = 0;

	for(int i=x-1; i>=0; --i)
		if(room[y][i]!='.'){
			(room[y][i]=='L')? empty++:seated++;
			break;
		}

	for(int i=x+1; i<xmax; ++i)
		if(room[y][i]!='.'){
			(room[y][i]=='L')? empty++:seated++;
			break;
		}

	for(int i=y-1; i>=0; --i)
		if(room[i][x]!='.'){
			(room[i][x]=='L')? empty++:seated++;
			break;
		}

	for(int i=y+1; i<ymax; ++i)
		if(room[i][x]!='.'){
			(room[i][x]=='L')? empty++:seated++;
			break;
		}

	for(int i=y-1, j=x-1; i>=0 && j>=0; --i, --j)
		if(room[i][j]!='.'){
			(room[i][j]=='L')? empty++:seated++;
			break;
		}

	for(int i=y-1, j=x+1; i>=0 && j<xmax; --i, ++j)
		if(room[i][j]!='.'){
			(room[i][j]=='L')? empty++:seated++;
			break;
		}

	for(int i=y+1, j=x-1; i<ymax && j>=0; ++i, --j)
		if(room[i][j]!='.'){
			(room[i][j]=='L')? empty++:seated++;
			break;
		}

	for(int i=y+1, j=x+1; i<ymax && j<xmax; ++i, ++j)
		if(room[i][j]!='.'){
			(room[i][j]=='L')? empty++:seated++;
			break;
		}

	if(room[y][x] == 'L' && empty==empty+seated)
		updated[y][x]='#';
	else if(room[y][x] == '#' && seated>=5)
		updated[y][x]='L';
}

//void printAll(vector<vector<char>> v){
	//for(auto i : v){
		//for(char j : i)
			//cout << j;
		//cout << '\n';
	//}
	//cout << '\n';
//}
