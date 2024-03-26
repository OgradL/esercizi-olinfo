#include <iostream>
#include <vector>
using namespace std;

int main(){

	int N;
	cin >> N;

	vector<int> V(N);
	for (int& x : V)
		cin >> x;
	
	vector<int> pr(N), pl(N);
	pr[0] = V[0];
	pl[N-1] = V[N-1];
	for (int i = 1; i < N; i++){
		pr[i] = max(pr[i-1], V[i]);
		pl[N-i-1] = max(pl[N-i], V[N-i-1]);
	}

	vector<long long> poles;
	poles.reserve(N);
	for (int i = 0; i < N; i++){
		if (V[i] >= min(pr[i], pl[i]))
			poles.push_back(i);
	}

	long long ans = 0;
	for (int i = 0; i < poles.size()-1; i++){
		ans += min(V[poles[i]], V[poles[i+1]]) * (poles[i+1] - poles[i]);
	}

	cout << ans << "\n";

	return 0;
}