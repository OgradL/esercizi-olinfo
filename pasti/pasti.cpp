#include <vector>
#include <bitset>
using namespace std;

int dividi(int N, vector<int> V) {
	bitset<10001> b1;
	b1[0] = 1;

	long long sum = 0;
	for (int x : V){
		b1 |= b1 << x;
		sum += x;
	}

	long long best = b1._Find_next((sum-1)/2);

	return abs(sum - 2 * best);
}
