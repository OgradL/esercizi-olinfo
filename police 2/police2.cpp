#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
	
	#ifdef INPUT
	freopen("input1.txt", "r", stdin);
	#endif
	#ifdef EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int N;
	cin >> N;
	
	vector<int> H(N);
	
	for (int i = 0; i < N; i++){
		cin >> H[i];
	}
	
	vector<int> v(N, -1);
	
	for (int i = 0; i < N; i++){
		
		if (v[i] != -1){
			continue;
		}
		
		int siz = 1;
		int h = i;
		while(1){
			
			
			if (v[h] != -1){
				break;
			}

			v[h] = max(v[h], siz);
			
			h = H[h];
			
			
			siz++;
		}
		
		if (siz == -1) continue;
		
		h = H[h];
		
	}
	
	
	
	int m = 0;
	
	for (int i = 0; i < N; i++){
		cout << v[i] << " ";
		m = max(m, v[i]);
	}
	cout << "\n";
	
	cout << m - 1 << "\n";
	
	return 0;
}
