#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

vector<int> values;
void inizia(int N, vector<int> A){
	values = A;
}

void aggiorna(int P, int C){
	values[P] = C;
}

int consiglio(int L, int R, int K){
	if (K == 0)
		return -1;
	long long total_sum = 0;
	for (int i = L; i < R; i++)
		total_sum += values[i];
	long long ex = K * 1LL * (R - L);

	if (total_sum < ex)
		return 1;
	if (total_sum == ex)
		return 0;

	vector<int> v(R-L);
	for (int i = L; i < R; i++)
		v[i-L] = values[i];
	
	sort(v.rbegin(), v.rend());

	int ans = 0;
	for (int i = 0; i < v.size(); i++){
		total_sum -= v[i] - 1;
		ans++;
		if (total_sum <= ex)
			break;
	}

	return ans;
}
