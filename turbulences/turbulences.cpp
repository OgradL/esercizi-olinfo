#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long revenue(int N, int K, vector<long long> A){

	sort(A.begin(), A.end(), [](long long a, long long b){
		return abs(a) < abs(b);
	});

	long long p = 0, n = 0, z = 0;
	for (long long x : A){
		if (x < 0)
			n++;
		if (x > 0)
			p++;
		else
			z++;
	}

	long long sum = 0;
	long long ans = 0;

	for (int i = 0; i < N; i++){
		sum += A[i];
		if (A[i] < 0)
			n--;
		if (A[i] > 0)
			p--;
		else
			z--;
		ans = max(ans, sum + abs(A[i]) * (p - n - K));
	}

	return ans;
}