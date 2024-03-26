#include <bits/stdc++.h>

using namespace std;

int sfangate(int N, vector<int> V){
	
	int sum = 0;
	
	for (int i = 0; i < N; i++){
		sum += V[i];
	}
	
//	cout << sum << "\n";
	int ans = 0;
	
	for (int i = 0; i < N && sum < 0; i++){
//		cout << i << " " << V[i] << "\n";
		sum -= V[i] * 2;
		ans = i;
	}
	
	return ans + 1;
}


int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
    int N;
	
	cin >> N;
    
    vector<int> V(N);
    
    for(int i = 0; i < N; i++)
        cin >> V[i];
    
    sort(V.begin(), V.end());
    
    cout << sfangate(N, V) << "\n";
    
    return 0;
}
