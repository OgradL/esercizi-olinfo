#include <bits/stdc++.h>

using namespace std;

bool jimmy(int ce, int st, int N, vector<vector<pair<int, int> > >& tab, vector<int>& m, vector<vector<int> >& solved){
	
	cout << ce << " " << st << " " << solved[ce][st] << "\n";
	
	if (ce <= 0) return true;
	
	if (solved[ce][st] == 1) return false;
	
	if (solved[ce][st] == 2) return true;
	
	cout << "si\n";
	
	solved[ce][st] = 1;
	
	bool tmp = jimmy(ce + tab[st][m[ce]].second, tab[st][m[ce]].first, N, tab, m, solved);
	
	if (tmp) solved[ce][st] = 2;
	cout << "ritorno\n";
	
	return tmp;
}


int main(){
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int N, S, C;
	
	cin >> N >> S >> C;
	
	vector<vector<pair<int, int> > > tab(S, vector<pair<int, int> >(C));
	
	vector<int> m(N);
	
	int a, b, c, d;
	
	for (int i = 0; i < S * C; i++){
		cin >> a >> b >> c >> d;
		
		tab[a][b] = make_pair(c, d);
	}
	
	for (int i = 0; i < N; i++){
		cin >> m[i];
	}
	
	vector<vector<int> > solved(N, vector<int>(S, 0));
	solved[0][0] = 2;
	
	for (int i = 0; i < N; i++){
		cout << "\n\n";
		bool c = jimmy(i, 0, N, tab, m, solved);
	}
	int ount = 0;
	for (int i = 0; i < N; i++){
		if (solved[i][0] == 2) ount++;
	}
	cout << "\n" << ount << "\n";
	for (int i = 0; i < N; i++){
		if (solved[i][0] == 2) cout << i << "\n";
	}
	
	
	return 0;
}
