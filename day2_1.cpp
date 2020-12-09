#include <bits/stdc++.h>

using namespace std;

int main(){
	int correct = 0;
	string limits;
	while(cin >> limits){
		replace(limits.begin(), limits.end(), '-', ' ');
		stringstream ss(limits);

		int mint, maxt;
		char letter;
		string temp, password;
		ss >> mint >> maxt;
		cin >> temp; letter = temp[0];
		cin >> password;

		int count = 0;
		for(auto i : password) if (i==letter) count++;

		if (count >= mint && count <= maxt) correct++;
	}

	cout << correct;
}
