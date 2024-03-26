#include <bits/stdc++.h>
#include <tuple>


using namespace std;

int N, M, T;
vector<int> A, B, C, E;

int main() {
    
    
    cin >> N >> M >> T;
    A.resize(M);
    B.resize(M);
    C.resize(M);
    E.resize(M);
    for (int i=0; i<M; i++)
        cin >> A[i] >> B[i] >> C[i] >> E[i];
    
    
    vector<pair<int, int> > adj[N];
    //adj.resize(0);
    
    for (int i = 0; i < M; i++){
        
        adj[A[i]].push_back({B[i], C[i]});
        
    }
    
    
    vector<tuple<int,int,int>> edges;
    edges.resize(0);
    
    for (int i = 0; i < N; i++){
        int siz = adj[i].size();
        for (int j = 0; j < siz; j++){
            cout << "node " << i << " to " << adj[i][j].first << "\n";
            edges.push_back(make_tuple(i, adj[i][j].first, adj[i][j].second)); 
        }
        //cout << adj[i]
    }
    
    vector<int> distance;
    distance.resize(N);
    
    for (int i = 1; i <= n; i++) distance[i] = INF;
		distance[x] = 0;
		for (int i = 1; i <= n-1; i++) {
			for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			distance[b] = min(distance[b], distance[a]+w);
		}
	}
    
    
    for (int i = 0; i < M; i++){
    	cout << i << " " << distance[i] << "\n";
	}
    
    
    //edges[1] = {1,2};
    //cout << adj[1].first;
    
}
