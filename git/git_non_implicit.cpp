// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <limits>
#include <fstream>

using namespace std;

static constexpr long long LMAX = numeric_limits<long long>::max();
static constexpr long long LMIN = numeric_limits<long long>::min();

typedef long long ll;

ofstream coutbrutto("out.txt");

struct Node{
	ll sum;
	ll lazyAdd;
	// Node(){};
	Node(): sum(0), lazyAdd(0){};
	void join(const Node& a, const Node& b){
		sum = a.sum + b.sum;
	}
};

struct ST{

	int n, real_size;

	vector<Node> nodes;

	ST(){}

	ST(int N, vector<int>& A){

		real_size = 1;

		while (real_size < N)
			real_size *= 2;
		
		nodes.assign(2 * real_size, Node());

		build(1, 0, real_size, A);

	}

	void replace_data(int x, int y, vector<Node>& A){
		build_2(1, 0, real_size, x, y, A);
	}

	void build_2(int u, int l, int r, int x, int y, vector<Node>& A){

		fixLazy(u, l, r);

		if (x >= r || y <= l) return;

		if (l >= x && r <= y) nodes[u] = A[u];

		if (r-l>1){
			build_2(u * 2, l, (l+r)/2, x, y, A);
			build_2(u*2+1, (l+r)/2, r, x, y, A);
			nodes[u].join(nodes[u*2], nodes[u*2+1]);
		}
	}

	void build(int u, int l, int r, vector<int>& A){

		if (r-l<=1){
			if (l < A.size()){
				nodes[u].sum = A[l];
			} else {
				nodes[u].sum = 0;
			}
		} else {
			build(u * 2, l, (l+r)/2, A);
			build(u*2+1, (l+r)/2, r, A);
			nodes[u].join(nodes[u*2], nodes[u*2+1]);
		}

	}

	void fixLazy(int u, int l, int r){

		nodes[u].sum += nodes[u].lazyAdd * (r - l);

		if (r-l>1){
			nodes[u * 2].lazyAdd += nodes[u].lazyAdd;
			nodes[u*2+1].lazyAdd += nodes[u].lazyAdd;
		}
		nodes[u].lazyAdd = 0;
	}

	void fixLazyAll(int u, int l, int r){
		fixLazy(u, l, r);
		if (r-l<=1) return;
		fixLazyAll(u * 2, l, (l+r)/2);
		fixLazyAll(u*2+1, (l+r)/2, r);
	}


	ll get_sum(int u, int l, int r, int x, int y){

		fixLazy(u, l, r);

		if (x >= r || y <= l) return 0;

		if (l >= x && r <= y) return nodes[u].sum;

		return
			get_sum(u * 2, l, (l+r)/2, x, y) + 
			get_sum(u*2+1, (l+r)/2, r, x, y);
	}

	ll get_sum(int x, int y){
		return get_sum(1, 0, real_size, x, y);
	}


	void add(int u, int l, int r, int x, int y, int val){
		
		fixLazy(u, l, r);
		
		if (x >= r || y <= l) return;

		if (l >= x && r <= y) {nodes[u].lazyAdd += val; fixLazy(u, l, r); return;}
		
		add(u * 2, l, (l+r)/2, x, y, val);
		add(u*2+1, (l+r)/2, r, x, y, val);
		
		nodes[u].join(nodes[u*2], nodes[u*2+1]);
	}

	void add(int x, int y, int val){
		add(1, 0, real_size, x, y, val);
	}


	void print(){
		fixLazyAll(1, 0, real_size);
		coutbrutto << "tree: \n";
		int ji = 1;
		int l = 2;
		for (int i = 1; i < nodes.size(); i++){
			coutbrutto << nodes[i].sum << " ";
			ji++;
			if (ji == l){
				l *= 2;
				coutbrutto << "\n";
			}
		}
	}

	void print(string& s){
		fixLazyAll(1, 0, real_size);
		coutbrutto << s << ":\n";
		int ji = 1;
		int l = 2;
		for (int i = 1; i < nodes.size(); i++){
			coutbrutto << nodes[i].sum << " ";
			ji++;
			if (ji == l){
				l *= 2;
				coutbrutto << "\n";
			}
		}
	}

};

ST segtree;
vector<vector<Node>> versions;

void inizia(int N, vector<int> A){
	segtree = ST(N, A);
	segtree.print();
}

void incrementa(int l, int r, int x){
	versions.push_back(segtree.nodes);
	segtree.add(l, r, x);
	// cout << "quie\n";
	segtree.print();
}

void resetta(int l, int r, int v){
	// cout << "working " << versions.size() << "\n";
	versions.push_back(segtree.nodes);
	segtree.replace_data(l, r, versions[v]);
	// cout << "wok\n";
	segtree.print();
}

long long somma(int l, int r){
	segtree.print();
	return segtree.get_sum(l, r);
}

/*

11 7
7 2 1 9 3 5 3 6 2 8 7
2 1 5
0 2 6 4
0 7 9 -2
1 2 5 1
2 3 5
1 6 10 2
2 0 9
->
15
20
50


4 7
1 2 3 4
2 0 2
2 2 4
0 0 4 1
0 0 4 -1
2 0 4
1 0 4 1
2 0 4
->
3
7
10
14


*/