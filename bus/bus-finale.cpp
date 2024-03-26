#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <random>
#include <unordered_map>
using namespace std;

const static constexpr int MAX = numeric_limits<int>::max();
const static constexpr int MIN = numeric_limits<int>::min();


struct node{
	int nodo;
	int linea;
	int step;
	int from;
	node(){
		nodo = -1;
		linea = -1;
		step = -1;
		from = -1;
	}
	node(int n){
		nodo = -1;
		linea = -1;
		step = n;
		from = -1;
	}
	node(int n, int l, int f){
		nodo = n;
		linea = l;
		step = 0;
		from = f;
	};
	node(int n, int l, int s, int f){
		nodo = n;
		linea = l;
		step = s;
		from = f;
	};
	bool operator<(const node& a) const{
		return a.step < step;
	};
};


void dijkstra(int N, int L, vector<vector<int>>& F, vector<node>& steps){

	vector<vector<node>> adj(N);

	for (int i = 0; i < L; i++){
		adj[F[i][0]].push_back(node(F[i][1], i, 0, -1));
		for (int j = 2; j < F[i].size(); j++){
			adj[F[i][j-1]].push_back(node(F[i][j], i, 0, F[i][j-2]));
		}
	}

	priority_queue<node> pq;

	for (int i = 0; i < adj[0].size(); i++){
		pq.push(node(0, adj[0][i].linea, 0, 0));
	}
	
	vector<unordered_map<int, int>> stplin(N);

	while (!pq.empty()){
		node n = pq.top();
		pq.pop();
		if (n.nodo == N - 1) break;
		if (n.step > N) break;
		stplin[n.nodo][n.linea] = 1;

		for (int i = 0; i < adj[n.nodo].size(); i++){
			node x = adj[n.nodo][i];
			int somma = n.step + int(n.linea != x.linea);

			if (somma < steps[x.nodo].step || (!stplin[n.nodo][n.linea] && somma <= steps[x.nodo].step)){
				bool good = false || (F[x.linea].size() <= 2) || (n.from == 0) || (F[x.linea][0] == n.nodo);
				if (x.from == n.from) good = true;
				if (good){
					steps[x.nodo].step = somma;
					pq.push(node(x.nodo, x.linea, n.step + int(n.linea != x.linea), n.nodo));
				} else {
					steps[x.nodo].step = n.step + 1;
					pq.push(node(x.nodo, x.linea, n.step + 1, n.nodo));
				}
			}
		}
	}


}

int pianifica(int N, int L, vector<vector<int> > F) {
	
	
	vector<node> steps(N);
	for (node &n: steps){
		n.step = MAX;
	}
	

	dijkstra(N, L, F, steps);


	if (steps[N - 1].step == MAX)
		steps[N - 1].step = -1;
	
	return steps[N - 1].step;
}