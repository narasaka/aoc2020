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

	if(x-1 >= 0){
		if(room[y][x-1]!='.')
			(room[y][x-1]=='L')? empty++:seated++;
	}
	if(x+1 < xmax){
		if(room[y][x+1]!='.')
			(room[y][x+1]=='L')? empty++:seated++;
	}
	if(y-1 >= 0){
		if(room[y-1][x]!='.')
			(room[y-1][x]=='L')? empty++:seated++;
	}
	if(y+1 < ymax){
		if(room[y+1][x]!='.')
			(room[y+1][x]=='L')? empty++:seated++;
	}
	if(y-1 >= 0 && x-1 >= 0){
		if(room[y-1][x-1]!='.')
			(room[y-1][x-1]=='L')? empty++:seated++;
	}
	if(y-1 >= 0 && x+1 < xmax){
		if(room[y-1][x+1]!='.')
			(room[y-1][x+1]=='L')? empty++:seated++;
	}
	if(y+1 < ymax && x-1 >= 0){
		if(room[y+1][x-1]!='.')
			(room[y+1][x-1]=='L')? empty++:seated++;
	}
	if(y+1 < ymax && x+1 < xmax){
		if(room[y+1][x+1]!='.')
			(room[y+1][x+1]=='L')? empty++:seated++;
	}

	if(room[y][x] == 'L' && empty==empty+seated)
		updated[y][x]='#';
	else if(room[y][x] == '#' && seated>=4)
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
