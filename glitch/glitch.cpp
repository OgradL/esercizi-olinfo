#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void radix_sort(vector<pair<int, int>>& v){
	vector<pair<pair<int, int>, int>> s(v.size());
	for (int i = 0; i < v.size(); i++)
		s[i] = {v[i], i};
	
	// sort();
}

int main(){

	int N;
	cin >> N;

	string s;
	cin >> s;

	int M = s.size();

	int righe = log2(s.size())+1;

	vector<pair<int, int>> v(N);
	for (int j = 0; j < righe; j++){
		radix_sort(v);


	}



	return 0;
}