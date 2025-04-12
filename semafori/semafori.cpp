#include <iostream>
#include <vector>
#include <array>
using namespace std;

int traffico(int N, vector<int> S) {

	array<int, 2> dp = {0, 0};

	for (int x : S){
		dp = {dp[1] + ((x & 1) == 0), dp[0] + ((x & 1) == 1)};
	}

	return min(dp[0], dp[1]);
}
