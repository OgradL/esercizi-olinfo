#include <bits/stdc++.h>

using namespace std;
 

 
int main()
{
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
    int N;
    cin >> N;
    
    vector<int> v(N);
    
    for (int i = 0; i < N; i++){
    	cin >> v[i];
	}
	
	vector<int> panini(N);
	
	panini[0] = 1;
    
    int lastPeso = v[0];
    
    int answer = 1;
    
    for (int i = 1; i < N; i++){
    	
    	for (int j = i; j >= 0; j--){
			
			if (v[i] < v[j] && panini[i] < panini[j]){
				panini[i] = panini[j];
			}
			
		}
		panini[i]++;
		answer = max(answer, panini[i]);
	}
    
    
    
    
    cout << answer << "\n";
    
	return 0;
}
