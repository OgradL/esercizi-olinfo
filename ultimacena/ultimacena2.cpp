#include <vector>
#include <set>

using namespace std;

const int MAXN = 50000;
const int MAXM = 100000;
const int MAXK = 10;

int n, m;
pair<int, int> edges[MAXM];
bool salta_arco[MAXM];
vector<int> G[MAXN];
bool found;
set<int> sol;

bool verifica_copertura(set <int> cope) {
	bool coperto[MAXM] = {};
	for (int v : cope)
		for (int i = 0; i < m; i++)
			if (edges[i].first == v or edges[i].second == v)
				coperto[i] = true;
	for (int i = 0; i < m; i++)
		if (!coperto[i])
			return false;
	return true;
}

void visit(int arco, set <int> cope) {
	if (salta_arco[arco])
		visit(arco + 1, cope);
	else {
		if (found)
			return;

		if (cope.size() == MAXK or arco == m) {
			if (verifica_copertura(cope)) {
				found = true;
				sol = cope;
			}
		} else {
			bool a_trovato = cope.find(edges[arco].first) != cope.end();
			bool b_trovato = cope.find(edges[arco].second) != cope.end();
			if (a_trovato or b_trovato)
				visit(arco + 1, cope);
			else {
				set<int> nuova_copertura_a = cope;
				set<int> nuova_copertura_b = cope;
				nuova_copertura_a.insert(edges[arco].first);
				nuova_copertura_b.insert(edges[arco].second);
				visit(arco + 1, nuova_copertura_a);
				visit(arco + 1, nuova_copertura_b);
			}
		}
	}
}

int riassumi(int N, int M, int A[], int B[], int S[]) {
	n = N;
	m = M;
	for (int i = 0; i < m; i++) {
		edges[i] = {A[i] - 1, B[i] - 1};
		G[A[i]-1].push_back(B[i]-1);
		G[B[i]-1].push_back(A[i]-1);
	}
	
	set<int> cope;
	for (int i = 0; i < n; i++)
		if (G[i].size() >= 11)
			cope.insert(i);
	
	for (int i = 0; i < m; i++)
		if (cope.find(edges[i].first) != cope.end() || cope.find(edges[i].second) != cope.end())
			salta_arco[i] = true;
	
	visit(0, cope);

	int i = 0;
	for (int v : sol)
		S[i++] = v + 1;
	return sol.size();
}