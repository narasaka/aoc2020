#include <bits/stdc++.h>

using namespace std;

int main(){
	string data;
	int ppSize = 0, valid = 0;
	string validecls[] = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
	bool haveCid = false, stillValid = true;
	while(getline(cin, data)){
		if(data.size()){
			string type, content;
			replace(data.begin(), data.end(), ':', ' ');
			stringstream ss(data);
			while(ss >> type){
				ss >> content;
				if(type=="cid") haveCid = true;
				else if(type=="byr"){
					int byr = stoi(content);
					if (byr < 1920 || byr > 2002) stillValid = false;
				}else if(type=="iyr"){
					int iyr = stoi(content);
					if (iyr < 2010 || iyr > 2020) stillValid = false;
				}else if(type=="eyr"){
					int eyr = stoi(content);
					if (eyr < 2020 || eyr > 2030) stillValid = false;
				}else if(type=="hgt"){
					string hgt = content;
					if (hgt.find("cm")==string::npos && hgt.find("in")==string::npos) stillValid = false;
					else if (hgt.find("cm")!=string::npos){
						hgt = hgt.substr(0, hgt.find("cm"));
						if(stoi(hgt) < 150 || stoi(hgt) > 193) stillValid = false;
					}else {
						hgt = hgt.substr(0, hgt.find("in"));
						if(stoi(hgt) < 59 || stoi(hgt) > 76) stillValid = false;
					}
				}else if(type=="hcl"){
					string hcl = content;
					if (hcl[0]!='#') stillValid = false;
					else if (hcl.size() != 7) stillValid = false;
					else {
						hcl = hcl.substr(1, hcl.size());
						for(char i : hcl) 
							if (isalpha(i)&&(i < 'a' || i > 'f') 
								stillValid = false; 
					}
				}else if(type=="ecl"){
					string ecl = content;
					bool found = false;
					for(int i = 0; i<7; ++i){
						if (validecls[i] == ecl) {
							found = true;
							break;
						}
					}
					if (!found) stillValid = false;
				}else{
					string pid = content;
					if (pid.size() != 9) stillValid = false;
					else{
						for(char i : pid) if(!isdigit(i)) stillValid = false;
					}
				} 
				ppSize++;
			}
		}else {
			if(ppSize == 8 && stillValid) valid++;
			else if(ppSize == 7 && !haveCid && stillValid) valid++;
			haveCid = false;
			stillValid = true;
			ppSize = 0;
		}
	}

	cout << valid;

	return 0;
}
