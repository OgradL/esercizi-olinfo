#include <iostream>
using namespace std;

int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N, M;
	cin >> N >> M;
	
	int pos[35], cla[35], n;
	for (int i = 1; i <= N; i++){
		cin >> n;
		pos[n] = i;
		cla[i] = n;
	}
	
	int a, b;
	for (int i = 1; i <= M; i++){
		cin >> a >> b;
		swap(cla[pos[a]], cla[pos[b]]);
		swap(pos[a], pos[b]);
	}
	
	cout << cla[1] << "\n";
	
	return 0;	
}