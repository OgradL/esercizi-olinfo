#include <vector>
#include <algorithm>
using namespace std;

vector<int> verifica(int N, vector<int> T) {

	vector<int> indici(N);
	for (int i = 0; i < N; i++)
		indici[i] = i;
	
	sort(indici.begin(), indici.end(), [&](int a, int b){
		return T[a] < T[b];
	});

	vector<int> ans;
	ans.reserve(N);
	ans.push_back(indici[0]);
	int t = 0, bigT = 1;
	int i = indici[0], j = indici[0];

	while (bigT < N){
		int x = indici[bigT++];

		if (i <= x && x <= j)
			continue;
		
		if (x < i){
			if (t + i - x > T[x])
				return {};
			
			for (i--; i >= x; i--)
				ans.push_back(i), t++;
			i = x;
		} else {
			if (t + x - j > T[x])
				return {};
			
			for (j++; j <= x; j++)
				ans.push_back(j), t++;
			j = x;
		}
	}

	return ans;
}
