#include <bits/stdc++.h>

using namespace std;


int calculate(int A, int pos, int col, vector<vector<int> >& griglia, vector<vector<int> >& alt){
	
	if (alt[pos][col] == -1){
	int a = 0, b = 0;
	
	if (col < A - 1){
		a = calculate(A, pos + 1, col + 1, griglia, alt);
		
		b = calculate(A, pos, col + 1, griglia, alt);
	}
	
	alt[pos][col] =  max(a, b) + griglia[col][pos];
	}
	
	return alt[pos][col];
	
}





int main(){
	
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	
	int A;
	
	cin >> A;
	
	vector<vector<int > > piramide(A, vector<int>(A));
	
	vector<vector<int > > alt(A, vector<int>(A, -1));
	
	
	for (int i = 0; i < A; i++){
		for (int j = 0; j <= i; j++){
			cin >> piramide[i][j];
		}
	}
	
	
//	cout << "\n\n\n\n\n";
	
	int answer = calculate(A, 0, 0, piramide, alt);
	
	cout << answer << "\n";
	
	
	
//	for (int i = 0; i < A; i++){
//		for (int j = 0; j <= i; j++)
//			cout << piramide[i][j] << " ";
//		cout << "\n";
//	}
	
	
}
