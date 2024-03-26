//Scrivi qui il tuo codice
/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <iostream>
#include <vector>

using namespace std;

// input data
int N, M, V;
vector<int> H;

int main() {
//  uncomment the following lines if you want to read/write from files
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> N >> M >> V;
	H.resize(N);
	for (int i=0; i<N; i++)
		cin >> H[i];
	
	int energy = M / 2 * V * V;
	int diff = 0;
	int current = 0;
	int count = 0;
	
	for (int j = 0; j < N; j++){
		count = j;
		energy = M / 2 * V * V;
		for (int i = j; i < N - 1; i++){
			diff = H[i] - H[i + 1];
			current = diff * M * 10;
			energy += current;
			//cout << diff << " " << current << " " << energy << "\n";
			if (energy < 0)
				break;
			count = i + 1;
			
		}
		
		cout << count << " ";
		
	}
	
	return 0;
}