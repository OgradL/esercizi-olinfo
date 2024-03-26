#include <iostream>
#include <vector>
using namespace std;

int main(){
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	
	int N;
	
	cin >> N;
	
	
	vector<long long> S(N), P(N);
	
	long long totalP = 0;
	long long totalS = 0;
	
	for (int i = 0; i < N; i++){
		cin >> S[i] >> P[i];
		totalS += S[i];
		totalP += P[i];
	}
	
	
	int idx = 0;
	long long miA = totalS, miB = totalP;
	
	//cout << totalS << " " << totalP << "\n";
	
	for (int i = 0; i < N; i++){
		totalS -= S[i];
		totalP -= P[i];
		//cout << totalS << " " << totalP << " --- " << miA << " " << miB << "\n";
		if (miA * totalP < miB * totalS){
			miA = totalS;
			miB = totalP;
			idx = i;
		}
		
		totalS += S[i];
		totalP += P[i];
	}
	
	cout << idx << "\n";
	
	return  0;
}
