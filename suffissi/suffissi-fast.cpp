#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main(){

	cin.tie(0);
	cin.sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> A(N);
	for (int &n : A) cin >> n;


	vector<int> pref(N, 1);
	unordered_map<int, int> nums;
	nums[A.back()] = 1;
	for (int i = N-2; i >= 0; i--){
		pref[i] = pref[i+1] + !nums[A[i]];
		nums[A[i]] = 1;
	}

	int b;
	while (M--){
		cin >> b;
		cout << pref[b-1] << "\n";
	}

	return 0;
}