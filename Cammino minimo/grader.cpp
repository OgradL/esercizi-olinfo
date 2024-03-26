#include <bits/stdc++.h>

using namespace std;

#define MAXUINT 429467296

typedef unsigned int uint;


struct arch{
	int a;
	int b;
	int p;
};

struct node{
	vector<arch> archi;
};



void search(int N, int M, int curNode, uint dist, vector<node>& nodes, vector<uint>& dists){
	
	dists[curNode] = dist;
//	cout << "visto " << curNode << " con dist " << dist << "\n";
	
	for (int i = 0; i < nodes[curNode].archi.size(); i++){
		if (dists[nodes[curNode].archi[i].b] > dist + nodes[curNode].archi[i].p){
			search(N, M, nodes[curNode].archi[i].b, dist + nodes[curNode].archi[i].p, nodes, dists);
		}
	}
	
}



void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D) {
	
	vector<uint> dists(N, MAXUINT);
	
	dists[0] = 0;
	
	vector<node> nodes(N);
	
	for (int i = 0; i < M; i++){
		arch arco;
		arco.a = X[i];
		arco.b = Y[i];
		arco.p = P[i];
		nodes[arco.a].archi.push_back(arco);
	}
	
	search(N, M, 0, 0, nodes, dists);
	
    for(int i = 0; i < N; i++) {
        D[i] = dists[i];
        if (D[i] == MAXUINT){
        	D[i] = -1;
		}
    }
}

int main() {
    ios::sync_with_stdio(false);

    // Uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    // Reading input
    int N, M;
    cin >> N >> M;

    vector<int> X(M), Y(M), P(M), D(N);
    for (int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i] >> P[i];
    }

    // Calling functions
    mincammino(N, M, X, Y, P, D);

    // Writing output
    for(int i = 0; i < D.size(); i++) {
        cout << D[i] << " ";
    }
    cout << endl;

    return 0;
}
