#include <bits/stdc++.h>

using namespace std;

int main(){
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int N, V;
	
	cin >> N >> V;
	
	vector<int> prices(N), vo(V);
	
	for (int i = 0; i < N; i++){
		cin >> prices[i];
	}
	for (int i = 0; i < V; i++){
		cin >> vo[i];
	}
	
	sort(prices.begin(), prices.end());
	sort(vo.begin(), vo.end());
	
	int count = 0, num = 0;
	
	for (int i = 0; i < V && num < N; i++){
		if (prices[num] <= vo[i]){
			count++;
			num++;
		}
	}
	cout << count << "\n";
}
