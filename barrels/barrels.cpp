#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
void DSU(int N){
	parent.assign(N+1, 0);
	for (int i = 0; i <= N; i++){
		parent[i] = i;
	}
}
int find_parent(int v){
	if (parent[v] == v) return v;
	return parent[v] = find_parent(parent[v]);
}

int main(){

	cin.tie(0);
	cin.sync_with_stdio(false);
	cout.tie(0);
	cout.sync_with_stdio(false);

	int N, T;
	cin >> N >> T;

	DSU(N);
	
	vector<int> C(N), B(N, 0);
	for (int &n : C)
		cin >> n;
	
	int v;
	int k, u, q;
	char op;
	while (T--){
		cin >> op;
		if (op == 'P'){
			cin >> k >> u;
			while (k && u != N){
				v = min(k, C[u] - B[u]);
				B[u] += v;
				k -= v;
				if (B[u] == C[u])
					parent[u] = find_parent(u+1);
				u = find_parent(u);
			}
		}
		if (op == 'M'){
			cin >> q;
			cout << B[q] << "\n";
		}
	}


	return 0;
}