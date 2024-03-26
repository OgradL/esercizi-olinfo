#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;

int main(){
	srand(time(NULL));

	int N = 1000000, K = rand() % (N-100)+100;
	cout << N << ' ' << K << "\n";

	for (int i = 0; i < N; i++)
		cout << rand() % 179 + 1 << ' ';

	return 0;
}