#include <bits/stdc++.h>

using namespace std;

int main(){
	char dirs[4] = {'E', 'S', 'W', 'N'};
	char currDir = 'E';
	int currIdx = 0;
	int x = 0, y = 0;

	char dir;
	int val;
	while(scanf("%c%d\n", &dir, &val) != EOF){
		if(dir=='N') y += val;
		else if(dir=='S') y -= val;
		else if(dir=='E') x += val;
		else if(dir=='W') x -= val;
		else{
			if(dir=='F'){
				if(currDir=='N') y += val;
				else if(currDir=='S') y -= val;
				else if(currDir=='E') x += val;
				else x -= val;
			}else if(dir=='R'){
				int turns = val/90;
				currIdx += turns;
				currIdx %= 4;
				currDir = dirs[currIdx];
			}else{
				int turns = val/90;
				currIdx += abs(4-turns);
				currIdx %= 4;
				currDir = dirs[currIdx];
			}
		}
	}

	x = abs(x); y = abs(y);

	printf("Manhattans distance: %d\n", x+y);
		
	return 0;
}
