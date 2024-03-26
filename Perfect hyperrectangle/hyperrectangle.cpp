#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int N;
	cin >> N;

	vector<int> V(2 * N);

	for (int &n : V)
		cin >> n;

	sort(V.begin(), V.end());

	for (int i = 0; i < N; i++)
		cout << i << " ";
	
	for (int i = N; i < 2 * N; i++)
		cout << i << " ";

	return 0;
}