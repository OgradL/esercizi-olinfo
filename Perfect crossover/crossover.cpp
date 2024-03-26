//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string crossover(string s, string t){
	
	if (s == "")
		return t;
	if (t == "")
		return s;
	
	int lens = s.size();
	int lent = t.size();
	
	string firsts = s.substr(0, 1);
	string rests = s.substr(1, lens);
	string lastt = t.substr(lent - 1, 1);
	string restt = t.substr(0, lent - 1);
	
	if (firsts == lastt){
		return crossover(restt, rests);
	} else {
		return lastt + crossover(rests, restt) + firsts;
	}
}

int main(){
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	string s, t;
	
	cin >> s >> t;
	
//	cout << crossover(s, t) << "\n";
	
	
	string prima = "";
	string dopo = "";
	
	while (s != "" && t != ""){
		int lens = s.size();
		int lent = t.size();
		
		string firsts = s.substr(0, 1);
		string rests = s.substr(1, lens);
		string lastt = t.substr(lent - 1, 1);
		string restt = t.substr(0, lent - 1);
		
		if (firsts == lastt){
			s = restt;
			t = rests;
		} else {
			prima = prima + lastt;
			dopo = firsts + dopo;
			s = rests;
			t = restt;
		}
		
	}
	
	cout << prima + s + t + dopo << "\n";
	
	return 0;
}
