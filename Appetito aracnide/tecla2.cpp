#include <bits/stdc++.h>

using namespace std;


int calc(int node, int dist, vector<vector<int> >& graph, vector<vector<int> >& dist){
	
	for (int i = 0; i < graph[node].size(); i++){
		
		int newNode = graph[node][i];
		
		
	}
}



int main(){
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int N, M;
	
	cin >> N >> M;
	
	vector<vector<int> > graph(N, vector<int>(0));
	
	vector<vector<int> > dists(N, vector<int>(0));
	
	vector<string> path_andata(N);
	vector<string> path_ritorno(N);
	
	for (int i = 0; i < M; i++){
		int A, B;
		
		cin >> A >> B;
		
		graph[A].push_back(B);
		
		graph[B].push_back(A);
		
	}
	
	
	
	cout << 4 << "\n" << "6 1 scemo se pensi che questa sia la risposta" << "\n";
	
	
	return 0;
}
