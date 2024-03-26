#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
using namespace std;

bool cmp(pair<long long, int>& a, pair<long long, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first >= b.first;
}

int main(){

	int N;
	cin >> N;

	vector<int> A(N), B(N), C(N);
	for(int i = 0; i < N; i++){
		cin >> A[i] >> B[i] >> C[i];
	}

	int Q;
	cin >> Q;
	while (Q--){
		int p;
		long long t; 
		cin >> p >> t;
		p--;

		vector<pair<long long, int>> cars(N);
		for (int i = 0; i < N; i++) {
			cars[i].second = i;
			cars[i].first = A[i] * t * t + B[i] * t + C[i];
		}

		nth_element(cars.begin(), cars.begin() + p, cars.end(), cmp);
		cout << cars[p].second+1 << '\n';
	}
}