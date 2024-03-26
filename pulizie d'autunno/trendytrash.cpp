#include <bits/stdc++.h>

using namespace std;

long long fast_pow(long long b, long long e, int &iterations){
	iterations++;
	if (e <= 0) return 1;
	if (e % 2 == 0){
		long long num = fast_pow(b, e/2, iterations);
		return num*num;
	} else {
		return b * fast_pow(b, e-1, iterations);
	}
}
long long fast_pow(long long b, long long e){
	if (e <= 0) return 1;
	if (e % 2 == 0){
		long long num = fast_pow(b, e/2);
		return num*num;
	} else {
		return b * fast_pow(b, e-1);
	}
}


float log(int b, float v){
	
	float lo = 0;
	float hi = 20;
	
//	cout << lo << " " << lo + 0.00001 << " " << hi << "\n";
	
	while (lo + 0.000001 < hi){
		float mid = (lo + hi) / 2;
//		cout << mid << "\n";
		
		float va = pow(b, mid);
		
		if (va == v) return mid;
		if (va < v){
			lo = mid;
		} else {
			hi = mid;
		}
	}
	
	return lo;
}

typedef long long ll;
typedef pair<int, int> pairi;

static constexpr long long MIN = numeric_limits<long long>::min();
static constexpr long long MAX = numeric_limits<long long>::max();

/*
struct ST{
	
	struct Node{
		
		int black;
		int blue;
		int addBlue;
		int addBlack;
		
		Node(){
			black = 0;
			blue = 0;
			addBlue = 0;
			addBlack = 0;
		}
		void join(const Node &l, const Node &r){
			
		}
	};
	
	int n, real_size;
	vector<Node> nodes;
	
	vector<Node> actual;
	
	ST(vector<ll> data){
		
		n = data.size();
		
		real_size = 1;
		while (real_size < n)
			real_size *= 2;
		
		nodes.assign(2 * real_size, Node());
		
		build(1, 0, real_size, data);
	}
	
	ST(){
		// cool
	}
	
	void fixLazy(int u, int l, int r){
		
		if (nodes[u].lazyAdd == 0 && nodes[u].lazySet == MIN) return;
		
		if (nodes[u].lazySet != MIN) {
			nodes[u].mi = nodes[u].lazySet;
			nodes[u].sum = nodes[u].lazySet * (r - l);
			
			if (u < real_size){
				nodes[u*2].lazySet = nodes[u].lazySet;
				nodes[u*2].lazyAdd = 0;
				
				nodes[u*2+1].lazySet = nodes[u].lazySet;
				nodes[u*2+1].lazyAdd = 0;
			}
			nodes[u].lazySet = MIN;
		}
		if (nodes[u].lazyAdd != 0){
			nodes[u].mi += nodes[u].lazyAdd;
			nodes[u].sum += nodes[u].lazyAdd * (r - l);
			
			if (u < real_size){
				nodes[u*2].lazyAdd += nodes[u].lazyAdd;
				
				nodes[u*2+1].lazyAdd += nodes[u].lazyAdd;
			}
			nodes[u].lazyAdd = 0;
		} 
		
	}
	
	void build(int u, int l, int r, vector<ll>& data){
		
		if (r - l == 1){
			if (l < data.size()){
				nodes[u].mi = data[l];
				nodes[u].sum = data[l];
			} else {
				nodes[u].mi = MAX;
				nodes[u].sum = 0;
			}
		} else {
			build(2*u, l, (l+r)/2, data);
			build(2*u+1, (l+r)/2, r, data);
			nodes[u].join(nodes[2*u], nodes[2*u+1]);
		}
		
	}
	
	void update(int pos, int x){
		
		int u = real_size + pos;
		nodes[u].mi = x;
		nodes[u].sum = x;
		
		while(u > 1){
			
			u /= 2;
			nodes[u].join(nodes[2*u], nodes[2*u+1]);
			
		}
		
	}
	
	ll getmin(int u, int l, int r, int x, int y){
		fixLazy(u, l, r);
		if (x >= r || y <= l) return MAX;
		
		if (l >= x && r <= y) return nodes[u].mi;
		
		return min(
			getmin(2*u, l, (l+r)/2, x, y),
			getmin(2*u+1, (l+r)/2, r, x, y)
		);
		
	}
	
	ll getmin(int x, int y){
		
		return getmin(1, 0, real_size, x, y);
		
	}
	
	
	// get sum
	
	ll getsum(int u, int l, int r, int x, int y){
		fixLazy(u, l, r);
		if (x >= r || y <= l) return 0;
		
		if (l >= x && r <= y) return nodes[u].sum;
		
		return getsum(2*u, l, (l+r)/2, x, y) + getsum(2*u+1, (l+r)/2, r, x, y);
		
	}
	
	ll getsum(int x, int y){
		
		return getsum(1, 0, real_size, x, y);
		
	}
	
	
	// set range
	
	void setrange(int u, int l, int r, int x, int y, ll num){
		fixLazy(u, l, r);
		if (x >= r || y <= l) return;
		
		if (l >= x && r <= y) {
			nodes[u].lazySet = num;
			nodes[u].lazyAdd = 0;
			fixLazy(u, l, r);
			return;
		}
		
		
		setrange(2*u, l, (l+r)/2, x, y, num);
		setrange(2*u+1, (l+r)/2, r, x, y, num);
		nodes[u].join(nodes[2*u], nodes[2*u+1]);
		
	}
	
	void setrange(int x, int y, ll num){
		
		setrange(1, 0, real_size, x, y, num);
		
	}
	
	
	// add range
	
	void addrange(int u, int l, int r, int x, int y, ll num){
		fixLazy(u, l, r);
		if (x >= r || y <= l) return;
		
		if (l >= x && r <= y) {
			nodes[u].lazyAdd += num;
			fixLazy(u, l, r);
			return;
		}
		
		addrange(2*u, l, (l+r)/2, x, y, num);
		addrange(2*u+1, (l+r)/2, r, x, y, num);
		nodes[u].join(nodes[2*u], nodes[2*u+1]);
		
	}
	
	void addrange(int x, int y, ll num){
		
		addrange(1, 0, real_size, x, y, num);
		
	}
	
	
	// lower bound
	
	int lowerbound(int u, int l, int r, int x, int y, ll num){
		fixLazy(u, l, r);
//		cout << "help " << u << " " << l << " " << r << "\n";
		if (y <= l || x >= r || nodes[u].mi > num) return -1;
//		cout << "eu\n";
		if (r - l <= 1){
			return l;
		}
		
		int le = lowerbound(u*2, l, (l+r)/2, x, y, num);
		if (le != -1) return le;
		
		int ri = lowerbound(u*2+1, (l+r)/2, r, x, y, num);
		return ri;
		
	}
	
	int lowerbound(int x, int y, ll num){
		
		return lowerbound(1, 0, real_size, x, y, num);
		
	}
	
	
	void print(){
		cout << "tree: \n";
		int ji = 1;
		int l = 2;
		for (int i = 1; i < nodes.size(); i++){
			cout << nodes[i].mi << " ";
			ji++;
			if (ji == l){
				l *= 2;
				cout << "\n";
			}
		}
	}
	
};
*/
int pulisci(int N, int M, vector<string> S){
	
	vector<pairi> rows(N);
	vector<pairi> cols(M);
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (S[i][j] == '1') {
				rows[i].first++;
				cols[j].first++;
			} else {
				rows[i].second++;
				cols[j].second++;
			}
		}
	}
	
	bool done = false;
	
	while (true){
		
		done = false;
		
		for (int i = 0; i < N; i++){
//			cout << "fs\n";
			if (rows[i].first == 0 && rows[i].second == 0) continue;
			if (!(rows[i].first == 0 || rows[i].second == 0)) continue;
//			cout << "ur\n";
			done = true;
			rows[i].first = 0;
			rows[i].second = 0;
			for (int j = 0; j < M; j++){
				if (S[i][j] == '1'){
					cols[j].first--;
				} else if (S[i][j] == '0'){
					cols[j].second--;
				}
				S[i][j] = '2';
			}
			
		}
		
		for (int i = 0; i < M; i++){
//			cout << "us\n";
			if (cols[i].first == 0 && cols[i].second == 0) continue;
			if (!(cols[i].first == 0 || cols[i].second == 0)) continue;
//			cout << "rt\n";
			done = true;
			cols[i].first = 0;
			cols[i].second = 0;
			for (int j = 0; j < N; j++){
				if (S[j][i] == '1'){
					rows[j].first--;
				} else if (S[j][i] == '0'){
					rows[j].second--;
				}
				S[j][i] = '2';
			}
			
		}
		
		if (!done) break;
		
	}
	
	int count = 0;
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (S[i][j] != '2'){
				count++;
			}
		}
	}
	
	return count;
	
}


int main(){
	
	int n, m;
	
	cin >> n >> m;
	
	vector<string> s(n);
	
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}
	
	cout << pulisci(n, m, s) << "\n";
	
	return 0;
}
