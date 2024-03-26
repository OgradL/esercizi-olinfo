#include <iostream>
#include <map>

using namespace std;

map<int, int> m;

int solve(int N, int* C, int index) {
	if (index == -1) {
		return 0;
	}
	auto search = m.find(index);
	if (search != m.end()) {
		return search->second;
	}
	int result = 1 + solve(N, C, C[index]);
	m[index] = result;
	return result;
}

int coppie(int N, int* C) {
	int result = 0;
	for (int i = 0; i < N; i++) {
		result += solve(N, C, C[i]);
	}
	return result;
}
