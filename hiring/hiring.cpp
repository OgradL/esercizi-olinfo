#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct operaio{
	long long s, q;
	int idx;

	bool operator<(const operaio& a) const{
		return q < a.q;
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	long long N, B;
	cin >> N >> B;

	vector<operaio> op(N);
	long long S, Q;
	for (int i = 0; i < N; i++){
		cin >> S >> Q;
		op[i] = (operaio){S, Q, i+1};
	}

	sort(op.begin(), op.end(), [](operaio& a, operaio& b){
		return a.s * b.q < b.s * a.q;
	});
	
	priority_queue<operaio> pq;
	long long rappa = 0, rappb = 1, qualifiche = 0, count = 0;
	int ans_it;
	long long ansa = 0, ansb = 1, anscount = 0;
	int it = 0;
	for (operaio& x : op){
		rappa = x.s;
		rappb = x.q;
		qualifiche += x.q;
		count++;
		pq.push(x);
		while (!pq.empty() && (rappa * qualifiche > B * rappb)){
			qualifiche -= pq.top().q;
			count--;
			pq.pop();
		}
		if ((count > anscount) || ((count == anscount) && (rappa * qualifiche * ansb < ansa * rappb))){
			ans_it = it;
			ansa = rappa * qualifiche;
			ansb = rappb;
			anscount = count;
		}
		++it;
	}

	pq = priority_queue<operaio>();
	priority_queue<operaio> ans;
	it = 0;
	qualifiche = 0;
	for (operaio& x : op){
		rappa = x.s;
		rappb = x.q;
		qualifiche += x.q;
		count++;
		pq.push(x);
		while (!pq.empty() && (rappa * qualifiche > B * rappb)){
			qualifiche -= pq.top().q;
			count--;
			pq.pop();
		}
		if (it == ans_it){
			ans = pq;
			break;
		}
		++it;
	}

	vector<int> indexes;
	for (;ans.size();){
		indexes.push_back(ans.top().idx);
		ans.pop();
	}
	sort(indexes.begin(), indexes.end(), [](int a, int b){
		return a < b;
	});

	cout << indexes.size() << "\n";
	for (int x : indexes)
		cout << x << "\n";

	return 0;
}