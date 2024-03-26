#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void riprogramma(int N, int K, vector<int>& C) {
	for (int i = 0; i < N; i++) {
		
		//cout << i << "\n";
		
		if (i == 0){
			//cout << "1\n";
			if (C[i] == C[i + 1]){
				for (int j = 1; j <= K; j++)
					if (j != C[i + 1]){
						C[i] = j;
						break;
					}
			
			}
		} else if (i == N - 1){
			//cout << "2\n";
			if (C[i] == C[i - 1]){
				for (int j = 1; j <= K; j++)
					if (j != C[i - 1]){
						C[i] = j;
						break;
					}
			}
			
			
		} else {
			bool good = false;
			//cout << "3\n";
			if (C[i] == C[i - 1] || C[i] == C[i + 1]){
				for (int j = 1; j <= K; j++)
					if (j != C[i - 1] && j != C[i + 1]){
						good = true;
						//cout << i << "C prima " << " " << C[i] << " | dopo";
						C[i] = j;
						//cout << C[i] << "\n";
						break;
					}
				if (!good){
					C[i] = C[i + 1];
				}
			}
			
		}
	}
	
	//return C;
	
}

int main() {
	ifstream cin("input1.txt");
  	//ofstream cout("output.txt");

  int N, K;
  cin >> N >> K;

  vector<int> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }
  //for (int i = 0; i < N; i++) {
    //cout << C[i] << " ";
  //}
  //cout << "\n";
	
  riprogramma(N, K, C);

  for (int i = 0; i < N; i++) {
    cout << C[i] << " ";
  }
  cout << endl;

  return 0;
}
