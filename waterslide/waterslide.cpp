#include <bits/stdc++.h>

using namespace std;

float find_people(int j, vector<float>& J, vector<vector<int> >& parent, vector<vector<int> >& child){
	
//	cout << j << " start\n";
	
	if (J[j] != -1.0f){
//		cout << j << " already calculated\n";
		return J[j];
	}
	
	J[j] = 0.0f;
	
//	cout << J[j] << "\n";
	
	for (int i = 0; i < parent[j].size(); i++){
		
		int idx = parent[j][i];
		
		J[j] += find_people(idx, J, parent, child);
		
		
	}
//	cout << J[j] << "\n";
	
	int size = child[j].size();
	if (size == 0) size = 1;
	
	J[j] = float(J[j] / float(size));
	
//	cout << J[j] << "\n";
	
//	cout << j << " done\n";
	
	return J[j];
}



int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N, M, P;
	
	cin >> N >> M >> P;
	
	vector<float> J(N, -1.0f);
	J[0] = 100000.0f;
	
	vector<vector<int> > child(N, vector<int>(0));
	
	vector<vector<int> > parent(N, vector<int>(0));
	
	for (int i = 0; i < M; i++){
		int A, B;
		
		cin >> A >> B;
		
		child[A].push_back(B);
		
		parent[B].push_back(A);
		
	}
	
	J[0] /= float(child[0].size());
	
	int index = 0;
	float maxPool = 0;
	
	for (int i = N - P; i < N; i++){
		if (find_people(i, J, parent, child) > maxPool){
			index = i;
			maxPool = J[i];
		}
	}
	
	
//	for (int i = 0; i < N; i++){
//		cout << J[i];
//		if (i >= N - P){
//			cout << " pool";
//		}
//		cout << "\n";
//	}
	
	
	cout << index << "\n";
	
	return 0;
}
