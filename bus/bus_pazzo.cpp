#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <random>
using namespace std;

const static constexpr int MAX = numeric_limits<int>::max();
const static constexpr int MIN = numeric_limits<int>::min();


node get(unordered_map<int, node>& map, int pos){
    node ans;
    try
    {
        ans = map[pos];
    }
    catch (const std::exception& e)
    {
        return node(MAX);
    }
    return map[pos];
}


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

    //steps[0] = 0;

    priority_queue<node> pq;

    for (int i = 0; i < adj[0].size(); i++){
        pq.push(node(0, adj[0][i].linea, 0, 0));
    }
    // int co = 0, co2 = 0;
    //cerr << pq.empty() << "\n";
    while (!pq.empty()){
        //cerr << pq.size() << "\n";
        node n = pq.top();
        pq.pop();
        if (n.nodo == N - 1) break;
		if (n.step > N) break;
        //cout << n.nodo << " " << n.linea << " " << n.step << " " << n.from << "\n";
        //cout << adj[n.nodo].size() << "\n";
		// if (rand() - 5 == 0 && rand() % 100 == 0) {
		// 	cout << co << " " << co2 << " " << n.step << " " << steps[N-1].step << "\n";
		// 	cout << n.nodo << " " << n.linea << " " << n.step << "\n\n";
		// 	cout.flush();
		// }
        //cout << steps[n.nodo] << " \n";
		
        //if (steps[n.nodo] > n.step) steps[n.nodo] = n.step;
        //else continue;
        //cerr << "hi\n";
        for (int i = 0; i < adj[n.nodo].size(); i++){
            node x = adj[n.nodo][i];
			int somma = n.step + int(n.linea != x.linea);
            //cerr << "info " << x.nodo << " " << x.linea << " " << x.step << " ";
            //cerr << "steps" << steps[x.nodo] << "\n";
            if (somma < steps[x.nodo].step || (x.linea != steps[x.nodo].linea && somma <= steps[x.nodo].step)){
                //cerr << "hi2\n";
                bool good = false || (F[x.linea].size() <= 2) || (n.from == 0) || (F[x.linea][0] == n.nodo);
                if (x.from == n.from) good = true;
                // for (int i = 0; i < F[x.linea].size() - 2; i++){
                //     if (F[x.linea][i] == n.from && F[x.linea][i + 1] == n.nodo && F[x.linea][i + 2] == x.nodo){
                //         good = true;
                //     }
                // }
                // if (steps[x.nodo].step == MAX) co++; co2++;
                if (good){
                    steps[x.nodo].step = somma;
                    pq.push(node(x.nodo, x.linea, n.step + int(n.linea != x.linea), n.nodo));
                } else {
                    steps[x.nodo].step = n.step + 1;
                    pq.push(node(x.nodo, x.linea, n.step + 1, n.nodo));
                }
                //cerr << "hi3\n";
            }
        }
    }


}

int pianifica(int N, int L, vector<vector<int> > F) {
    
    
    unordered_map<int, int> pod;

    

    vector<unordered_map<int, node>> steps(N);
    // for (node &n: steps){
    	// n.step = MAX;
	// }
    

    dijkstra(N, L, F, steps);


    if (steps[N - 1].step == MAX) {
        steps[N - 1].step = -1;
    }
    return steps[N - 1].step;
}