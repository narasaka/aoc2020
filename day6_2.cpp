#include <bits/stdc++.h>

using namespace std;

int main(){
	string a;
	map<char, int> mp;
	int people = 0, count = 0;
	while(getline(cin ,a)){
		if(a.size()){
			people++;
			for(char i : a){
				if(mp.count(i)>0) mp[i]++;
				else mp[i]=1;
			}
		}else{
			for(auto i : mp)
				if(i.second==people) count++;
			mp.clear();
			people = 0;
		}
	}
	for(auto i : mp)
		if(i.second==people) count++;
	cout << count;

	return 0;
}
