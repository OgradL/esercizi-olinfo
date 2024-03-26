#include <iostream>
#include <queue>
using namespace std;

int GreatestHappiness(int N, int K, int *C){

	priority_queue<int, vector<int>, greater<int>> pq;

	int k = K+1;
	int e = 0;
	int ans = 0, ma = 0, m;
	while (e < N && (!pq.empty() || e == 0)){

		if (k >= 2){
			pq.push(C[e]);
			ma += C[e];
			e++;
			k -= 2;
		} else if (k == 1){
			m = pq.top();
			pq.pop();
			ma -= m;
			if (C[e] > m){
				pq.push(C[e]);
				ma += C[e];
			} else {
				ma += m;
				pq.push(m);
			}
			k--;
			e++;
		} else if (k == 0){
			m = pq.top();
			ma -= m;
			pq.pop();
			k++;
		}

		ans = max(ans, ma);
	}


	return ans;
}