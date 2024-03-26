#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool test(string qry);

string analizza(int N){

	string ans = "";

	int c = 0, l = sqrt(N);
	while (1){
		int qry = test(ans + "0");
		if (qry){
			ans += "0";
			c = 0;
		} else {
			ans += "1";
			c++;
		}
		if (c >= l){
			if (test(ans)) continue;
			// binsearch
		}
	}

	while (ans.size() != N){
		
	}


	return ans;
}