#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> bilancia(int N, int M, vector<vector<int>> S) {

	vector<int> count(M, 0);
	
	for (auto& x : S){
		for (int& y : x){
			count[y]++;
		}
	}

	vector<int> order(M);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int a, int b){
		return count[a] > count[b];
	});

	vector<int> inv(M);
	for (int i = 0; i < M; i++){
		inv[order[i]] = i;
	}

	for (auto& x : S){
		int sz = x.size();
		for (int& y : x){
			if (inv[y] >= sz){
				return {};
			}
		}
	}

	return order;
}
