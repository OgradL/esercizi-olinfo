#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

struct Node{
	int mi, ma;
	Node(){
		mi = 1e9;
		ma = -1e9;
	}
	Node(int v){
		mi = ma = v;
	}
	Node(int m, int a): mi(m), ma(a) {}
	void merge(const Node& a, const Node& b){
		mi = min(a.mi, b.mi);
		ma = max(a.ma, b.ma);
	}
};

struct ST{

	vector<Node> nodes;
	int real_size, n;

	ST(){
		// cool
	}

	ST(vector<int>& V){
		n = V.size();

		real_size = 1<<(int)ceil(log2(n));

		nodes.assign(2 * real_size, Node());

		build(1, 0, real_size, V);
	}

	void build(int u, int l, int r, vector<int>& V){
		if (r - l == 1){
			if (l < n)
				nodes[u] = Node(V[l]);
		} else {
			build(u * 2, l, (l+r)/2, V);
			build(u*2+1, (l+r)/2, r, V);
			nodes[u].merge(nodes[u*2], nodes[u*2+1]);
		}
	}

	int at(int x){
		return nodes[real_size + x].mi;
	}

	void update(int x, int v){

		int u = real_size + x;
		nodes[u] = Node(v);
		while (u > 1){
			u /= 2;
			nodes[u].merge(nodes[u*2], nodes[u*2+1]);
		}
	}


	int get_min(int u, int l, int r, int x, int y){
		if (y <= l || r <= x) return 1e9;
		if (x <= l && r <= y) return nodes[u].mi;
		return min(
			get_min(u * 2, l, (l+r)/2, x, y),
			get_min(u*2+1, (l+r)/2, r, x, y)
		);
	}

	int get_min(int x, int y){
		return get_min(1, 0, real_size, x, y);
	}


	int get_max(int u, int l, int r, int x, int y){
		if (y <= l || r <= x) return -1e9;
		if (x <= l && r <= y) return nodes[u].ma;
		return max(
			get_max(u * 2, l, (l+r)/2, x, y),
			get_max(u*2+1, (l+r)/2, r, x, y)
		);
	}

	int get_max(int x, int y){
		return get_max(1, 0, real_size, x, y);
	}


	void print(){
		cout << "\nSEGTREE:\n";
		int i = 1, j = 2;
		for (i = 1; i < nodes.size(); ){
			cout << "[ " << nodes[i].mi << " " << nodes[i].ma << " ]" << " ";
			i++;
			if (i == j){
				cout << "\n";
				j <<= 1;
			}
		}
		cout << "\n";
	}
};

vector<set<int>> balls;
ST ball, succ;
vector<int> prec;
int N;
void inizio(int N, int M, int sfere[]){
	::N = N;
	balls = vector<set<int>>(N+1);
	vector<int> bal(N), suc(N, 1e6), pos(N+1, -1);
	prec.assign(N, -1);
	for (int i = 0; i < N; i++){
		bal[i] = sfere[i];
		prec[i] = pos[sfere[i]];
		if (prec[i] != -1)
			suc[prec[i]] = i;
		pos[sfere[i]] = i;
		balls[sfere[i]].insert(balls[sfere[i]].end(), i);
	}
	ball = ST(bal);
	succ = ST(suc);
}

void modifica(int posizione, int valore){
	
	int pre = prec[posizione];
	int suc = succ.at(posizione);
	
	if (pre != -1){
		succ.update(pre, suc);
	}
	if (suc < N)
		prec[suc] = pre;
	
	int prev_n = ball.at(posizione);
	balls[prev_n].erase(balls[prev_n].find(posizione));

	ball.update(posizione, valore);
	
	auto x = balls[valore].lower_bound(posizione);
	
	if (balls[valore].size() == 0){
		prec[posizione] = -1;
		succ.update(posizione, 1e6);
	} else if (x != balls[valore].end()){
		pre = prec[*x];
		prec[*x] = posizione;
		prec[posizione] = pre;
		succ.update(posizione, *x);
		if (pre != -1){
			succ.update(pre, posizione);
		}
	} else if (x == balls[valore].end()){
		x = prev(x);
		prec[posizione] = *x;
		succ.update(*x, posizione);
		succ.update(posizione, 1e6);
	} else {
		
	}
	
	balls[valore].insert(posizione);
}

bool verifica(int l, int r){
	return (succ.get_min(l, r+1) >= r) && (ball.get_max(l, r+1) == r-l+1);
}
