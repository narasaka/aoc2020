#include <bits/stdc++.h>

using namespace std;

int main(){
	string a;
	set<char> s;
	int count = 0;
	while(getline(cin ,a)){
		if(a.size()){
			for(char i : a) s.insert(i);
		}else{
			count += s.size();
			s.clear();
		}
	}
	count += s.size();
	cout << count;

	return 0;
}
