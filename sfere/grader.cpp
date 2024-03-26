#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int MAXM = 1e5;

void inizio(int N,int M, int sfere[]);
void modifica(int posizione,int valore);
bool verifica(int l,int r);

int main() {
	
	int sfere[MAXN], N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> sfere[i];
	
	inizio(N, M, sfere);

	for (int i = 0; i < M; i++){
		int tipo, a, b;
		cin >> tipo >> a >> b;
		if (tipo == 1)
			cout << (int)verifica(a, b) << '\n';
		else
			modifica(a, b);
	}
	return 0;
}