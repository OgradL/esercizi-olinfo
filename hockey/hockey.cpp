#include <queue>
#include <vector>
#include <set>
using namespace std;

int squalifica(int N, vector<int> T, vector<int> L) {

	multiset<int> s;
	priority_queue<pair<int, int>> pq;

	T.push_back(2e9 + 2);

	for (int i = 0; i < N; i++){
		auto it = s.lower_bound(-L[i]);

		if (it != s.end())
			s.erase(it);

		pq.push({-(T[i] + L[i]), L[i]});

		while (!pq.empty() && -pq.top().first <= T[i+1]){
			auto [t, x] = pq.top();
			pq.pop();
			s.insert(-x);
		}
	}

	return s.size();
}
