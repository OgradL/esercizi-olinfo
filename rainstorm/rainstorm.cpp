#include <bits/stdc++.h>

using namespace std;

void search(int node, vector<vector<pair<int, int> > >& nodes, vector<bool>& visi, int x){
	
	visi[node] = true;
	
	for (int i = 0; i < nodes[node].size(); i++){
		pair<int, int> newIdx = nodes[node][i];
		if (newIdx.second >= x && !visi[newIdx.first]){
			search(newIdx.first, nodes, visi, x);
		}
		
	}
	
}


int main(){
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int N, M;
	
	cin >> N >> M;
	
	vector<int> A(M), B(M), R(M), H(M);
	
	vector<vector<pair<int, int> > > nodes(N);
	
	vector<bool> visi(N, false);
	
	for (int i = 0; i < M; i++){
		cin >> A[i] >> B[i] >> R[i];
		H[i] = R[i];
		nodes[A[i]].push_back(make_pair(B[i], R[i]));
		nodes[B[i]].push_back(make_pair(A[i], R[i]));
	}
	
	sort(H.begin(), H.end());
	
	int lo = 0, hi = H.size() - 1;
	
	while (lo + 1 < hi){
		int mid = (lo + hi) / 2;
		int x = H[mid];
		
		for (int i = 0; i < N; i++){
			visi[i] = false;
		}
		
		search(0, nodes, visi, x);
		
		bool good = true;
		for (int i = 0; i < N; i++){
			if (!visi[i]){
				good = false;
				break;
			}
		}
		
		if (good){
			lo = mid;
		} else {
			hi = mid;
		}
		
	}
	
	cout << H[lo] << "\n";
	
	return 0;
}
