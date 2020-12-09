#include <bits/stdc++.h>

using namespace std;

int main(){
	int correct = 0;
	string limits;
	while(cin >> limits){
		replace(limits.begin(), limits.end(), '-', ' ');
		stringstream ss(limits);

		int a, b;
		char letter;
		string temp, password;
		ss >> a >> b;
		a--; b--;
		cin >> temp; letter = temp[0];
		cin >> password;

		int bitX = 0, bitY = 0;
		if (password[a]==letter) bitX = 1;
		if (password[b]==letter) bitY = 1;
		if ((bitX ^ bitY) == 1) correct++;
	}

	cout << correct;
}
