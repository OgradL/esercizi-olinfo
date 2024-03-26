#include <iostream>
#include <vector>
using namespace std;

int s2i(string s){
	int n = 0, po = 1;
	int i = s.size()-1;
	while (i >= 0){
		n += (s[i]-'0')*po;
		po *= 10;
		i--;
	}
	return n;
}

int main(){
	
	int p2[21];
	p2[0] = 1;
	for (int i = 1; i < 20; i++){
		p2[i] = 2 * p2[i-1];
	}

	int p5[10];
	p5[0] = 1;
	for (int i = 1; i < 10; i++){
		p5[i] = 5 * p5[i-1];
	}

	string s;
	cin >> s;

	int due = 0, cinque = 0;
	string n;
	for (int i = 0; i <= s.size(); i++){
		if (s[i] == 'x' || i == s.size()){
			
			int num = s2i(n);

			int lo = 0, hi = 20, mid;
			while (lo + 1 < hi){
				mid = (lo+hi)/2;
				if (num % p2[mid]){
					hi = mid;
				} else {
					lo = mid;
				}
			}
			due += lo;

			lo = 0, hi = 9;
			while (lo + 1 < hi){
				mid = (lo+hi)/2;
				if (num % p5[mid]){
					hi = mid;
				} else {
					lo = mid;
				}
			}
			cinque += lo;

			n = "";
		} else {
			n += s[i];
		}
	}

	cout << min(due, cinque) << "\n";

	return 0;
}