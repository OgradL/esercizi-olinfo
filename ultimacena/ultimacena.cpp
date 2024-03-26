#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, sizes;

void DSU(int N){
	parent.assign(N+1, -1);
	sizes.assign(N+1, -1);
}

void make_set(int v){
	parent[v] = v;
	sizes[v] = 0;
}

int find_parent(int v){
	if (parent[v] == -1) make_set(v);
	if (v == parent[v]) return v;
	return parent[v] = find_parent(parent[v]);
}

int set_union(int a, int b){
	a = find_parent(a);
	b = find_parent(b);
	if (a != b){
		if (sizes[a] < sizes[b]){
			swap(a, b);
		}
		parent[b] = a;
		sizes[a] += sizes[b];
		return 1;
	}
	return 0;
}

int main(){

	int N, M;
	cin >> N >> M;

	DSU(N);

	int a, b;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		set_union(a, b);
	}

	vector<int> parents;
	for (int i = 1; i <= N; i++){
		if (i == find_parent(i))
			parents.push_back(i);
	}

	cout << parents.size() << "\n";
	for (auto p : parents) cout << p << " ";
	cout << "\n";

	return 0;
}