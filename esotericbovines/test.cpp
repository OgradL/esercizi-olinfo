#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){


	vector<int> A = {3, 5, 6, 9, 20, 31};

	auto it0 = lower_bound(A.begin(), A.end(), 16, [](int a, int b){
		return (a & b) == 0;
	});

	cout << it0 - A.begin() << "\n";

	return 0;
}
